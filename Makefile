include yaml/yaml.mak

gcm.cache:
	g++ -std=c++26 -fmodules --reflection -c -fmodule-only -fsearch-include-path bits/std.cc # Generate standard library

${GCM}: | gcm.cache

demo.elf: main.cpp ${GCM}
	g++ --std=c++26 --reflection -fmodules -x c++ \
		-Wall -Wextra -Wconversion -Wsign-conversion -Wpedantic \
		-fconcepts-diagnostics-depth=2 \
		$< -o $@

.PHONY: clean
clean:
	-rm -r ./gcm.cache/ ./demo.elf

.DEFAULT_GOAL := demo.elf
