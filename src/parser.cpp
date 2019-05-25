#include "../headers/parser.h"
#include "../headers/literal.h"
#include "../headers/grouping.h"
#include "../headers/binary.h"
#include "../headers/unary.h"
#include "../headers/exception.h"
#include <memory>

Parser::Parser(const std::vector<Token>& tk)
{
    tokens = tk;
}

std::shared_ptr<Expression> Parser::parse()
{
    index = 0; // Reset
    try {
        return handleExpression();
    } catch (const Exception) {
        throw; // Pass through any errors
    }
}

std::shared_ptr<Expression> Parser::handleExpression()
{
    return handleAddition();
}


std::shared_ptr<Expression> Parser::handleAddition()
{
    std::shared_ptr<Expression> left = handleMultiplication();

    while(match({tok_sub, tok_add}))
    {
        // Get the operator. Match advances
        Token op = previousToken();
        std::shared_ptr<Expression> right = handleMultiplication();
        return std::shared_ptr<Expression>(new Binary(left, op, right));
    }

    return left;
}

std::shared_ptr<Expression> Parser::handleExponent()
{
    std::shared_ptr<Expression> left = handleUnary();

    while(match({tok_exp}))
    {
        // Get the operator. Match advances
        Token op = previousToken();
        std::shared_ptr<Expression> right = handleUnary();
        return std::shared_ptr<Expression>(new Binary(left, op, right));
    }

    return left;
}

std::shared_ptr<Expression> Parser::handleMultiplication()
{
    std::shared_ptr<Expression> left = handleExponent();

    while(match({tok_div, tok_mul}))
    {
        // Get the operator. Match advances
        Token op = previousToken();
        std::shared_ptr<Expression> right = handleExponent();
        return std::shared_ptr<Expression>(new Binary(left, op, right));
    }

    return left;
}

std::shared_ptr<Expression> Parser::handleUnary()
{
    if(match({tok_sub}))
    {
        Token op = previousToken();
        std::shared_ptr<Expression> right = handleUnary();
        return std::shared_ptr<Expression>(new Unary(op, right));
    }

    return handlePrimary();
}

std::shared_ptr<Expression> Parser::handlePrimary()
{
    if(match({tok_number}))
    {
        return std::shared_ptr<Expression>(new Literal(previousToken().value));
    }

    if(match({tok_lParen}))
    {
        std::shared_ptr<Expression> expr = handleExpression();
        consume(tok_rParen, "Expect ')' after expression.");
        return std::shared_ptr<Expression>(new Grouping(expr));
    }

    throw Exception("Unknown primary", 5);
}

bool Parser::isAtEnd()
{
    return currentToken().type == tok_eof;
}

Token Parser::currentToken()
{
    return tokens.at(index);
}

Token Parser::previousToken()
{
    return tokens.at(index - 1);
}

Token Parser::advance()
{
    if (!isAtEnd())
    {
        index++;
    }

    return previousToken();
}

bool Parser::match(std::vector<TokenType> types)
{
    for(TokenType type : types)
    {
        if(check(type))
        {
            advance();
            return true;
        }
    }

    return false;
}

bool Parser::check(TokenType type)
{
    if (isAtEnd())
    {
        return false;
    }

    return currentToken().type == type;
}

Token Parser::consume(TokenType type, const std::string& errMessage)
{
    if(check(type))
    {
        return advance();
    }

    throw Exception(errMessage, 4);
}
