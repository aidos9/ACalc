#include "../headers/exception.h"

Exception::Exception(const std::string& d, const int& c)
{
    description = d;
    code = c;
}

std::string Exception::getDescription() const
{
    return description;
}

int Exception::getCode() const
{
    return code;
}
