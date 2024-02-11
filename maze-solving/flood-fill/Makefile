XLEN        := 64
STUDY       := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TARGETS     := $(wildcard src/*)
BUILD_PATH  := $(PWD)/bin

TOOLCHAIN_PREFIX := 
CC               := $(TOOLCHAIN_PREFIX)gcc

all: studies

prerequisites:
	mkdir -p $(BUILD_PATH)

$(CC): prerequisites

$(TARGETS): $(CC)
	$(CC) $@/main.c -o bin/$$(basename $@)

module: $(CC)
	@test -n "$(MODULE)" || (echo 'MODULE must be set, Ex: make study MODULE=sort\rModules: ' $$(basename $(TARGETS)) && exit 1)
	$(CC) src/$(MODULE)/main.c -o bin/$(MODULE)

study: module

studies: $(TARGETS)

.PHONY: all study clean help

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
	@echo "    make study MODULE=??"
	@echo "    Modules available: " $$(basename $(TARGETS))
	@echo ""
	@echo "Clean built binaries"
	@echo "    make clean"
	@echo ""