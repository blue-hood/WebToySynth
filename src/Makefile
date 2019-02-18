STD := c++17

all: ../html/core.html
.PHONY: clean ../html/core.html

clean:
	rm ../html/core.html

../html/core.html:
	emcc -std=$(STD) -s WASM=1 -o ../html/core.html index.cpp \
		core/core.cpp core/sketch.cpp core/component.cpp core/port_in.cpp core/port_out.cpp \
		com/speaker.cpp
