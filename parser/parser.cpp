#include "parser.hpp"
#include "operations/get.hpp"
#include "operations/set.hpp"
#include "operations/delete.hpp"
#include "operations/noop.hpp"

Parser* Parser::ParseCommand(Database* db, std::string line) {
    std::string command = "";
    for (auto c : line) {
        if (c == ' ') {
            break;
        }

        command += toupper(c);
    }

    // TODO - possible off by one error if no key given
    line = line.substr(command.length()+1, line.length());

    if (command == "GET") return new GetCommand(db, line);
    if (command == "SET") return new SetCommand(db, line);
    if (command == "DELETE") return new DeleteCommand(db, line);

    return new NoopCommand();
}

std::string Parser::parseKey() {
    std::string key = "";
    for (auto c : this->line) {
        if (c == ' ') {
            break;
        }

        key += c;
    }

    if (key.length() < this->line.length()) {
        std::string value = this->line.substr(key.length()+1, std::string::npos);
        this->line = value;
    }

    return key;
}
