#pragma once

#include <string>

#include "../parser.hpp"

class NoopCommand: public Parser {
public:
    NoopCommand();
    std::string Parse() override;
};
