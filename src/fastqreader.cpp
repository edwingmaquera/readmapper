#include <cstdlib>  //borrar después de implementar las funciones
#include <iostream> //borrar después de implementar las funciones

#include "fastqreader.hpp"

/*
 * Implementar las funciones. Puedes agregar los campos y métodos que veas
 * por conveniente.
 */
FASTQReader::FASTQReader(char* filename)
    file_(fopen(filename, "r"))
{
    current = fgetc(file_);
}

FASTQReader::FASTQReader(std::string filename)
    file_(fopen(filename.c_str(), "r"))
{
    current = fgetc(file_);
}

std::string FASTQReader::getID()
{
    return this->id_;
}

std::string FASTQReader::getSequence()
{
    return this->sequence_;
}

bool FASTQReader::next()
{
    this->id_.clear();
    this->sequence_.clear();
    if(accept('@'))
    {
        inheader=true;
        while(acceptPrintable());
        acceptSpace();
        inheader=false;
        while(acceptPrintableBut('@') || acceptSpace());
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

bool FASTAReader::acceptSpace()
{
    if(isspace(current))
    {
        current = fgetc(file_);
        return true;
    }
    return false;
}