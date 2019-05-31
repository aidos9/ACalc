#include "../headers/evaluator.h"
#include <cmath>

const long double PI = 3.141592653589793238L;
const long double EPSILON = 0.000000000000001L;
const long double E = 2.71828182845904523536L;

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
            internals = sin(internals);

            if (fabs(internals) < static_cast<double>(EPSILON))
            {
                return 0;
            }else if(fabs(internals-1) < static_cast<double>(EPSILON))
            {
                return 1;
            }else if(fabs(internals+1) < static_cast<double>(EPSILON))
            {
                return -1;
            }

            return internals;
        }else if(call->getCallee().value == "cos")
        {
            if(call->getArguments().size() != 1)
            {
                throw Exception("Only 1 argument expected", 9);
            }

            double internals = evaluateNode(call->getArguments()[0]);
            internals = sin(internals);

            if (fabs(internals) < static_cast<double>(EPSILON))
            {
                return 0;
            }else if(fabs(internals-1) < static_cast<double>(EPSILON))
            {
                return 1;
            }else if(fabs(internals+1) < static_cast<double>(EPSILON))
            {
                return -1;
            }

            return internals;
        }else if(call->getCallee().value == "tan")
        {
            if(call->getArguments().size() != 1)
            {
                throw Exception("Only 1 argument expected", 9);
            }

            double internals = evaluateNode(call->getArguments()[0]);
            internals = tan(internals);

            if (fabs(internals) < static_cast<double>(EPSILON))
            {
                return 0;
            }else if(fabs(internals-1) < static_cast<double>(EPSILON))
            {
                return 1;
            }else if(fabs(internals+1) < static_cast<double>(EPSILON))
            {
                return -1;
            }

            return internals;
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
        }else if(call->getCallee().value == "gcd")
        {
            if(call->getArguments().size() != 2)
            {
                throw Exception("2 arguments expected", 9);
            }

            long long left = static_cast<long long>(evaluateNode(call->getArguments()[0]));
            long long right = static_cast<long long>(evaluateNode(call->getArguments()[1]));
            return gcd(left, right);
        }else if(call->getCallee().value == "lcm")
        {
            if(call->getArguments().size() != 2)
            {
                throw Exception("2 arguments expected", 9);
            }

            long long left = static_cast<long long>(evaluateNode(call->getArguments()[0]));
            long long right = static_cast<long long>(evaluateNode(call->getArguments()[1]));
            return lcm(left, right);
        }else{
            throw Exception("Unknown function", 8);
        }
    }else if(e->type == ExpressionType::identifier)
    {
        std::shared_ptr<Identifier> identifier = std::dynamic_pointer_cast<Identifier>(e);

        if(identifier->getValue().value == "pi")
        {
            return static_cast<double>(PI);
        }else if(identifier->getValue().value == "e")
        {
            return static_cast<double>(E);
        }else{
            throw Exception("Unknown identifier", 9);
        }
    }

    throw Exception("Fell through function",2);
}
