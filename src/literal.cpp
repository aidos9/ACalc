#include "../headers/literal.h"

Literal::Literal(std::string v)
{
    value = v;
    type = lit;
}


std::string Literal::getValue() const
{
    return value;
}
