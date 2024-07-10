# Directories
SRC_DIR := ./src
INCLUDE_DIR := ./include
BIN_DIR := ./bin
OBJ_DIR := ./obj
TESTS_DIR := ./tests
TEST_BIN_DIR := ./tests/bin

# Subdirectories
COMMON_DIR := common
GUI_DIR := gui
IMAGE_PROC_DIR := image_processing
NETWORK_DIR := network
SOLVER_DIR := solver

# Source Files
COMMON_SRC_FILES := $(wildcard $(SRC_DIR)/$(COMMON_DIR)/*.c)
GUI_SRC_FILES := $(wildcard $(SRC_DIR)/$(GUI_DIR)/*.c)
IMAGE_PROC_SRC_FILES := $(wildcard $(SRC_DIR)/$(IMAGE_PROC_DIR)/*.c)
NETWORK_SRC_FILES := $(wildcard $(SRC_DIR)/$(NETWORK_DIR)/*.c)
SOLVER_SRC_FILES := $(wildcard $(SRC_DIR)/$(SOLVER_DIR)/*.c)

# Object Files
COMMON_OBJ_FILES := $(patsubst $(SRC_DIR)/$(COMMON_DIR)/%.c, $(OBJ_DIR)/$(COMMON_DIR)/%.o, $(COMMON_SRC_FILES))
GUI_OBJ_FILES := $(patsubst $(SRC_DIR)/$(GUI_DIR)/%.c, $(OBJ_DIR)/$(GUI_DIR)/%.o, $(GUI_SRC_FILES))
IMAGE_PROC_OBJ_FILES := $(patsubst $(SRC_DIR)/$(IMAGE_PROC_DIR)/%.c, $(OBJ_DIR)/$(IMAGE_PROC_DIR)/%.o, $(IMAGE_PROC_SRC_FILES))
NETWORK_OBJ_FILES := $(patsubst $(SRC_DIR)/$(NETWORK_DIR)/%.c, $(OBJ_DIR)/$(NETWORK_DIR)/%.o, $(NETWORK_SRC_FILES))
SOLVER_OBJ_FILES := $(patsubst $(SRC_DIR)/$(SOLVER_DIR)/%.c, $(OBJ_DIR)/$(SOLVER_DIR)/%.o, $(SOLVER_SRC_FILES))

# Binaries
GUI_BIN := $(BIN_DIR)/gui
IMAGE_PROC_BIN := $(BIN_DIR)/image_processing
NETWORK_BIN := $(BIN_DIR)/network
SOLVER_BIN := $(BIN_DIR)/solver

# Test Files
SOLVER_TEST_FILES := $(wildcard $(TESTS_DIR)/$(SOLVER_DIR)/*.c)
SOLVER_TEST_BIN := $(patsubst $(TESTS_DIR)/$(SOLVER_DIR)/%.c, $(TEST_BIN_DIR)/$(SOLVER_DIR)/%, $(SOLVER_TEST_FILES))

# Compiler and flags
CSTD = c99
CC := gcc
CFLAGS := -std=$(CSTD) -Wall -Wextra # -Werror -Wpedantic
LIBS := 
TEST_LIBS := -lcriterion -lm

# Targets
.PHONY: all gui image_processing network solver format clean test

all: $(GUI_BIN) $(IMAGE_PROC_BIN) $(NETWORK_BIN) $(SOLVER_BIN)

# Build rules
$(GUI_BIN): $(COMMON_OBJ_FILES) $(GUI_OBJ_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $@ $(LIBS)

$(IMAGE_PROC_BIN): $(COMMON_OBJ_FILES) $(IMAGE_PROC_OBJ_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $@ $(LIBS)

$(NETWORK_BIN): $(COMMON_OBJ_FILES) $(NETWORK_OBJ_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $@ $(LIBS)

$(SOLVER_BIN): $(COMMON_OBJ_FILES) $(SOLVER_OBJ_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $^ -o $@ $(LIBS)

# Compile source files
$(OBJ_DIR)/$(COMMON_DIR)/%.o: $(SRC_DIR)/$(COMMON_DIR)/%.c | $(OBJ_DIR)/$(COMMON_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/$(GUI_DIR)/%.o: $(SRC_DIR)/$(GUI_DIR)/%.c | $(OBJ_DIR)/$(GUI_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/$(IMAGE_PROC_DIR)/%.o: $(SRC_DIR)/$(IMAGE_PROC_DIR)/%.c | $(OBJ_DIR)/$(IMAGE_PROC_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/$(NETWORK_DIR)/%.o: $(SRC_DIR)/$(NETWORK_DIR)/%.c | $(OBJ_DIR)/$(NETWORK_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/$(SOLVER_DIR)/%.o: $(SRC_DIR)/$(SOLVER_DIR)/%.c | $(OBJ_DIR)/$(SOLVER_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

# Create directories if they don't exist
$(OBJ_DIR)/$(COMMON_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(GUI_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(IMAGE_PROC_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(NETWORK_DIR):
	mkdir -p $@

$(OBJ_DIR)/$(SOLVER_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

$(TEST_BIN_DIR)/$(SOLVER_DIR):
	mkdir -p $@

# Test rules
$(TEST_BIN_DIR)/$(SOLVER_DIR)/%: $(TESTS_DIR)/$(SOLVER_DIR)/%.c $(COMMON_OBJ_FILES) | $(TEST_BIN_DIR)/$(SOLVER_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) $< $(COMMON_OBJ_FILES) -o $@ $(TEST_LIBS)

solver: $(SOLVER_BIN)

test: clean $(SOLVER_TEST_BIN)
	@for test in $(SOLVER_TEST_BIN); do ./$$test --verbose && echo; done

format:
	find . -iname '*.h' -o -iname '*.c' | xargs clang-format --style=file -i

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TEST_BIN_DIR)
