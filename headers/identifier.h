#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "token.h"
#include "expression.h"
#include <memory>
#include <vector>

class Identifier : public Expression
{
public:
    Identifier(Token c);
    Token getValue() const;

private:
    Token value;
};
#endif // IDENTIFIER_H
