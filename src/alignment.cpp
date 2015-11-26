#include <iostream>

#include "alignment.hpp"

Sequence Alignment::sequence1()
{
    return this->sequence1_;
}

Sequence Alignment::sequence2()
{
    return this->sequence2_;
}

std::string Alignment::alignment1()
{
    return this->alignment1_;
}

std::string Alignment::alignment2()
{
    return this->alignment2_;
}

int Alignment::i_0()
{
    return this->i_0_;
}

int Alignment::j_0()
{
    return this->j_0_;
}

int Alignment::i()
{
    return this->i_;
}

int Alignment::j()
{
    return this->j_;
}

int Alignment::score()
{
    return this->score_;
}

void Alignment::print()
{
    std::cout << "seq1: " << this->sequence1_.id() << std::endl;
    std::cout << "seq2: " << this->sequence2_.id() << std::endl;
    std::cout << "score: " << this->score() << std::endl;
    std::cout << this->alignment1_ << std::endl;
    for(int i = 0; i < this->alignment1_.size(); i++)
    {
        if(this->alignment1_[i] == this->alignment2_[i])
            std::cout << '|';
        else if(this->alignment1_[i] == '-' 
                || this->alignment2_[i] == '-')
            std::cout << ' ';
        else
            std::cout << '.';
    }
    std::cout << std::endl;
    std::cout << this->alignment2_ << std::endl << std::endl;
}
