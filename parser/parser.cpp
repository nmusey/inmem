#include "parser.hpp"
#include "operations/get.hpp"
#include "operations/set.hpp"
#include "operations/delete.hpp"
#include "operations/keys.hpp"
#include "operations/noop.hpp"

std::unique_ptr<Parser> Parser::ParseCommand(std::shared_ptr<Database> db, std::string line) {
    std::string command = "";
    for (auto c : line) {
        if (c == ' ') {
            break;
        }

        command += toupper(c);
    }

    if (command.length() < line.length()) {
        line = line.substr(command.length()+1, line.length());
    }

    if (command == "GET") return std::make_unique<GetCommand>(db, line);
    if (command == "SET") return std::make_unique<SetCommand>(db, line);
    if (command == "DELETE") return std::make_unique<DeleteCommand>(db, line);
    if (command == "KEYS") return std::make_unique<KeysCommand>(db);

    return std::make_unique<NoopCommand>();
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
