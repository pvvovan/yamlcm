all:
	g++ -std=c++26 -fmodules -freflection -c -fmodule-only -fsearch-include-path bits/std.cc # Generate standard library
	g++ --std=c++26 -freflection -fmodules -x c++ \
	-fconcepts-diagnostics-depth=2 \
	-o demo.elf \
	yaml/markup.cppm \
	main.cpp
