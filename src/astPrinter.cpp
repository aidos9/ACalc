#include "../headers/astPrinter.h"
#include "../headers/expressions.h"
#include <memory>

ASTPrinter::ASTPrinter()
{
    ss = std::stringstream();
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
