#ifndef LITERAL_H
#define LITERAL_H

#include "expression.h"
#include <string>

class Literal : public Expression
{
public:
    Literal(std::string v);

    std::string getValue() const;

private:
    std::string value;
};

#endif // LITERAL_H
