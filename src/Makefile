STD := c++17

all: core

clean:
	rm ../html/core/*

core:
	emcc -std=$(STD) -s WASM=1 -o ../html/core/index.html core.cpp
