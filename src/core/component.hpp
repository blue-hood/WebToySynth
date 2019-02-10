#pragma once
#include "port_in.hpp"
#include "port_out.hpp"

#include <vector>
#include <memory>
using namespace std;

typedef shared_ptr<PortIn> PortIn_p;
typedef shared_ptr<PortOut> PortOut_p;

class Component
{
  int loopCnt;

public:
  vector<PortIn_p> ins;
  vector<PortOut_p> outs;

  Component();
  void onSimStart();
};
