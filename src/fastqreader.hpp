#pragma once

#include "sequencereader.hpp"

class FASTQReader : public SequenceReader
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
    //agregar los campos y métodos auxiliares que veas por conveniente
public:
    FASTQReader(char* filename);
    FASTQReader(std::string filename);
    std::string getID();
    std::string getSequence();
    bool next();
};