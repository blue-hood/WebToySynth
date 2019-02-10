#include "component.hpp"

Component::Component() : loopCnt(0)
{
	/*
		this.ui_class = UiComponent;
		this.id = UUID.generate();
    */
}

void Component::onSimStart()
{
	/*this.ins.forEach((in_) = > {
		in_.initVal();
	});
	this.outs.forEach((out) = > {
		out.initVal();
	});*/
	for (PortIn_p in_ : this->ins)
	{
		in_->initVal();
	}
	for (PortOut_p out : this->outs)
	{
		out->initVal();
	}
}

/*
var Component = class{

	appendIn(in_){
		this.ins.push(in_);
		in_.com = this;
	}
	removeIn(rm){
		this.ins = this.ins.filter((in_) => { return in_!=rm; });
		rm.com = null;
	}
	clearIn(){
		while(this.ins.length) this.removeIn(this.ins[0]);
	}

	appendOut(out){
		this.outs.push(out);
	}
	removeOut(rm){
		this.outs = this.outs.filter((out) => { return out!=rm; });
	}
	clearOut(){
		while(this.outs.length) this.removeOut(this.outs[0]);
	}

	initPort(in_n, out_n){
		this.clearIn();
		for(var i = 0; i<in_n; i++){
			this.appendIn(new PortIn());
		}

		this.clearOut();
		for(var i = 0; i<out_n; i++){
			this.appendOut(new PortOut());
		}
	}

	update(){
		var chins = [];
		this.outs.forEach((out) => {
			Array.prototype.push.apply(chins, out.update())
		});

		var chcoms = [];
		chins.forEach((in_) => {
			chcoms.push(in_.com);
		});
		return chcoms;
	}

	get int_ins(){
		var int_ins = [];

		this.ins.forEach((in_) => {
			if (in_.int!="") int_ins.push(in_);
		});
		return int_ins;
	}

	get int_outs(){
		var int_outs = [];

		this.outs.forEach((out) => {
			if (out.int!="") int_outs.push(out);
		});
		return int_outs;
	}

	export(){
		var ex = {};
		ex.type = this.constructor.name;
		ex.id = this.id;

		ex.ins = [];
		this.ins.forEach((in_) => {
			ex.ins.push(in_.export());
		});

		ex.outs = [];
		this.outs.forEach((out) => {
			ex.outs.push(out.export());
		});

		return ex;
	}

	import(im){
		var lut = [];

		this.id = im.id;
		this.clearIn();
		im.ins.forEach((im) => {
			var in_ = new PortIn();
			lut.push(in_.import(im));
			this.appendIn(in_);
		});

		this.clearOut();
		im.outs.forEach((im) => {
			var out = new PortOut();
			out.import(im);
			this.appendOut(out);
		});

		return lut;
	}

	connectById(lut){
		this.outs.forEach((out) => {
			out.connectById(lut);
		});
	}


	onChangeIn(){
		if (++this._loopcnt>=256){
			throw "An infinite loop was occured. \nPlease insert \"Buffer\" to prevent it. ";
		}
		return [];
	}
	onChangeTime(){
		this._loopcnt = 0;
		return [];
	}
	onSimEnd(){}
};

*/