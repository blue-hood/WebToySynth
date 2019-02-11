#pragma once
class Component;

#include "port_in.hpp"
#include "port_out.hpp"

#include <vector>
#include <memory>
#include <uuid/uuid.h>
using namespace std;

typedef shared_ptr<Component> Component_p;
typedef shared_ptr<PortIn> PortIn_p;
typedef shared_ptr<PortOut> PortOut_p;

class Component
{
  int loopCnt;

public:
  uuid_t id;
  vector<PortIn_p> ins;
  vector<PortOut_p> outs;

  Component();
  void onSimStart();
  void appendIn(PortIn_p in_);
  void removeIn(PortIn_p rm);
  void clearIn();
  void appendOut(PortOut_p out);
  void removeOut(PortOut_p rm);
  void clearOut();
  void initPort(int in_n, int out_n);
  vector<Component_p> update();
};
