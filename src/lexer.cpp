#include "../headers/lexer.h"

Lexer::Lexer()
{

}

Lexer::Lexer(const std::string& equation)
{
    str = equation;
}

void Lexer::setEquation(const std::string& equation)
{
    str = equation;
}

void Lexer::parse()
{
    index = 0;

    for(;index < str.size(); index++)
    {
        char ch = str[index];
        switch (ch)
        {
        case '*':
            tokens.push_back(Token(TokenType::tok_mul, "*"));
            break;
        case '+':
            tokens.push_back(Token(TokenType::tok_add, "+"));
            break;
        case '-':
            tokens.push_back(Token(TokenType::tok_sub, "-"));
            break;
        case '/':
            tokens.push_back(Token(TokenType::tok_div, "/"));
            break;
        case '(':
            tokens.push_back(Token(TokenType::tok_lParen, "("));
            break;
        case ')':
            tokens.push_back(Token(TokenType::tok_rParen, ")"));
            break;
        case ' ':
        case '\r':
        case '\t':
            continue;
        default:
            if(isdigit(ch))
            {
                tokens.push_back(handleNumber());
            }else{
                //Throw
            }
            break;
        }
    }

    tokens.push_back(Token(TokenType::tok_eof,""));
}

Token Lexer::handleNumber()
{
    std::string value = "";
    while(isdigit(str[index]) && index < str.size())
    {
        value += str[index];
        index++;
    }

    if(index == str.size())
    {
        return Token(TokenType::tok_number, value);
    }

    if(str[index] == '.')
    {
        value += str[index];
        index++;

        while(isdigit(str[index]) && index < str.size())
        {
            value += str[index];
            index++;
        }
    }

    index--; // We do this because otherwise in the above loops we advance too far
    return Token(TokenType::tok_number, value);
}

std::vector<Token> Lexer::getTokens()
{
    return tokens;
}
