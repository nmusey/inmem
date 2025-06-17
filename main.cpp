#include <iostream>

#include "database/database.hpp"

int main() {
    std::cout << "Hello world" << std::endl;

    Database* db = new Database;
    db->Set("hello", "world");
    std::cout << db->Get("hello") << std::endl;

    auto val = db->Delete("hello");
    std::cout << val << std::endl;

    delete db;
    return 0;
}
