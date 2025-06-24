#pragma once

#include <string>
 
#include "../../database/database.hpp"
#include "../parser.hpp"

class GetCommand: public Parser {
public:
    GetCommand(std::shared_ptr<Database> db, std::string line);
    std::string Parse() override;
};
