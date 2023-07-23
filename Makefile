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

study:
	@echo "Modules: " $$(basename $(TARGETS))
	@read module;
	@echo $$module;

studies: $(TARGETS)

.PHONY: clean
clean:
	rm -rf $(BUILD_PATH)

help:
	@echo "usage: $(MAKE) [tool] ..."
	@echo ""