# inmem

An in memory database to practice C++

## Working on the project
All instructions here assume a working local copy (`git clone https://github.com/nmusey/inmem`)

See `Makefile' for all possible commands. 

### Building
Assumes `g++` is installed locally.
`make build` builds a debug version, 
`make release` builds a release version

### Running
Executable is found in `build/{debug|release|tests}/inmem` depending on which target was built.
`make run` builds and runs the debug version

### Testing
Integration testing is run with `make test`

### Debugging
Run gdb with `make debug`
Run valgrind with `make memory`
