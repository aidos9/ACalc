#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception
{
public:
    Exception(const std::string& d, const int& c);

    std::string getDescription() const;
    int getCode() const;

private:
    int code;
    std::string description;
};

#endif // EXCEPTION_H
