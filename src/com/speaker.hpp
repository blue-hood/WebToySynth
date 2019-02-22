#pragma once
class Speaker;

#include <core/core.hpp>

class Speaker : public Component
{
public:
  Speaker();
  virtual map<string, int> getIn();
  virtual map<string, int> getOut();
  virtual deque<Component_p> onChangeTime(double dt);
};
