#include "../headers/parser.h"
#include "../headers/expressions.h"
#include "../headers/exception.h"
#include <memory>

Parser::Parser(const std::vector<Token>& tk)
{
    tokens = tk;
}

void Parser::setTokens(const std::vector<Token>& tk)
{
    tokens = tk;
    index = 0;
}

std::shared_ptr<Expression> Parser::parse()
{
    index = 0; // Reset
    try {
        return handleExpression();
    } catch (const Exception&) {
        throw; // Pass through any errors
    }
}

std::shared_ptr<Expression> Parser::handleExpression()
{
    try {
        return handleAddition();
    } catch (const Exception&) {
        throw;
    }
}

std::shared_ptr<Expression> Parser::handleAddition()
{
    try{
        std::shared_ptr<Expression> left = handleMultiplication();

        while(match({tok_sub, tok_add}))
        {
            // Get the operator. Match advances
            Token op = previousToken();
            std::shared_ptr<Expression> right = handleMultiplication();

            left = std::shared_ptr<Expression>(new Binary(left, op, right)); // We are returning but the next token is still an addition
        }

        return left;
    }catch(const Exception&){
        throw;
    }
}

std::shared_ptr<Expression> Parser::handleMultiplication()
{
    try {
        std::shared_ptr<Expression> left = handleExponent();

        while(match({tok_div, tok_mul, tok_mod}))
        {
            // Get the operator. Match advances
            Token op = previousToken();
            std::shared_ptr<Expression> right = handleExponent();
            left = std::shared_ptr<Expression>(new Binary(left, op, right));
        }

        return left;
    }catch(const Exception&) {
        throw;
    }
}

std::shared_ptr<Expression> Parser::handleExponent()
{
    try{
        std::shared_ptr<Expression> left = handleUnary();

        while(match({tok_exp}))
        {
            // Get the operator. Match advances
            Token op = previousToken();
            std::shared_ptr<Expression> right = handleUnary();
            left = std::shared_ptr<Expression>(new Binary(left, op, right));
        }

        return left;
    }catch(const Exception&) {
        throw;
    }
}


std::shared_ptr<Expression> Parser::handleUnary()
{
    try {
        if(match({tok_sub}))
        {
            Token op = previousToken();
            std::shared_ptr<Expression> right = handleUnary();
            return std::shared_ptr<Expression>(new Unary(op, right));
        }

        return handleIdentifier();
    } catch (const Exception&) {
        throw;
    }
}

std::shared_ptr<Expression> Parser::handleIdentifier()
{
    if(match({tok_identifier}))
    {
        Token name = previousToken();

        try {
            consume(tok_lParen, "Expected '(' to open an identifier");
        }  catch (const Exception&) {
            throw;
        }


        std::vector<std::shared_ptr<Expression>> args;
        try {
            args.push_back(handleExpression());
        } catch (const Exception&) {
            throw;
        }

        while(match({tok_comma})){
            try {
                args.push_back(handleExpression());
            } catch (const Exception&) {
                throw;
            }
        }

        if(isAtEnd())
        {
            throw Exception("No closing ')' found",7);
        }

        try {
            consume(tok_rParen, "Expected ')' to close an identifier");
        }catch (const Exception&) {
            throw;
        }

        return std::shared_ptr<Expression>(new Call(name, args));
    }

    try {
        return handlePrimary();
    } catch (const Exception&) {
        throw;
    }
}

std::shared_ptr<Expression> Parser::handlePrimary()
{
    if(match({tok_number}))
    {
        return std::shared_ptr<Expression>(new Literal(previousToken().value));
    }

    if(match({tok_lParen}))
    {
        try {
            std::shared_ptr<Expression> expr = handleExpression();
            consume(tok_rParen, "Expect ')' after expression.");
            return std::shared_ptr<Expression>(new Grouping(expr));
        } catch (const Exception&) {
            throw;
        }
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
