#include "core/core.hpp"
#include "com/com.hpp"

#include <iostream>
#include <emscripten/emscripten.h>

using namespace std;

int main(int argc, char **argv)
{
    Sketch sketch;

    sketch.appendCom(Component_p(new Speaker()));

    return 0;
}

void EMSCRIPTEN_KEEPALIVE test()
{
}
