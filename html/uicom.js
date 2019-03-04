var UiInput = class extends UiComponent {
	constructor(com, uisk) {
		super(com, uisk);
		this._jqinput = $('<input style="width: 112px; text-align: inherit; " placeholder="(ex.) 440.0">');
	}

	initDom() {
		super.initDom();
		var column = $('<td colspan="2" style="text-align: center; "></td>');
		column.append(this._jqinput);
		this.jqobj.append($('<tr></tr>').append(column));

		this._jqinput.change(() => {
			this.com.value = this.value;
		});
	}

	set value(value) {
		this.com.value = value;
		this._jqinput.val(value);
	}
	get value() {
		return Number(this._jqinput.val());
	}

	export() {
		var ex = super.export();
		ex.value = this.value;
		return ex;
	}

	import(im) {
		var lut = super.import(im);
		this.value = im.value;
		return lut;
	}
};

var UiKeyboard = class extends UiComponent {
	constructor(com, uisk) {
		super(com, uisk);
		this._key = 0;

		$(window).keydown((e) => {
			this._key = e.keyCode;
			this.com.keyon(e.keyCode);
		});
		$(window).keyup((e) => {
			if (e.keyCode == this._key) this.com.keyoff();
		});
	}
};

var UiScope = class extends UiComponent {
	constructor(com, uisk) {
		super(com, uisk);
		this._canvas = document.createElement("Canvas");

		var labels = [];
		for (var i = 0; i < 256; i++) labels.push(i);

		var ctx = this._canvas.getContext('2d');
		this._chart = new Chart(ctx, {
			type: 'line',
			data: {
				labels: labels,
				datasets: [{
					data: this.com.data,
					fill: false,
					borderColor: "gray",
					borderWidth: 1,
					lineTension: 0,
					pointRadius: 0,
				}]
			},
			options: {
				responsive: false,
				legend: { display: false },
				animation: false,
				scales: {
					xAxes: [{
						display: false,
					}],
				},
			}
		});

		this._jqmodebtn = $('<button>Free Run</button>');
		this._jqtrig = $('<input value="0.0" style="width: 48px; ">');
		this._jqskip = $('<input type="number" value="1" style="width: 48px; " min="1">');
	}

	initDom() {
		super.initDom();
		var column = $('<td colspan="2" style="text-align: center; "></td>');
		column.append(this._jqmodebtn);
		column.append(" Trigger ");
		column.append(this._jqtrig);
		column.append(" Skip ");
		column.append(this._jqskip);
		column.append(this._canvas);
		this.jqobj.append($('<tr></tr>').append(column));

		this._timer = setInterval(() => {
			this._chart.update();
		}, 16);
		this._jqmodebtn.click((e) => {
			switch (this.mode) {
				case Scope.Mode.freerun:
					this.mode = Scope.Mode.rising;
					break;
				case Scope.Mode.rising:
					this.mode = Scope.Mode.falling;
					break;
				case Scope.Mode.falling:
					this.mode = Scope.Mode.freerun;
					break;
			}
		});
		this._jqtrig.change((e) => {
			this.trig = this.trig;
		});
		this._jqskip.change((e) => {
			this.skip = this.skip;
		});
	}

	get mode() {
		return this.com.mode;
	}
	set mode(value) {
		this.com.mode = value;
		switch (value) {
			case Scope.Mode.freerun:
				this._jqmodebtn.text("Free Run");
				break;
			case Scope.Mode.rising:
				this._jqmodebtn.text("Rising Edge");
				break;
			case Scope.Mode.falling:
				this._jqmodebtn.text("Falling Edge");
				break;
		}
	}

	get trig() {
		return Number(this._jqtrig.val());
	}
	set trig(value) {
		this.com.trig = value;
		this._jqtrig.val(value);
	}

	get skip() {
		return Number(this._jqskip.val());
	}
	set skip(value) {
		this.com.skip = value;
		this._jqskip.val(value);
	}

	export() {
		var ex = super.export();
		ex.mode = this.mode;
		ex.trig = this.trig;
		ex.skip = this.skip;
		return ex;
	}

	import(im) {
		var lut = super.import(im);
		this.mode = im.mode;
		this.trig = im.trig;
		this.skip = im.skip;
		return lut;
	}

	dispose() {
		clearInterval(this._timer);
		super.dispose();
	}
};

var UiMeter = class extends UiComponent {
	constructor(com, uisk) {
		super(com, uisk);
		this._jqdisplay = $('<input style="width: 112px; text-align: inherit; " disabled>');
	}

	initDom() {
		super.initDom();
		var column = $('<td colspan="2" style="text-align: center; "></td>');
		column.append(this._jqdisplay);
		this.jqobj.append($('<tr></tr>').append(column));

		this._timer = setInterval(() => {
			this._jqdisplay.val(this.com.val);
		}, 16);
	}

	dispose() {
		clearInterval(this._timer);
		super.dispose();
	}
};

var UiCustom = class extends UiComponent {
};
