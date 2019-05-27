#include "../headers/call.h"

Call::Call(Token c, std::vector<std::shared_ptr<Expression>> a)
{
    callee = c;
    arguments = a;
    type = ExpressionType::call;
}


Token Call::getCallee() const
{
    return callee;
}

std::vector<std::shared_ptr<Expression>> Call::getArguments() const
{
    return arguments;
}
