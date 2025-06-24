files = main.cpp database/database.cpp parser/parser.cpp parser/operations/get.cpp parser/operations/set.cpp parser/operations/delete.cpp parser/operations/keys.cpp parser/operations/noop.cpp
flags = -std=c++20 -Wall -Wextra -Werror -o build/debug/inmem 

setup:
	@mkdir -p build/debug

build: setup
	@g++ -g $(flags) $(files)

run: build
	./build/debug/inmem

debug: build
	gdb ./build/debug/inmem

memory: build
	valgrind ./build/debug/inmem
