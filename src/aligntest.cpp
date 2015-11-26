#include <algorithm>
#include <iostream>
#include <vector>

#include "alignment.hpp"
#include "sequence.hpp"

int main(int argc, char* argv[])
{
    //Ejemplo de alineamiento ficticio
    //Ojo, no se está calculando nada en este ejemplo
    Sequence seq1("seq_a_1", "GTACTCATAAAA");
    Sequence seq2("seq_b_1", "GACTCAGTAACA");
    //Sequence seq1("seq_a_1", "GTACTCA T");
    //Sequence seq2("seq_b_1", "G ACTCAGT");
    Alignment alignment(seq1, seq2, "GTACTCA-TAAAA", "G-ACTCAGTAACA", 
                        0, 0, 10, 10, 26);
    
    alignment.print();
    
    return 0;
}
