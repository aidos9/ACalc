#ifndef PARSER_H
#define PARSER_H

#include "expression.h"
#include "token.h"
#include <vector>
#include <memory>

class Parser
{
public:
    Parser(const std::vector<Token>& tk);
    void setTokens(const std::vector<Token>& tk);

    std::shared_ptr<Expression> parse();

private:
    std::shared_ptr<Expression> handleCall();
    std::shared_ptr<Expression> handleExpression();
    std::shared_ptr<Expression> handleAddition();
    std::shared_ptr<Expression> handleMultiplication();
    std::shared_ptr<Expression> handleExponent();
    std::shared_ptr<Expression> handleUnary();
    std::shared_ptr<Expression> handlePrimary();

    bool check(TokenType type);
    bool match(std::vector<TokenType> types);
    bool isAtEnd();
    Token currentToken();
    Token previousToken();
    Token advance();
    Token consume(TokenType type, const std::string& errMessage);

    std::vector<Token> tokens;
    size_t index = 0;
};

#endif // PARSER_H
