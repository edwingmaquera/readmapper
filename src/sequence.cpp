#include "sequence.hpp"

Sequence::Sequence(std::string id, std::string value) :
    id_(id), value_(value)
{}

std::string Sequence::id()
{
    return this->id_;
}
std::string Sequence::value()
{
    return this->value_;
}