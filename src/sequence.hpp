#pragma once

#include <string>

class Sequence
{
private:
    std::string id_;
    std::string value_;
public:
    Sequence(std::string id, std::string value);
    std::string id();
    std::string value();
};
