#include "keys.hpp"

KeysCommand::KeysCommand(std::shared_ptr<Database> db) {
    this->db = db;
}

std::string KeysCommand::Parse() {
    auto store = this->db->getStore();

    std::string keys = "";
    for (auto pair : *store) {
        keys += " " + pair.first;
    }

    return keys;
}
