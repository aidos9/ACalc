#include "../headers/evaluator.h"
#include <cmath>

double Evaluator::evaluateNode(std::shared_ptr<Expression> e)
{
    if(e->type == ExpressionType::lit)
    {
        std::shared_ptr<Literal> literal = std::dynamic_pointer_cast<Literal>(e);
        return std::stod(literal->getValue());
    }else if(e->type == ExpressionType::bin)
    {
        std::shared_ptr<Binary> binary = std::dynamic_pointer_cast<Binary>(e);

        switch (binary->getOp().type) {
        case TokenType::tok_add:
             return evaluateNode(binary->getLeft()) + evaluateNode(binary->getRight());
        case TokenType::tok_sub:
             return evaluateNode(binary->getLeft()) - evaluateNode(binary->getRight());
        case TokenType::tok_mul:
             return evaluateNode(binary->getLeft()) * evaluateNode(binary->getRight());
        case TokenType::tok_div:
             return evaluateNode(binary->getLeft()) / evaluateNode(binary->getRight());
        case TokenType::tok_exp:
            return pow(evaluateNode(binary->getLeft()), evaluateNode(binary->getRight()));
        case TokenType::tok_mod:
            return std::fmod(evaluateNode(binary->getLeft()), evaluateNode(binary->getRight()));
        default:
            throw Exception("Fell through switch",1);
        }
    }else if(e->type == ExpressionType::grp)
    {
        std::shared_ptr<Grouping> grouping = std::dynamic_pointer_cast<Grouping>(e);
        return evaluateNode(grouping->getExpression());
    }else if(e->type == ExpressionType::uny)
    {
        std::shared_ptr<Unary> unary = std::dynamic_pointer_cast<Unary>(e);
        if(unary->getOp().type == TokenType::tok_sub)
        {
            return -1*(evaluateNode(unary->getRight()));
        }
    }

    throw Exception("Fell through function",2);
}
