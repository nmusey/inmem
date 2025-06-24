#include "database.hpp"

#include <iostream>

Database::Database() {
    this->store = std::make_unique<store_t>();
}

std::string Database::Get(std::string key) {
    if (this->store->contains(key)) {
        return this->store->at(key);
    }

    return std::string(""); 
}

void Database::Set(std::string key, std::string value) {
    std::pair<std::string, std::string> pair = { key, value };
    this->store->insert(pair);
}

std::string Database::Delete(std::string key) {
    std::string current_value = this->Get(key);
    this->store->erase(key);

    return current_value;
}

std::shared_ptr<store_t> Database::getStore() {
    return this->store;
}
