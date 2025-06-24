#pragma once

#include <string>

#include "../../database/database.hpp"
#include "../parser.hpp"

class SetCommand: public Parser {
public:
    SetCommand(std::shared_ptr<Database> db, std::string line);

    std::string Parse() override;
};
