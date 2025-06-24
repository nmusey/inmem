#include "set.hpp"

SetCommand::SetCommand(Database* db, std::string line) {
    this->line = line;
    this->db = db;
}

std::string SetCommand::Parse() {
    auto key = this->parseKey();
    this->db->Set(key, this->line);
    return "";
}
