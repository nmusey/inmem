#include "delete.hpp"

DeleteCommand::DeleteCommand(Database* db, std::string* line) {
    this->db = db;
    this->line = line;
}

std::string DeleteCommand::Parse() {
    std::string key = "";
    for (auto c : *this->line) {
        if (c == ' ') {
            break;
        }

        key += c;
    }

    return this->db->Delete(key);
}
