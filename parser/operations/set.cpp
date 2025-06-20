#include "set.hpp"

SetCommand::SetCommand(Database* db, std::string* line) {
    this->line = line;
    this->db = db;
}

std::string SetCommand::Parse() {
    std::string key = "";
    for (auto c : *this->line) {
        if (c == ' ') {
            break;
        }

        key += c;
    }

    std::string value = this->line->substr(key.length()+1, this->line->length());
    this->db->Set(key, value);
    return "";
}
