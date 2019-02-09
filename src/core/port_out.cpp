#include "port_out.hpp"

/*
var PortOut = class{
	constructor(){
		this.tos = [];
		this.to_ids = [];
		this.int = "";
		this.initVal();
	}

	initVal(){
		this._latch = 0.0;
		this._val = 0.0;
	}

	get val(){
		return this._val;
	}

	set latch(value){
		this._latch = value;
	}

	update(){
		if (this._val != this._latch){
			this._val = this._latch;

			this.tos.forEach((to) => {
				to.val = this._val;
			});

			return this.tos;
		}else{
			return [];
		}
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