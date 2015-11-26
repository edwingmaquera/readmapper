#include "sw.hpp"

/*
 * Este método recorre la tabla H partiendo de la celda con mayor puntaje hasta
 * encontrar una celda con valor 0. Además, va reconstruyendo el alineamiento.
 * Ejemplo: después de la ejecución, en las cadenas aln1 y aln2 debería haber 
 * algo asi:
 * aln1: AT--GCAAAGGC
 * aln2: ATTTGTAAA-GC
 */
void sw_backtrack(std::string seq1, std::string seq2, 
        int* E, int* F, int* H, int* smatrix, int gap_open, int gap_extend,
        int* i_0, int* j_0,
        int max_i, int max_j,
        char* aln1, char* aln2)
{
    //TODO: implementar
}


/*
 * Función que es la que en realidad computa las celdas
 */
void sw(std::string seq1, std::string seq2, 
        int* E, int* F, int* H, int* smatrix, 
        int gap_open, int gap_extend,
        int* max_i, int* max_j, int* max_score)
{
    //TODO: implementar
}

/*
 * Smith-Waterman: devuelve el alineamiento local entre dos secuencias.
 * Implementar la versión "affine gap penalty (tablas E, F y H)"
 * smatrix: matriz de sustitución
 * gap_open: penalidad de abrir una brecha (casi siempre es 10)
 * gap_extend: penalidad de extender una brecha (casi siempre es 1 en 
 *             enteros y 0.5 si se trabaja con float)
 */
Alignment smith_waterman(Sequence seq1, Sequence seq2, 
                        int* smatrix, int gap_open, int gap_extend)
{
    std::string str1 = seq1.value();
    std::string str2 = seq2.value();
    int m = str1.size() + 1;
    int n = str1.size() + 1;
    
    int* E = new int[m * n];
    int* F = new int[m * n];
    int* H = new int[m * n];
    
    //TODO: inicializar matrices
    
    int max_i, max_j, max_score;
    
    sw(str1, str2, E, F, H, smatrix, gap_open, gap_extend,
        &max_i, &max_j, &max_score);
    
    char* aln1 = new char[1000]; //fijar un límite conveniente
    char* aln2 = new char[1000]; //fijar un límite conveniente
    
    int i_0, j_0; //posiciones donde empiezan los alineamientos
    
    sw_backtrack(str1, str2, E, F, H, smatrix, gap_open, gap_extend,
                 &i_0, &j_0, max_i, max_j,
                 aln1, aln2);
    
    //incluimos la información generada en pasos anteriores
    Alignment alignment(seq1, seq2, aln1, aln2, 
                        i_0, j_0, max_i, max_j, max_score);
    return alignment;
}

