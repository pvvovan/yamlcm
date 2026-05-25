all:
	g++ -std=c++26 -fmodules --reflection -c -fmodule-only -fsearch-include-path bits/std.cc # Generate standard library
	g++ --std=c++26 --reflection -fmodules -x c++ \
		-Wall -Wextra -Wconversion -Wsign-conversion -Wpedantic \
		-fconcepts-diagnostics-depth=2 \
		-o demo.elf \
		yaml/markup.cppm \
		main.cpp
