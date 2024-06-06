CC = clang
C_OPTS = $(MAC_OPTS) -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src src/lib.c
 
clean:
	rm -rf dist
prep:
	mkdir -p dist/html
 
format:
	clang-format --verbose -dry-run --Werror src/*
 
 compile: main.bin test.bin
 
main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
test.bin: test/test.c
	$(CC) $(C_OPTS) $< -fprofile-instr-generate -fcoverage-mapping -lm -o ./dist/$@ -lcheck -lrt -lpthread -lsubunit
 
run: clean prep compile
	./dist/main.bin


doxygen: Doxyfile
		 doxygen
test: clean prep compile
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html
 
all: clean prep compile

