#include "port_out.hpp"

PortOut::PortOut() : int_("")
{
	this->initVal();
}

double PortOut::getVal()
{
	return this->val;
}

double PortOut::setLatch(double value)
{
	return this->latch = value;
}

void PortOut::initVal()
{
	this->latch = 0.0;
	this->val = 0.0;
}

vector<PortIn_p> PortOut::update()
{
	if (this->val != this->latch)
	{
		this->val = this->latch;

		for (PortIn_p to : this->tos)
		{
			to->val = this->val;
		}

		return this->tos;
	}
	else
	{
		return vector<PortIn_p>();
	}
}

void PortOut::disconnectAll()
{
	while (!this->tos.empty())
	{
		this->tos[0]->disconnect();
	}
}

/*
var PortOut = class{


	import(im){
		this.to_ids = im.tos;
		this.int = im.int;
	}

	connectById(lut){
		this.disconnectAll();
		this.to_ids.forEach((to_id) => {
			for(var i = 0; i<lut.length; i++){
				if (to_id==lut[i].id){
					lut[i].inst.connect(this);
					break;
				}
			}
		});
	}
};

*/