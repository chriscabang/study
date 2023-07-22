XLEN				:= 64
STUDY				:= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
SOURCE_PATH	:= $(PWD)/src
BUILD_PATH	:= $(PWD)/bin

TOOLCHAIN_PREFIX := 
CC					:= $(TOOLCHAIN_PREFIX)gcc

.PHONY: all prerequisites
all: $(CC) \
	array-manipulation \
	binary-gap \
	binary-search-tree \
	bit-manipulation \
	fibonacci \
	fizzbuzz \
	flood-fill \
	pascals-triangle \
	product-code \
	root-mean-square-error \
	sort

prerequisites:
	mkdir -p $(BUILD_PATH)

$(CC): prerequisites

$(STUDY)/array-manipulation: $(CC)
	$(CC) $(SOURCE_PATH)/array-manipulation/main.c -o $(BUILD_PATH)/array-manipulation

$(STUDY)/binary-gap: $(CC)
	$(CC) $(SOURCE_PATH)/binary-gap/main.c -o $(BUILD_PATH)/binary-gap

$(STUDY)/binary-search-tree: $(CC)
	$(CC) $(SOURCE_PATH)/binary-search-tree/main.c -o $(BUILD_PATH)/binary-search-tree

$(STUDY)/bit-manipulation: $(CC)
	$(CC) $(SOURCE_PATH)/bit-manipulation/main.c -o $(BUILD_PATH)/bit-manipulation

$(STUDY)/fibonacci: $(CC)
	$(CC) $(SOURCE_PATH)/fibonacci/main.c -o $(BUILD_PATH)/fibonacci

$(STUDY)/fizzbuzz: $(CC)
	$(CC) $(SOURCE_PATH)/fizzbuzz/main.c -o $(BUILD_PATH)/fizzbuzz

$(STUDY)/flood-fill: $(CC)
	$(CC) $(SOURCE_PATH)/flood-fill/main.c -o $(BUILD_PATH)/flood-fill

$(STUDY)/pascals-triangle: $(CC)
	$(CC) $(SOURCE_PATH)/pascals-triangle/main.c -o $(BUILD_PATH)/pascals-triangle

$(STUDY)/product-code: $(CC)
	$(CC) $(SOURCE_PATH)/product-code/main.c -o $(BUILD_PATH)/product-code

$(STUDY)/root-mean-square-error: $(CC)
	$(CC) $(SOURCE_PATH)/root-mean-square-error/main.c -o $(BUILD_PATH)/root-mean-square-error

$(STUDY)/bubble-sort: $(CC)
	$(CC) $(SOURCE_PATH)/sort/bubble-sort/main.c -o $(BUILD_PATH)/bubble-sort

$(STUDY)/quick-sort: $(CC)
	$(CC) $(SOURCE_PATH)/sort/quick-sort/main.c -o $(BUILD_PATH)/quick-sort

$(STUDY)/sort: $(STUDY)/bubble-sort $(STUDY)/quick-sort

gcc: $(CC)
array-manipulation: $(STUDY)/array-manipulation
binary-gap: $(STUDY)/binary-gap
binary-search-tree: $(STUDY)/binary-search-tree
bit-manipulation: $(STUDY)/bit-manipulation
fibonacci: $(STUDY)/fibonacci
fizzbuzz: $(STUDY)/fizzbuzz
flood-fill: $(STUDY)/flood-fill
pascals-triangle: $(STUDY)/pascals-triangle
product-code: $(STUDY)/product-code
root-mean-square-error: $(STUDY)/root-mean-square-error
sort: $(STUDY)/sort
bubble-sort: $(STUDY)/bubble-sort
quick-sort: $(STUDY)/quick-sort

.PHONY: clean
clean:
	rm -rf $(BUILD_PATH)

help:
	@echo "usage: $(MAKE) [tool] ..."
	@echo ""