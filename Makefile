XLEN        := 64
STUDY       := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TARGETS     := $(patsubst %/src,%,$(wildcard **/src))
BUILD_PATH  := $(PWD)/bin

TOOLCHAIN_PREFIX := 
CC               := $(TOOLCHAIN_PREFIX)gcc

all: $(TARGETS)

prerequisites:
	mkdir -p $(BUILD_PATH)

$(CC): prerequisites

$(TARGETS): $(CC)
	$(CC) $@/src/main.c -g -o bin/$$(basename $@)

test: all

.PHONY: all test clean help

clean:
	rm -rf $(BUILD_PATH)

help:
	@echo "usage: $(MAKE) [target] ..."
	@echo ""
	@echo "Build all the studies using either of the following:"
	@echo "    make"
	@echo "    make all"
	@echo ""
	@echo "Build specific study modules only:"
	@echo "    make [$(TARGETS)]"
	@echo ""
	@echo "Clean built binaries"
	@echo "    make clean"
