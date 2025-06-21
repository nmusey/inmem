#pragma once

#include <string>

#include "../parser.hpp"

class Database;

class DeleteCommand : public Parser {
public:
    DeleteCommand(Database* db, std::string* line);

    std::string Parse() override;

private:
    std::string* line;
    Database* db;
};
