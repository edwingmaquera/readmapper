#include <algorithm>
#include <iostream>
#include <vector>

#include "sequence.hpp"
#include "fastareader.hpp"
#include "fastqreader.hpp"
#include "sw.hpp"



int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cout
            << "Error: no se especificaron suficientes archivos de entrada." 
            << std::endl;
        return 1;
    }
    
    std::string filename1 = argv[1];
    std::string filename2 = argv[2];
    
    size_t pos1 = filename1.rfind(".") + 1;
    size_t pos2 = filename2.rfind(".") + 1;
    
    std::string extension1 = filename1.substr(pos1);
    std::string extension2 = filename2.substr(pos2);
    
    std::vector<std::string> fasta_extensions {"fasta", "fas"};
    std::vector<std::string> fastq_extensions {"fastq", "fq"};
    
    SequenceReader* reader1;
    SequenceReader* reader2;
    
    if(std::find(fasta_extensions.begin(), 
                 fasta_extensions.end(), 
                 extension1) != fasta_extensions.end())
    {
        reader1 = new FASTAReader(filename1);
    }
    else if(std::find(fastq_extensions.begin(), 
                      fastq_extensions.end(), 
                      extension1) != fastq_extensions.end())
    {
        reader1 = new FASTQReader(filename1); //falta implementar las funciones
    }
    else
    {
        std::cout << "Error: no se pudo reconocer el tipo de archivo." << std::endl;
        return 1;
    }
    
    
    
    if(std::find(fasta_extensions.begin(), 
                 fasta_extensions.end(), 
                 extension2) != fasta_extensions.end())
    {
        reader2 = new FASTAReader(filename2);
    }
    else if(std::find(fastq_extensions.begin(), 
                      fastq_extensions.end(), 
                      extension2) != fastq_extensions.end())
    {
        reader2 = new FASTQReader(filename2); //falta implementar las funciones
    }
    else
    {
        std::cout << "Error: no se pudo reconocer el tipo de archivo." << std::endl;
        return 1;
    }
    
    //matriz de sustitución
    int smatrix[]{ 5, -4, -4, -4,
                  -4,  5, -4, -4,
                  -4, -4,  5, -4,
                  -4, -4, -4,  5};
    int gap_open   = 10;
    int gap_extend =  1;
    
    while(reader1->next() && reader2->next())
    {
        Sequence seq1(reader1->getID(), reader1->getSequence());
        Sequence seq2(reader2->getID(), reader2->getSequence());
        
        Alignment alignment 
            = smith_waterman(seq1, seq2, smatrix, gap_open, gap_extend);
        alignment.print();
    }
    delete reader1;
    delete reader2;
    return 0;
}
