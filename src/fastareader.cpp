#include <cstdio>
#include <cctype>

#include "fastareader.hpp"

FASTAReader::FASTAReader(char* filename) :
    file_(fopen(filename, "r"))
{
    current = fgetc(file_);
}

FASTAReader::FASTAReader(std::string filename) :
    file_(fopen(filename.c_str(), "r"))
{
    current = fgetc(file_);
}

bool FASTAReader::accept(char ch)
{
    if(current == ch)
    {
        current = fgetc(file_);
        return true;
    }
    return false;
}

bool FASTAReader::acceptSpace()
{
    if(isspace(current))
    {
        current = fgetc(file_);
        return true;
    }
    return false;
}


bool FASTAReader::acceptPrintable()
{
    if(isprint(current))
    {        
        if(inheader)
            this->id_ += current;
        else
            this->sequence_ += current;
        current = fgetc(file_);
        return true;
    }
    return false;
}

bool FASTAReader::acceptPrintableBut(char ch)
{
    if(isprint(current) && current != ch)
    {
        if(inheader)
            this->id_ += current;
        else
            this->sequence_ += current;
        current = fgetc(file_);
        return true;
    }
    return false;
}


bool FASTAReader::next()
{
    this->id_.clear();
    this->sequence_.clear();
    if(accept('>'))
    {
        inheader=true;
        while(acceptPrintable());
        acceptSpace();
        inheader=false;
        while(acceptPrintableBut('>') || acceptSpace());
        return true;
    }
    return false;
}

std::string FASTAReader::getID()
{
    return this->id_;
}
std::string FASTAReader::getSequence()
{
    return this->sequence_;
}
