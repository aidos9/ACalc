#ifndef CALL_H
#define CALL_H

#include "token.h"
#include "expression.h"
#include <memory>
#include <vector>

class Call : public Expression
{
public:
    Call(Token c, std::vector<std::shared_ptr<Expression>> a);
    Token getCallee() const;
    std::vector<std::shared_ptr<Expression>> getArguments() const;

private:
    Token callee;
    std::vector<std::shared_ptr<Expression>> arguments;
};

#endif // CALL_H
