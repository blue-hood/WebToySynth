#pragma once
class Sketch;

#include "component.hpp"
#include "port_in.hpp"
#include "port_out.hpp"

#include <vector>
#include <memory>
#include <cereal/cereal.hpp>

using namespace std;

typedef shared_ptr<Component> Component_p;
typedef shared_ptr<PortIn> PortIn_p;
typedef shared_ptr<PortOut> PortOut_p;

class Sketch
{
public:
  vector<Component_p> coms;
  vector<PortIn_p> int_ins;
  vector<PortOut_p> int_outs;

  void appendCom(Component_p com);
  void removeCom(Component_p com);
  void clearCom();
  void upInterface();
  void onSimStart();
  void onChangeTime(double dt);
  void onSimEnd();

  int val;
  template <class Archive>
  void serialize(Archive &archive)
  {
    archive(CEREAL_NVP(val));
  }
};
