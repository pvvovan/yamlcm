all:
	g++ -std=c++26 -fmodules -c -fmodule-only -fsearch-include-path bits/std.cc # Generate standard library as module
	g++ --std=c++26 -fmodules -x c++ \
	-fconcepts-diagnostics-depth=2 \
	-o demo.elf \
	yaml/markup.cppm \
	main.cpp
