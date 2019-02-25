#pragma once
class Sine;

#include <core/core.hpp>

class Sine : public Component
{
  double phase;

public:
  Sine();
  virtual map<string, int> getIn();
  virtual map<string, int> getOut();
  virtual deque<Component_p> onChangeTime(double dt);
};
