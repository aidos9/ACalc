#ifndef EXPRESSION_H
#define EXPRESSION_H

enum ExpressionType {
    bin,
    uny,
    lit,
    grp,
    none,
};

class Expression
{
public:
    Expression();
    virtual ~Expression() = default;

    ExpressionType type = none;
};

#endif // EXPRESSION_H
