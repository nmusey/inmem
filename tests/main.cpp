#include <iostream>
#include <memory>

#include "../database/database.hpp"
#include "../parser/parser.hpp"

int main() {
    auto db = std::make_shared<Database>();

    auto val = Parser::ParseCommand(db, "GET hello")->Parse();
    if (val != "") {
        std::cout << "Failed to GET null" << std::endl;
        std::cout << "GOT: " << val << std::endl;
        return 1;
    }

    Parser::ParseCommand(db, "SET hello world")->Parse();
    Parser::ParseCommand(db, "SET k1 v1")->Parse();
    Parser::ParseCommand(db, "SET k2 v2")->Parse();

    val = Parser::ParseCommand(db, "GET hello")->Parse();
    if (val != "world") {
        std::cout << "Failed to GET after setting" << std::endl;
        std::cout << "GOT: " << val << std::endl;
        return 1;
    }

    val = Parser::ParseCommand(db, "KEYS")->Parse();
    if (val.find("hello") == std::string::npos) {
        std::cout << "Failed to get KEYS" << std::endl;
        std::cout << "GOT: " << val << std::endl;
        return 1;
    }

    val = Parser::ParseCommand(db, "DELETE hello world")->Parse();
    if (val.find("hello") != std::string::npos) {
        std::cout << "Failed to return after deleting values" << std::endl;
        std::cout << "GOT: " << val << std::endl;
        return 1;
    }

    std::cout << "Test passed" << std::endl;
    return 0;
}
