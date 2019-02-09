#include "sketch.hpp"

#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

void Sketch::appendCom(Component_p com)
{
    this->coms.push_back(com);
}

void Sketch::removeCom(Component_p rm)
{
    this->coms.erase(remove_if(this->coms.begin(), this->coms.end(), [&](Component_p com) -> bool { return com == rm; }), this->coms.end());
}

void Sketch::onSimStart() // 未確認
{
    for (Component_p com : this->coms)
    {
        com->onSimStart();
    }
}
