#include "port_in.hpp"

typedef shared_ptr<PortIn> PortIn_p;

PortIn::PortIn() : com(Component_p(nullptr)), src(PortOut_p(nullptr))
{
	/*
	this.int = "";
	this.id = UUID.generate();
	this.initVal();*/
}

void PortIn::initVal()
{
	this->val = 0.0;
}

void PortIn::connect(PortOut_p src)
{
	this->disconnect();
	this->src = src;
	src->tos.push_back(PortIn_p(this));
}

void PortIn::disconnect()
{
	if (this->src)
	{
		PortIn_p dis = PortIn_p(this);
		this->src->tos.erase(remove_if(this->src->tos.begin(), this->src->tos.end(), [&](PortIn_p to) -> bool { return to == dis; }), this->src->tos.end());
		this->src = PortOut_p(nullptr);
	}
}

/*
var PortIn = class{


	export(){
		return {id: this.id, int: this.int, };
	}

	import(im){
		this.id = im.id;
		this.int = im.int;
		return { id: this.id, inst: this };
	}
};

*/