CC=g++
CFLAGS= -std=c++11 -c -Wall
LDFLAGS=

NAME=InventoryMIS

SRC_DIR=./src
TEST_DIR=./test/src
OBJ_DIR=./include
BIN_DIR=./bin

SRC=$(wildcard $(SRC_DIR)/*.cpp)
TEST_SRC=$(wildcard $(TEST_DIR)/*.cpp)
OBJ=$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJ=$(TEST_SRC:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXECUTABLE=$(BIN_DIR)/$(NAME)
TEST_EXECUTABLE=$(BIN_DIR)/test

# Path to the Doctest header directory
DOCTEST_INC_DIR := ../doctest

build: $(SRC_DIR) $(BIN_DIR) $(EXECUTABLE)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(SRC_DIR):
	mkdir -p $(SRC_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(DOCTEST_INC_DIR) $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(DOCTEST_INC_DIR) $< -o $@

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

$(BIN_DIR)/%Test: $(OBJ_DIR)/%.o $(OBJ)
	$(CC) -o $@ $^ -I$(DOCTEST_INC_DIR) -lpthread

test: $(TEST_OBJ) $(TEST_SRC:%.cpp=$(BIN_DIR)/%Test)
	@for test in $(TEST_SRC:%.cpp=%); do \
		echo "Running test: $$test"; \
		./bin/$$test; \
	done

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

.PHONY: build clean test
