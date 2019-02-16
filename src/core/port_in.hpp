#pragma once
class PortIn;

#include "component.hpp"
#include "port_out.hpp"

#include <string>
#include <memory>
#include <uuid/uuid.h>
using namespace std;

typedef shared_ptr<Component> Component_p;
typedef shared_ptr<PortOut> PortOut_p;

class PortIn
{
public:
  uuid_t id;
  double val;
  Component_p com;
  PortOut_p src;
  string int_;

  PortIn();
  void initVal();
  void connect(PortOut_p src);
  void disconnect();
};
