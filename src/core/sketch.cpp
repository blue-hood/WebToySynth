#include "sketch.hpp"

#include <algorithm>

void Sketch::appendCom(Component_p com)
{
    this->coms.push_back(com);
}

void Sketch::removeCom(Component_p rm)
{
    this->coms.erase(remove_if(this->coms.begin(), this->coms.end(), [&](Component_p com) -> bool { return com == rm; }), this->coms.end());
}

void Sketch::onSimStart() // 未確認
{
    for (Component_p com : this->coms)
    {
        com->onSimStart();
    }
}

/*
	onChangeTime(e){
		var chcoms = [];
		this.coms.forEach((com) => {
			Array.prototype.push.apply(chcoms, com.onChangeTime(e));
		});
		while(chcoms.length){
			chcoms = chcoms.filter((chcom, i) => { return i==chcoms.indexOf(chcom); });
			var com = chcoms.shift();
			Array.prototype.push.apply(chcoms, com.onChangeIn());
		}
	}

	onSimEnd(){
		this.coms.forEach((com) => {
			com.onSimEnd();
		});
	}

	upInterface(){
		this.int_ins = [];
		this.int_outs = [];
		this.coms.forEach((com) => {
			this.int_ins = this.int_ins.concat(com.int_ins);
			this.int_outs = this.int_outs.concat(com.int_outs);
		});
	}

	export(){
		var ex = {};
		ex.coms = [];
		this.coms.forEach((com) => {
			ex.coms.push(com.export());
		});
		return ex;
	}

	import(im){
		this.clearCom();
		var lut = [];
		im.coms.forEach((im) => {
			var com = eval("new "+im.type+"()");
			lut = lut.concat(com.import(im));
			this.appendCom(com);
		});

		var comlut = [];
		this.coms.forEach((com) => {
			com.connectById(lut);
			comlut.push({ id: com.id, inst: com });
		});
		return comlut;
	}
};
*/