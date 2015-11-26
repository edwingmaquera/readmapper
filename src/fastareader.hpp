#pragma once

#include "sequencereader.hpp"

class FASTAReader : public SequenceReader
{
private:
    FILE* file_;
    int current;
    bool inheader;
    std::string id_;
    std::string sequence_;
    bool accept(char ch);
    bool acceptSpace();
    bool acceptPrintable();
    bool acceptPrintableBut(char ch);
public:
    FASTAReader(char* filename);
    FASTAReader(std::string filename);
    std::string getID();
    std::string getSequence();
    bool next();
};
