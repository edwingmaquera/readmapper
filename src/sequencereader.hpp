#pragma once

#include <string>

class SequenceReader
{
public:
    virtual bool next() = 0;
    virtual std::string getID() = 0;
    virtual std::string getSequence() = 0;
};
