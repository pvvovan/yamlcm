SRC = \
yaml/markup.cppm

GCM = $(addprefix gcm.cache/, $(subst /,.,$(SRC:.cppm=.gcm)))
vpath %.cppm $(sort $(dir $(SRC)))

.SECONDEXPANSION:
gcm.cache/%.gcm: $$(subst .,/,%).cppm
	g++ --std=c++26 --reflection -fmodules -x c++ -c $(subst .,/,$(notdir $*)).cppm \
		-Wall -Wextra -Wconversion -Wsign-conversion -Wpedantic \
		-fconcepts-diagnostics-depth=2
