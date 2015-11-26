#pragma once

#include "sequencereader.hpp"

class FASTQReader : public SequenceReader
{
private:
    //agregar los campos y métodos auxiliares que veas por conveniente
public:
    FASTQReader(char* filename);
    FASTQReader(std::string filename);
    std::string getID();
    std::string getSequence();
    bool next();
};