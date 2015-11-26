#include <algorithm>
#include <iostream>
#include <vector>

#include "sequence.hpp"
#include "fastareader.hpp"
#include "fastqreader.hpp"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Error: no se especificó el archivo de entrada." << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    size_t pos = filename.rfind(".") + 1;
    std::string extension = filename.substr(pos);
    
    std::vector<std::string> fasta_extensions {"fasta", "fas"};
    std::vector<std::string> fastq_extensions {"fastq", "fq"};
    
    SequenceReader* reader;
    
    if(std::find(fasta_extensions.begin(), 
                 fasta_extensions.end(), 
                 extension) != fasta_extensions.end())
    {
        reader = new FASTAReader(filename);
    }
    else if(std::find(fastq_extensions.begin(), 
                      fastq_extensions.end(), 
                      extension) != fastq_extensions.end())
    {
        reader = new FASTQReader(filename); //falta implementar las funciones
    }
    else
    {
        std::cout << "Error: no se pudo reconocer el tipo de archivo." << std::endl;
        return 1;
    }
    
    while(reader->next())
    {
        std::cout << "ID : " << reader->getID() << std::endl;
        std::cout << "SEQ: " << reader->getSequence() << std::endl;
    }
    delete reader;
    return 0;
}
