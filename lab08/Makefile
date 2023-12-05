CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Wno-error=vla -Wno-unused-but-set-variable 

clean:
	sudo rm -rf dist
prep:
	mkdir dist	
	
format:
	clang-format --verbose -dry-run src/*
	
compile: mainf.bin mains.bin maint.bin

mainf.bin: src/mainf.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
mains.bin: src/mains.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
maint.bin: src/maint.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/mainf.bin
	./dist/mains.bin
	./dist/maint.bin

doxygen: Doxyfile 
		 doxygen

check:
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
all: clean prep compile check doxygen

