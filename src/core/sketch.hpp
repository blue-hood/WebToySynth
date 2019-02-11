#pragma once
class Sketch;

#include "component.hpp"

#include <vector>
#include <memory>
using namespace std;

typedef shared_ptr<Component> Component_p;

class Sketch
{
public:
  vector<Component_p> coms;
  vector<int> intIns;
  vector<int> intOuts;

  void appendCom(Component_p com);
  void removeCom(Component_p com);
  void clearCom();
  void onSimStart();
};
