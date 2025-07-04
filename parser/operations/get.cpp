#include "get.hpp"

GetCommand::GetCommand(std::shared_ptr<Database> db, std::string line) {
    this->line = line;
    this->db = db;
}

std::string GetCommand::Parse() {
    auto key = this->parseKey();
    return this->db->Get(key);
}
