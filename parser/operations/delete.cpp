#include "delete.hpp"

DeleteCommand::DeleteCommand(std::shared_ptr<Database> db, std::string line) {
    this->db = db;
    this->line = line;
}

std::string DeleteCommand::Parse() {
    auto key = this->parseKey();
    return this->db->Delete(key);
}
