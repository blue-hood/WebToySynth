#include "port_in.hpp"

PortIn::PortIn() : com(Component_p(nullptr))
{
	/*
	this.src = null;
	this.int = "";
	this.id = UUID.generate();
	this.initVal();*/
}

void PortIn::initVal()
{
	this->val = 0.0;
}
/*
var PortIn = class{
	connect(src){
		this.disconnect();
		this.src = src;
		src.tos.push(this);
	}

	disconnect(){
		if (this.src){
			var dis = this;
			this.src.tos = this.src.tos.filter((to) => { return to!=dis; });
			this.src = null;
		}
	}

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