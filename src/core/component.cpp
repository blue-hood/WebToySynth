#include "component.hpp"

Component::Component() : loopCnt(0)
{
	/*
		this.ui_class = UiComponent;
    */
	uuid_generate(this->id);
}

void Component::onSimStart()
{
	for (PortIn_p in_ : this->ins)
	{
		in_->initVal();
	}
	for (PortOut_p out : this->outs)
	{
		out->initVal();
	}
}

void Component::appendIn(PortIn_p in_)
{
	this->ins.push_back(in_);
	in_->com = Component_p(this);
}

void Component::removeIn(PortIn_p rm)
{
	this->ins.erase(remove_if(this->ins.begin(), this->ins.end(), [&](PortIn_p in_) -> bool { return in_ == rm; }), this->ins.end());
	rm->com = Component_p(nullptr);
}

/*
var Component = class{

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