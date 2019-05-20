#include "../headers/astNode.h"

ASTNode::ASTNode(const ASTOperation& o, const double& v, ASTNode* l, ASTNode* r)
{
    hasValue = true;
    op = o;
    value = v;
    left = l;
    right = r;
}
ASTNode::ASTNode(const ASTOperation& o, ASTNode* l, ASTNode* r)
{
    op = o;
    left = l;
    right = r;
}

ASTOperation ASTNode::getOperation() const
{
    return op;
}

double ASTNode::getValue() const
{
    return value;
}

ASTNode* ASTNode::getLeft() const
{
    return left;
}

ASTNode* ASTNode::getRight() const
{
    return right;
}

bool ASTNode::getHasValue() const
{
    return hasValue;
}
