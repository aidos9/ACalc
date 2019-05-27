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
    }else if(e->type == ExpressionType::call)
    {
        std::shared_ptr<Call> call = std::dynamic_pointer_cast<Call>(e);

        if(call->getCallee().value == "sin")
        {
            if(call->getArguments().size() != 1)
            {
                throw Exception("Only 1 argument expected", 9);
            }

            double internals = evaluateNode(call->getArguments()[0]);
            return sin(internals);
        }else if(call->getCallee().value == "cos")
        {
            if(call->getArguments().size() != 1)
            {
                throw Exception("Only 1 argument expected", 9);
            }

            double internals = evaluateNode(call->getArguments()[0]);
            return cos(internals);
        }else if(call->getCallee().value == "tan")
        {
            if(call->getArguments().size() != 1)
            {
                throw Exception("Only 1 argument expected", 9);
            }

            double internals = evaluateNode(call->getArguments()[0]);
            return tan(internals);
        }else if(call->getCallee().value == "asin")
        {
            if(call->getArguments().size() != 1)
            {
                throw Exception("Only 1 argument expected", 9);
            }

            double internals = evaluateNode(call->getArguments()[0]);
            return asin(internals);
        }else if(call->getCallee().value == "acos")
        {
            if(call->getArguments().size() != 1)
            {
                throw Exception("Only 1 argument expected", 9);
            }

            double internals = evaluateNode(call->getArguments()[0]);
            return acos(internals);
        }else if(call->getCallee().value == "atan")
        {
            if(call->getArguments().size() != 1)
            {
                throw Exception("Only 1 argument expected", 9);
            }

            double internals = evaluateNode(call->getArguments()[0]);
            return atan(internals);
        }else{
            throw Exception("Unknown identifier", 8);
        }
    }

    throw Exception("Fell through function",2);
}
