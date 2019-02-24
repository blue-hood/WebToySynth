#pragma once
class PortIn;

#include "component.hpp"
#include "port_out.hpp"

#include <string>
#include <memory>
#include <uuid/uuid.h>
#include <cereal/cereal.hpp>

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

  template <class Archive>
  void serialize(Archive &archive)
  {
    archive(CEREAL_NVP(id), cereal::make_nvp("int", int_));
  }
};
