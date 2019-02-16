#pragma once
class PortOut;

#include "port_in.hpp"

#include <string>
#include <vector>
#include <memory>
using namespace std;

typedef shared_ptr<PortIn> PortIn_p;

class PortOut
{
  double val;
  double latch;

public:
  string int_;
  vector<PortIn_p> tos;
  vector<string> to_ids;

  PortOut();
  double getVal();
  void setLatch(double value);
  void initVal();
  vector<PortIn_p> update();
  void disconnectAll();
};
