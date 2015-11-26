#pragma once

#include "sequence.hpp"

class Alignment
{
private:
    Sequence sequence1_;
    Sequence sequence2_;
    std::string alignment1_;
    std::string alignment2_;
    int i_0_, j_0_, i_, j_;
    int score_;
public:
    Alignment(Sequence seq1, Sequence seq2, 
        std::string alignment1, std::string alignment2, 
        int i_0, int j_0, int i, int j, int score) : 
        sequence1_(seq1), sequence2_(seq2), 
        alignment1_(alignment1), alignment2_(alignment2),
        i_0_(i_0), j_0_(j_0), i_(i), j_(j), score_(score)
    {}
    Sequence sequence1();
    Sequence sequence2();
    std::string alignment1();
    std::string alignment2();
    int i_0();
    int j_0();
    int i();
    int j();
    int score();
    void print();
};

