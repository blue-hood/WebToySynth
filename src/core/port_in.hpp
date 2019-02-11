#pragma once
class PortIn;

#include "component.hpp"

#include <memory>
using namespace std;

typedef shared_ptr<Component> Component_p;

class PortIn
{
public:
  double val;
  Component_p com;

  PortIn();
  void initVal();
};
