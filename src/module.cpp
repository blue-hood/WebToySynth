#include <core/core.hpp>
#include <com/com.hpp>

#include <exception>
#include <emscripten/emscripten.h>
#include <sstream>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

using namespace std;

class Test
{
    int intVal = 0;
    double rename = 1.5;

  public:
    template <class Archive>
    void serialize(Archive &archive)
    {
        archive(CEREAL_NVP(intVal), cereal::make_nvp("doubleVal", rename));
    }
};

extern "C"
{
    int main(int argc, char **argv)
    {
        Test test;
        stringstream stream;
        {
            cereal::JSONOutputArchive archive(stream);
            archive(CEREAL_NVP(test));
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
}
