files = database/database.cpp parser/parser.cpp parser/operations/get.cpp parser/operations/set.cpp parser/operations/delete.cpp parser/operations/keys.cpp parser/operations/noop.cpp
flags = -std=c++20 -Wall -Wextra -Werror 

setup:
	@mkdir -p build/{debug,tests}

build: setup
	@g++ -g $(flags) -o build/debug/inmem main.cpp $(files)

run: build
	./build/debug/inmem

debug: build
	gdb ./build/debug/inmem

memory: build
	valgrind ./build/debug/inmem

test: setup
	@g++ -g $(flags) -o build/tests/inmem tests/main.cpp $(files)
	./build/tests/inmem

clean:
	rm -rf ./build
