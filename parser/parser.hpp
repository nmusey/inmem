#pragma once

#include <string>
    
#include "../database/database.hpp"

class Parser {
public:
    virtual std::string Parse() = 0;
    static Parser* ParseCommand(Database* db, std::string line);

protected:
    Database* db;
    std::string line;

    std::string parseKey();
};
