CC = clang

# Common compilation options
C_OPTS = $(MAC_OPTS) -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src

# Source files
SRC = src/lib.c src/main.c
TEST_SRC = src/lib.c test/test.c

# Directories
DIST_DIR = dist
HTML_DIR = $(DIST_DIR)/html

# Executables
MAIN_BIN = $(DIST_DIR)/main.bin
TEST_BIN = $(DIST_DIR)/test.bin

# Clean task
clean:
	rm -rf $(DIST_DIR)

# Preparation task
prep:
	mkdir -p $(HTML_DIR)

# Format check task
format:
	clang-format --verbose -dry-run --Werror src/*

# Compilation task
compile: $(MAIN_BIN) $(TEST_BIN)

# Main binary target
$(MAIN_BIN): $(SRC)
	$(CC) $(C_OPTS) $^ -o $@

# Test binary target
$(TEST_BIN): $(TEST_SRC)
	$(CC) $(C_OPTS) $^ -fprofile-instr-generate -fcoverage-mapping -lm -o $@ -lcheck -lrt -lpthread -lsubunit

# Run the main binary
run: clean prep compile
	./$(MAIN_BIN)

# Generate documentation
doxygen: Doxyfile
	doxygen

# Run tests and generate coverage report
test: clean prep compile
	LLVM_PROFILE_FILE="$(DIST_DIR)/test.profraw" ./$(TEST_BIN)
	llvm-profdata merge -sparse $(DIST_DIR)/test.profraw -o $(DIST_DIR)/test.profdata
	llvm-cov report $(TEST_BIN) -instr-profile=$(DIST_DIR)/test.profdata src/*.c
	llvm-cov show $(TEST_BIN) -instr-profile=$(DIST_DIR)/test.profdata src/*.c --format=html > $(HTML_DIR)/coverage.html

# Default target
all: clean prep compile
