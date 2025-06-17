run:
	@mkdir -p build/debug
	@g++ -Wall -Wextra -Werror -o build/debug/inmem main.cpp database/database.cpp
	./build/debug/inmem
