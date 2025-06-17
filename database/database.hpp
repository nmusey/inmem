#pragma once

#include <unordered_map>
#include <string>

class Database {
public:
    Database();
    ~Database();

    std::string Get(std::string key);
    void Set(std::string key, std::string value);
    std::string Delete(std::string key);

private: 
    std::unordered_map<std::string, std::string>* memmap = {};
};
