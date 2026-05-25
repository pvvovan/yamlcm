all:
	g++ --std=c++26 -fmodules -x c++ \
	-fconcepts-diagnostics-depth=2 \
	-o demo.elf \
	yaml/markup.cppm \
	main.cpp
