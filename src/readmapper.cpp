#include <iostream>

#include "sequence.hpp"
#include "fastareader.hpp"

int main(int argc, char* argv[])
{
    FASTAReader reader(argv[1]);
    while(reader.next())
    {
        std::cout << "ID : " << reader.getID() << std::endl;
        std::cout << "SEQ: " << reader.getSequence() << std::endl;
    }
    
    return 0;
}
