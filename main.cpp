#include <iostream>

#include "database/database.hpp"
#include "parser/parser.hpp"

int main() {
    Database* db = new Database;

    auto get = Parser::ParseCommand(db, std::string("GET hello"))->Parse();
    std::cout << get << std::endl;

    auto set = Parser::ParseCommand(db, std::string("SET hello world"))->Parse();
    std::cout << set << std::endl;

    auto get2 = Parser::ParseCommand(db, std::string("GET hello"))->Parse();
    std::cout << get2 << std::endl;

    auto del = Parser::ParseCommand(db, std::string("DELETE hello world"))->Parse();
    std::cout << del << std::endl;

    delete db;
    return 0;
}
