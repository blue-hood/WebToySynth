STD := c++17

all: ../html/module.js
.PHONY: clean ../html/module.js

clean:
	rm ../html/module.js

../html/module.js:
	emcc -O3 -s WASM=1 -std=$(STD) -s NO_EXIT_RUNTIME=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -s DISABLE_EXCEPTION_CATCHING=0 \
		-o ../html/module.js module.cpp \
		core/core.cpp core/sketch.cpp core/component.cpp core/port_in.cpp core/port_out.cpp \
		com/speaker.cpp
