#include "../headers/astEvaluator.h"
#include <cmath>

double ASTEvaluator::evaluateNode(ASTNode* node)
{

    if(node->getOperation() == ASTOperation::ast_add)
    {
        return evaluateNode(node->getLeft()) + evaluateNode(node->getRight());
    }else if(node->getOperation() == ASTOperation::ast_mul)
    {
        return evaluateNode(node->getLeft()) * evaluateNode(node->getRight());
    }else if(node->getOperation() == ASTOperation::ast_sub)
    {
        return evaluateNode(node->getLeft()) - evaluateNode(node->getRight());
    }else if(node->getOperation() == ASTOperation::ast_div)
    {
        double left = evaluateNode(node->getLeft());
        if(fabs(left) == 0)
        {
            throw ASTException("Can't divide zero",1);
        }
        return evaluateNode(node->getLeft()) / evaluateNode(node->getRight());
    }else{
        if(node->getHasValue())
        {
            return node->getValue();
        }
    }

    throw ASTException("Fell through function",2);
}


namespace ASTEvaluator {
    ASTException::ASTException(const std::string& d, const int& c) : std::exception ()
    {
        description = d;
        code = c;
    }
}
