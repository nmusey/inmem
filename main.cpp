#include <iostream>

#include "database/database.hpp"
#include "parser/parser.hpp"

int main() {
    Database* db = new Database;

    auto get = Parser::ParseCommand(db, std::string("GET hello"))->Parse();
    auto set = Parser::ParseCommand(db, std::string("SET hello world"))->Parse();
    auto get2 = Parser::ParseCommand(db, std::string("GET hello"))->Parse();
    auto del = Parser::ParseCommand(db, std::string("DELETE hello world"))->Parse();

    std::cout << get << std::endl << set << std::endl << get2 << std::endl << del << std::endl;;

    delete db;
    return 0;
}
