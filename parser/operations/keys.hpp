#pragma once

#include <memory>
#include <string>

#include "../../database/database.hpp"
#include "../parser.hpp"

class KeysCommand: public Parser {
public:
    KeysCommand(std::shared_ptr<Database> db);

    std::string Parse() override;
};
