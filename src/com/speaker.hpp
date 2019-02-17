#pragma once
class Speaker;

#include "../core/component.hpp"

class Speaker : Component
{
  public:
    Speaker();
    virtual vector<string> getIn();
    virtual vector<string> getOut();
    virtual deque<Component_p> onChangeTime(double dt);
};
