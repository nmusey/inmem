#include <iostream>
#include <memory>
#include <string>

#include "database/database.hpp"
#include "parser/parser.hpp"

#define MaxLineLength 255

int main() {
    auto db = std::make_shared<Database>();

    std::string input = "";
    do {
        std::getline(std::cin, input);
        auto val = Parser::ParseCommand(db, input)->Parse();
        std::cout << val << std::endl;
    } while (input.length() > 0);

    // auto get = Parser::ParseCommand(db, "GET hello")->Parse();
    // std::cout << "Get1: " << get << std::endl;

    // Parser::ParseCommand(db, "SET hello world")->Parse();
    // Parser::ParseCommand(db, "SET k1 v1")->Parse();
    // Parser::ParseCommand(db, "SET k2 v2")->Parse();

    // auto get2 = Parser::ParseCommand(db, "GET hello")->Parse();
    // std::cout << "Get2: " << get2 << std::endl;

    // auto keys = Parser::ParseCommand(db, "KEYS")->Parse();
    // std::cout << "Keys: " << keys << std::endl;

    // auto del = Parser::ParseCommand(db, "DELETE hello world")->Parse();
    // std::cout << "Delete: " << del << std::endl;


    return 0;
}
