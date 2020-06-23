CF := -Wall -Isrc -Ithirdparty

CF_TEST := $(CF)

OBJ_DIR := build/src
SRC_DIR := src
TEST_OBJ_DIR := build/test
TEST_SRC_DIR := test

EXE := bin/sort
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEP := $(OBJ:.o=.d)

TEST_EXE := bin/test
TEST_SRC := $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJ := $(patsubst $(TEST_SRC_DIR)/%.c, $(TEST_OBJ_DIR)/%.o, $(TEST_SRC))
TEST_DEP := $(TEST_OBJ:.o=.d)

all: build $(OBJ_DIR) bin $(EXE) $(SRC)

build $(OBJ_DIR) $(TEST_OBJ_DIR) bin:
	mkdir $@

$(EXE): $(OBJ)
	gcc $^ -o $@ $(CF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $< -c -o $@ $(CF) -MMD -MF $(OBJ_DIR)/$*.d

test: all $(TEST_OBJ_DIR) $(TEST_EXE) $(TEST_SRC)

$(TEST_EXE): $(TEST_OBJ) $(patsubst build/src/main.o, ,$(OBJ))
	gcc $^ -o $@ $(CF_TEST)

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	gcc $< -c -o $@ $(CF_TEST) -MMD -MF $(TEST_OBJ_DIR)/$*.d

clean:
	rm -rf build/src/ build/test

.PHONY: all clean test