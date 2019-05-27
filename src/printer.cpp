#include "../headers/printer.h"
#include "../headers/expressions.h"
#include <memory>

Printer::Printer()
{

}

void Printer::printNode(const std::shared_ptr<Expression> e)
{
    if(e->type == ExpressionType::lit)
    {
        std::shared_ptr<Literal> literal = std::dynamic_pointer_cast<Literal>(e);
        ss << literal->getValue();
    }else if(e->type == ExpressionType::bin)
    {
        std::shared_ptr<Binary> binary = std::dynamic_pointer_cast<Binary>(e);
        printNode(binary->getLeft());
        ss << binary->getOp().value;
        printNode(binary->getRight());
    }else if(e->type == ExpressionType::grp)
    {
        std::shared_ptr<Grouping> grouping = std::dynamic_pointer_cast<Grouping>(e);
        ss << "(";
        printNode(grouping->getExpression());
        ss << ")";
    }else if(e->type == ExpressionType::call)
    {
        std::shared_ptr<Call> call = std::dynamic_pointer_cast<Call>(e);
        ss << call->getCallee().value << "(";

        for(size_t i = 0; i< call->getArguments().size(); i++)
        {
            printNode(call->getArguments()[i]);

            if(i != call->getArguments().size()-1)
            {
                ss << ",";
            }
        }

        ss << ")";
    }
}

std::string Printer::printTree(const std::shared_ptr<Expression> e)
{
    ss = std::stringstream();
    printNode(e);
    return ss.str();
}
