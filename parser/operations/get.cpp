#include "get.hpp"

GetCommand::GetCommand(Database* db, std::string* line) {
    this->line = line;
    this->db = db;
}

std::string GetCommand::Parse() {
    std::string key = "";
    for (auto c : *this->line) {
        if (c == ' ') {
            break;
        }

        key += c;
    }

    return this->db->Get(key);
}
