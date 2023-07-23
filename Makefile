XLEN				:= 64
STUDY				:= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TARGETS			:= $(wildcard src/*)
BUILD_PATH	:= $(PWD)/bin

TOOLCHAIN_PREFIX := 
CC					:= $(TOOLCHAIN_PREFIX)gcc

.PHONY: all prerequisites
all: studies

prerequisites:
	mkdir -p $(BUILD_PATH)

$(CC): prerequisites

$(TARGETS): $(CC)
	$(CC) $@/main.c -o bin/$$(basename $@)

modules:
	@echo " Modules available:"
	@echo "  " $$(basename $(TARGETS));

study: $(CC)
	@echo "Modules: " $$(basename $(TARGETS));
	@read -p "> " module; \
	$(CC) src/$$module/main.c -o bin/$$module

studies: $(TARGETS)

.PHONY: clean
clean:
	rm -rf $(BUILD_PATH)

help:
	@echo "usage: $(MAKE) [tool] ..."
	@echo ""
	@echo "Build all the studies using either of the following:"
	@echo "    make"
	@echo "    make all"
	@echo "    make studies"
	@echo ""
	@echo "List available modules to build:"
	@echo "    make modules"
	@echo ""
	@echo "Build specific study modules only:"
	@echo "    make study"
	@echo ""
	@echo "Clean built binaries"
	@echo "    make clean"
	@echo ""