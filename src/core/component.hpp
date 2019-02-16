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
  int loopcnt;

public:
  uuid_t id;
  vector<PortIn_p> ins;
  vector<PortOut_p> outs;

  Component();
  vector<PortIn_p> getIntIns();
  vector<PortOut_p> getIntOuts();
  void appendIn(PortIn_p in_);
  void removeIn(PortIn_p rm);
  void clearIn();
  void appendOut(PortOut_p out);
  void removeOut(PortOut_p rm);
  void clearOut();
  void initPort(int in_n, int out_n);
  vector<Component_p> update();
  void onSimStart();
  vector<Component_p> onChangeIn();
  vector<Component_p> onChangeTime();
  void onSimEnd();
};
