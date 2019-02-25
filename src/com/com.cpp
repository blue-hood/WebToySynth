#include "com.hpp"

#include <vector>
#include <string>

using namespace std;

static vector<string> g_com_names;
static vector<Component *(*)(string)> g_new_com_funcs;

#define registerComponent(Com)                                         \
    do                                                                 \
    {                                                                  \
        Com com;                                                       \
                                                                       \
        g_com_names.push_back(#Com);                                   \
        g_new_com_funcs.push_back([](string com_name) -> Component * { \
            return com_name == string(#Com) ? new Com : nullptr;       \
        });                                                            \
    } while (0)

Component *newCom(string com_name)
{
    for (Component *(*func)(string) : g_new_com_funcs)
    {
        Component *com = func(com_name);

        if (com != nullptr)
        {
            return com;
        }
    }

    return nullptr;
}

void initCom()
{
    g_com_names.clear();
    g_new_com_funcs.clear();

    registerComponent(Speaker);
    registerComponent(Input);
    registerComponent(Sine);
}
