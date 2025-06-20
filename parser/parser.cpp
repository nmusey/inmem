#include "parser.hpp"
#include "operations/get.hpp"
#include "operations/set.hpp"
#include "operations/noop.hpp"

Parser* Parser::ParseCommand(Database* db, std::string line) {
    std::string command = "";
    for (auto c : line) {
        if (c == ' ') {
            break;
        }

        command += toupper(c);
    }

    line = line.substr(command.length()+1, line.length());
    if (command == "GET") {
        return new GetCommand(db, &line);
    }

    if (command == "SET") {
        return new SetCommand(db, &line);
    }

    return new NoopCommand();
}
