#pragma once
class PortIn;

#include "component.hpp"
#include "port_out.hpp"

#include <memory>
using namespace std;

typedef shared_ptr<Component> Component_p;
typedef shared_ptr<PortOut> PortOut_p;

class PortIn
{
public:
  double val;
  Component_p com;
  PortOut_p src;

  PortIn();
  void initVal();
  void connect(PortOut_p src);
  void disconnect();
};
