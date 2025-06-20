#include "database.hpp"

#include <iostream>

Database::Database() {
    this->memmap = new std::unordered_map<std::string, std::string>();
}

Database::~Database() {
    delete this->memmap;
}

std::string Database::Get(std::string key) {
    if (this->memmap->contains(key)) {
        return this->memmap->at(key);
    }

    return std::string(""); 
}

void Database::Set(std::string key, std::string value) {
    std::pair<std::string, std::string> pair = { key, value };
    this->memmap->insert(pair);
}

std::string Database::Delete(std::string key) {
    std::string current_value = this->Get(key);
    this->memmap->erase(key);

    return current_value;
}
