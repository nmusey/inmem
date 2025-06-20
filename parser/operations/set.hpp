#pragma once

#include <string>

#include "../../database/database.hpp"
#include "../parser.hpp"

class SetCommand: public Parser {
public:
    SetCommand(Database* db, std::string* line);

    std::string Parse() override;

private:
    std::string* line;
    Database* db;
};
