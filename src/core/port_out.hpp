#pragma once
class PortOut;

#include "port_in.hpp"

#include <string>
#include <vector>
#include <memory>
#include <uuid/uuid.h>
#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>

using namespace std;

typedef shared_ptr<PortIn> PortIn_p;

class PortOut
{
  double val;
  double latch;

  vector<string> exportTos();

public:
  string int_;
  vector<PortIn_p> tos;
  vector<string> to_ids;

  PortOut();
  double getVal();
  double setLatch(double value);
  void initVal();
  vector<PortIn_p> update();
  void disconnectAll();

  template <class Archive>
  void serialize(Archive &archive)
  {
    vector<string> tos = this->exportTos();
    archive(CEREAL_NVP(tos), cereal::make_nvp("int", int_));
  }
};
