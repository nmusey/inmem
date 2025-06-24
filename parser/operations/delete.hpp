#pragma once

#include <string>

#include "../parser.hpp"

class Database;

class DeleteCommand : public Parser {
public:
    DeleteCommand(std::shared_ptr<Database> db, std::string line);

    std::string Parse() override;
};
