#pragma once
class Component;

#include "port_in.hpp"
#include "port_out.hpp"

#include <vector>
#include <deque>
#include <map>
#include <memory>
#include <string>
#include <uuid/uuid.h>
#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/memory.hpp>

using namespace std;

typedef shared_ptr<Component> Component_p;
typedef shared_ptr<PortIn> PortIn_p;
typedef shared_ptr<PortOut> PortOut_p;

class Component
{
  int loopcnt;

protected:
  deque<Component_p> update();
  void appendIn(PortIn_p in_);
  void removeIn(PortIn_p rm);
  void clearIn();
  void appendOut(PortOut_p out);
  void removeOut(PortOut_p rm);
  void clearOut();

public:
  uuid_t id;
  vector<PortIn_p> ins;
  vector<PortOut_p> outs;

  Component();
  vector<PortIn_p> getIntIns();
  vector<PortOut_p> getIntOuts();
  virtual map<string, int> getIn();
  virtual map<string, int> getOut();
  void initPort(int in_n, int out_n);
  void onSimStart();
  deque<Component_p> onChangeIn();
  virtual deque<Component_p> onChangeTime(double dt);
  void onSimEnd();

  template <class Archive>
  void serialize(Archive &archive)
  {
    archive(cereal::make_nvp("type", "test"), CEREAL_NVP(id), CEREAL_NVP(ins), CEREAL_NVP(outs));
  }
};
