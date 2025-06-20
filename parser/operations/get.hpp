#pragma once

#include <string>
 
#include "../../database/database.hpp"
#include "../parser.hpp"

class GetCommand: public Parser {
public:
    GetCommand(Database* db, std::string* line);

    std::string Parse() override;

private:
    std::string* line;
    Database* db;
};
