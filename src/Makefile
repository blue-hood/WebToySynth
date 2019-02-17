STD := c++17

all: core

clean:
	rm ../html/core/*

core: core/*
	emcc -std=$(STD) -s WASM=1 -o ../html/core/index.html \
		core/core.cpp core/sketch.cpp core/component.cpp core/port_in.cpp core/port_out.cpp \
		com/speaker.cpp
