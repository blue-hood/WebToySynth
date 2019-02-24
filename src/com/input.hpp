#pragma once
class Input;

#include <core/core.hpp>

class Input : public Component
{
  double val;

public:
  Input();
  virtual map<string, int> getIn();
  virtual map<string, int> getOut();
  double setValue(double value);
  virtual deque<Component_p> onChangeTime(double dt);
  virtual void exportExtends();
};
