#pragma once

#include "sequence.hpp"
#include "alignment.hpp"

Alignment smith_waterman(Sequence seq1, Sequence seq2, 
                        int* smatrix, int gap_open, int gap_extend);
