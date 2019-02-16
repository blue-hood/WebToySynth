#include "component.hpp"

#include <stdexcept>

Component::Component() : loopcnt(0)
{
	/*
		this.ui_class = UiComponent;
    */
	uuid_generate(this->id);
}

vector<PortIn_p> Component::getIntIns()
{
	vector<PortIn_p> int_ins;

	for (PortIn_p in_ : this->ins)
	{
		if (in_->int_ != "")
		{
			int_ins.push_back(in_);
		}
	}
	return int_ins;
}

vector<PortOut_p> Component::getIntOuts()
{
	vector<PortOut_p> int_outs;

	for (PortOut_p out : this->outs)
	{
		if (out->int_ != "")
		{
			int_outs.push_back(out);
		}
	}
	return int_outs;
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

void Component::clearIn()
{
	this->ins.clear();
}

void Component::appendOut(PortOut_p out)
{
	this->outs.push_back(out);
}

void Component::removeOut(PortOut_p rm)
{
	this->outs.erase(remove_if(this->outs.begin(), this->outs.end(), [&](PortOut_p out) -> bool { return out == rm; }), this->outs.end());
}

void Component::clearOut()
{
	this->outs.clear();
}

void Component::initPort(int in_n, int out_n)
{
	this->clearIn();
	for (int i = 0; i < in_n; i++)
	{
		this->appendIn(PortIn_p(new PortIn()));
	}

	this->clearOut();
	for (int i = 0; i < out_n; i++)
	{
		this->appendOut(PortOut_p(new PortOut()));
	}
}

deque<Component_p> Component::update()
{
	vector<PortIn_p> chins;
	for (PortOut_p out : this->outs)
	{
		vector<PortIn_p> partins = out->update();
		chins.insert(chins.end(), partins.begin(), partins.end());
	}

	deque<Component_p> chcoms;
	for (PortIn_p in_ : chins)
	{
		chcoms.push_back(in_->com);
	}

	return chcoms;
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

deque<Component_p> Component::onChangeIn()
{
	if (++this->loopcnt >= 256)
	{
		throw runtime_error("An infinite loop was occured. \nPlease insert \"Buffer\" to prevent it. ");
	}
	return deque<Component_p>();
}

deque<Component_p> Component::onChangeTime(double dt)
{
	this->loopcnt = 0;
	return deque<Component_p>();
}

void Component::onSimEnd()
{
}

/*
var Component = class{

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


};

*/