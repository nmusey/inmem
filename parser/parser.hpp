#pragma once

#include <string>
#include<memory>
    
#include "../database/database.hpp"

class Parser {
public:
    virtual std::string Parse() = 0;
    static std::unique_ptr<Parser> ParseCommand(std::shared_ptr<Database> db, std::string line);

protected:
    std::shared_ptr<Database> db;
    std::string line;

    std::string parseKey();
};
