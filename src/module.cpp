#include "core/core.hpp"
#include "com/com.hpp"

#include <stdio.h>
#include <emscripten/emscripten.h>

using namespace std;

extern "C"
{
    int main(int argc, char **argv)
    {
        printf("main\n");
        return 0;
    }

    EMSCRIPTEN_KEEPALIVE void test()
    {
        printf("test\n");
    }
}
