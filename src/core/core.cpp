#include "sketch.hpp"

#include <iostream>

using namespace std;
//var g_spouts = [];

int main()
{
	Sketch sketch;
	Component_p com1(new Component());
	Component_p com2(new Component());
	Component_p com3(new Component());

	sketch.appendCom(com1);
	sketch.appendCom(com2);
	sketch.appendCom(com3);

	for (Component_p com : sketch.coms)
	{
		printf("%p\n", com.get());
	}

	return 0;
}

/*






*/
