#include <core/core.hpp>
#include <com/com.hpp>

#include <exception>
#include <sstream>
#include <iostream>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include <emscripten/emscripten.h>

using namespace std;

extern "C"
{
    int main(int argc, char **argv);
    EMSCRIPTEN_KEEPALIVE void onSimStart();
    EMSCRIPTEN_KEEPALIVE float *onAudioProcess(double dt);
    EMSCRIPTEN_KEEPALIVE void onSimEnd();
    EMSCRIPTEN_KEEPALIVE const char *export_();
}

int main(int argc, char **argv)
{
    initCom();

    Component_p speaker1 = Component_p(newCom("Speaker"));
    g_sketch.appendCom(speaker1);
    Component_p input1 = Component_p(newCom("Input"));
    g_sketch.appendCom(input1);
    Component_p sine1 = Component_p(newCom("Sine"));
    g_sketch.appendCom(sine1);

    sine1->ins[sine1->getIn()["freq"]]->connect(input1->outs[input1->getOut()["value"]]);
    speaker1->ins[speaker1->getIn()["sound"]]->connect(sine1->outs[sine1->getOut()["sine"]]);
    for (int i = 1; i < 50 /*speakerの数*/; i++)
    {
        Component_p speaker2 = Component_p(newCom("Speaker"));
        g_sketch.appendCom(speaker2);

        speaker2->ins[speaker2->getIn()["sound"]]->connect(speaker1->outs[speaker1->getOut()["thru"]]);

        speaker1 = speaker2;
    }

    static_cast<Input *>(input1.get())->setValue(440.0);

    return 0;
}

EMSCRIPTEN_KEEPALIVE void onSimStart()
{
    g_sketch.onSimStart();
}

EMSCRIPTEN_KEEPALIVE float *onAudioProcess(double dt)
{
    // スキップフレームは未実装。
    try
    {
        for (int i = 0; i < G_BUFFER_SIZE; i++)
        {
            g_spout = 0.0;
            g_spcount = 0;
            g_sketch.onChangeTime(dt);
            g_buffer[i] = g_spcount ? g_spout / g_spcount : 0.0f;
        }
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
        return NULL;
    }

    return g_buffer;
}

EMSCRIPTEN_KEEPALIVE void onSimEnd()
{
    g_sketch.onSimEnd();
}

EMSCRIPTEN_KEEPALIVE const char *export_()
{
    g_sketch.exportExtends();

    stringstream stream;
    {
        cereal::JSONOutputArchive archive(stream);
        archive(cereal::make_nvp("sketch", g_sketch));
    }

    return stream.str().c_str();
}
