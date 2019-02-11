#include "port_out.hpp"

PortOut::PortOut()
{
	/*
		this.to_ids = [];
		this.int = "";
*/
	this->initVal();
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

/*
var PortOut = class{

	get val(){
		return this._val;
	}

	set latch(value){
		this._latch = value;
	}


	disconnectAll(){
		while(this.tos.length) this.tos[0].disconnect(this);
	}

	export(){
		var tos = [];
		this.tos.forEach((to) => {
			tos.push(to.id);
		});
		return {tos: tos, int: this.int, };
	}

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