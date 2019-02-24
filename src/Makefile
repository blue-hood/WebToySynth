OPTIONS := -s WASM=1 -s NO_EXIT_RUNTIME=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -s DISABLE_EXCEPTION_CATCHING=0 \
		-O3 -std=c++17 -Wno-exceptions \
		-I $(PWD) -I $(PWD)/cereal/include

all: ../html/module.js

PHONY: clean
clean:
	-rm ../html/module.js
	-rm core/core.o
	-rm com/*.o

../html/module.js: module.cpp core/core.o com/speaker.o com/input.o
	emcc $(OPTIONS) -o ../html/module.js module.cpp core/core.o com/*.o

core/core.o: core/*.?pp
	emcc $(OPTIONS) -o core/core.o core/core.cpp core/sketch.cpp core/component.cpp core/port_in.cpp core/port_out.cpp

com/speaker.o: com/speaker.?pp
	emcc $(OPTIONS) -o com/speaker.o com/speaker.cpp

com/input.o: com/input.?pp
	emcc $(OPTIONS) -o com/input.o com/input.cpp
