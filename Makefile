files = main.cpp database/database.cpp parser/parser.cpp parser/operations/get.cpp parser/operations/set.cpp parser/operations/noop.cpp
flags = -std=c++20 -Wall -Wextra -Werror -o build/debug/inmem 

setup:
	@mkdir -p build/debug

run: setup
	@g++ $(flags) $(files) 
	./build/debug/inmem

debug: setup
	@g++ -g $(flags) $(files) 
	gdb ./build/debug/inmem

