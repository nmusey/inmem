#pragma once

#include <memory>
#include <unordered_map>
#include <string>

typedef std::unordered_map<std::string, std::string> store_t;

class Database {
public:
    Database();

    std::string Get(std::string key);
    void Set(std::string key, std::string value);
    std::string Delete(std::string key);

    std::shared_ptr<store_t> getStore();

private: 
    std::shared_ptr<store_t> store; 
};
