#include "../headers/astPrinter.h"
#include "../headers/expressions.h"
#include <memory>

ASTPrinter::ASTPrinter()
{
    ss = std::stringstream();
}

void ASTPrinter::printNode(const ASTNode* n)
{
    if(n->getOperation() == ASTOperation::ast_none)
    {
        ss << n->getValue();
    }else if(n->getOperation() == ASTOperation::ast_div)
    {
        printNode(n->getLeft());
        ss << " / ";
        printNode(n->getRight());
    }else if(n->getOperation() == ASTOperation::ast_mul)
    {
        printNode(n->getLeft());
        ss << " * ";
        printNode(n->getRight());
    }else if(n->getOperation() == ASTOperation::ast_add)
    {
        ss << "(";
        printNode(n->getLeft());
        ss << " + ";
        printNode(n->getRight());
        ss << ")"; // Add these brackets because divide/multiply symbols on the outside would be evaluated first otherwise when printed
    }else if(n->getOperation() == ASTOperation::ast_sub)
    {
        ss << "(";
        printNode(n->getLeft());
        ss << " - ";
        printNode(n->getRight());
        ss << ")"; // Add these brackets because divide/multiply symbols on the outside would be evaluated first otherwise when printed
    }
}

void ASTPrinter::printNode(const std::shared_ptr<Expression> e)
{
    if(e->type == ExpressionType::lit)
    {
        std::shared_ptr<Literal> literal = std::dynamic_pointer_cast<Literal>(e);
        ss << literal->getValue();
    }else if(e->type == ExpressionType::bin)
    {
        std::shared_ptr<Binary> binary = std::dynamic_pointer_cast<Binary>(e);
        printNode(binary->getLeft());
        ss << " " << binary->getOp().value << " ";
        printNode(binary->getRight());
    }else if(e->type == ExpressionType::grp)
    {
        std::shared_ptr<Grouping> grouping = std::dynamic_pointer_cast<Grouping>(e);
        ss << " ( ";
        printNode(grouping->getExpression());
        ss << " ) ";
    }
}

std::string ASTPrinter::printTree(const std::shared_ptr<Expression> e)
{
    ss.clear();
    printNode(e);
    return ss.str();
}

std::string ASTPrinter::printTree(const ASTNode* n)
{
    ss.clear();
    printNode(n);
    return ss.str();
}
