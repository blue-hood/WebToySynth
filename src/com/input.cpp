#include "input.hpp"

map<string, int> Input::getIn()
{
	return map<string, int>();
}

map<string, int> Input::getOut()
{
	return map<string, int>{{"value", 0}};
}

double Input::setValue(double value)
{
	this->val = value;
	return value;
}

Input::Input() : Component()
{
	this->initPort(this->getIn().size(), this->getOut().size());
	this->com_name = string(__FUNCTION__);
	this->val = 0.0;
}

deque<Component_p> Input::onChangeTime(double dt)
{
	Component::onChangeTime(dt);
	this->outs[this->getOut()["value"]]->setLatch(this->val);
	return this->update();
}

void Input::exportExtends()
{
	this->extends = map<string, string>{{"value", to_string(this->val)}};
}

/*
var Input = class extends Component{

	constructor(){
		this.ui_class = UiInput;
	}

	import(im){
		var lut = super.import(im);
		this._val = im.value;
		return lut;
	}
};

*/