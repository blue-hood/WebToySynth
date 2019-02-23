#include <core/core.hpp>
#include <com/com.hpp>

#include <exception>
#include <emscripten/emscripten.h>
#include <sstream>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

using namespace std;

extern "C"
{
    int main(int argc, char **argv);
    EMSCRIPTEN_KEEPALIVE void onSimStart();
    EMSCRIPTEN_KEEPALIVE int onAudioProcess(double dt, float *buffer, int length);
    EMSCRIPTEN_KEEPALIVE void onSimEnd();
    EMSCRIPTEN_KEEPALIVE void export_();
}

int main(int argc, char **argv)
{
    stringstream stream;
    {
        cereal::JSONOutputArchive archive(stream);
        archive(cereal::make_nvp("sketch", g_sketch));
    }
    cout << stream.str() << endl;
    return 0;
}

EMSCRIPTEN_KEEPALIVE void onSimStart()
{
    g_sketch.onSimStart();
}

EMSCRIPTEN_KEEPALIVE int onAudioProcess(double dt, float *buffer, int length)
{
    // スキップフレームは未実装。
    try
    {
        for (int i = 0; i < length; i++)
        {
            g_spout = 0.0;
            g_spcount = 0;
            g_sketch.onChangeTime(dt);

            buffer[i] = g_spout / g_spcount;
        }
    }
    catch (exception &e)
    {
        return 1;
    }

    return 0;
}

EMSCRIPTEN_KEEPALIVE void onSimEnd()
{
    g_sketch.onSimEnd();
}

EMSCRIPTEN_KEEPALIVE void export_()
{
}
