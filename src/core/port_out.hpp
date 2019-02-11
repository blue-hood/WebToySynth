#pragma once
class PortOut;

#include "port_in.hpp"

#include <vector>
#include <memory>
using namespace std;

typedef shared_ptr<PortIn> PortIn_p;

class PortOut
{
  double val;
  double latch;

public:
  vector<PortIn_p> tos;

  PortOut();
  void initVal();
  vector<PortIn_p> update();
};
