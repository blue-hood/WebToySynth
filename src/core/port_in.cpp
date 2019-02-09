#include "port_in.cpp"

/*
var PortIn = class{
	constructor(){
		this.com = null;
		this.src = null;
		this.int = "";
		this.id = UUID.generate();
		this.initVal();
	}

	initVal(){
		this.val = 0.0;
	}

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