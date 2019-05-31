#include "../headers/identifier.h"

Identifier::Identifier(Token v)
{
    value = v;
    type = ExpressionType::identifier;
}


Token Identifier::getValue() const
{
    return value;
}
