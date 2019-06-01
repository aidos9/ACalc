#include "../headers/lexer.h"
#include "../headers/exception.h"
#include "../headers/tokenType.h"
#define CATCH_CONFIG_MAIN
#include "../libs/catch.hpp"

static std::string test1 = "sin(4)";
static std::string test2 = "cos(4 * (3-2))";
static std::string test3 = "5^(4%3) / 2";
static std::string test4 = "sin(pi)";
static std::string test5 = "log(e,2*e)";

TEST_CASE("Test 1","[test1]")
{
    Lexer lx = Lexer(test1);
    try {
         lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> results = lx.getTokens();
    std::vector<TokenType> expectedTypes = {tok_call, tok_lParen, tok_number, tok_rParen, tok_eof};

    REQUIRE(expectedTypes.size() == results.size());

    for(size_t i = 0; i < results.size(); i++)
    {
        REQUIRE(expectedTypes[i] == results[i].type);
    }
}

TEST_CASE("Test 2","[test2]")
{
    Lexer lx = Lexer(test2);
    try {
         lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> results = lx.getTokens();
    std::vector<TokenType> expectedTypes = {tok_call, tok_lParen, tok_number, tok_mul, tok_lParen, tok_number, tok_sub, tok_number, tok_rParen, tok_rParen, tok_eof};

    REQUIRE(expectedTypes.size() == results.size());

    for(size_t i = 0; i < results.size(); i++)
    {
        REQUIRE(expectedTypes[i] == results[i].type);
    }
}

TEST_CASE("Test 3","[test3]")
{
    Lexer lx = Lexer(test3);
    try {
         lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> results = lx.getTokens();
    std::vector<TokenType> expectedTypes = {tok_number, tok_exp, tok_lParen, tok_number, tok_mod, tok_number, tok_rParen, tok_div, tok_number, tok_eof};

    REQUIRE(expectedTypes.size() == results.size());

    for(size_t i = 0; i < results.size(); i++)
    {
        REQUIRE(expectedTypes[i] == results[i].type);
    }
}

TEST_CASE("Test 4","[test4]")
{
    Lexer lx = Lexer(test4);
    try {
         lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> results = lx.getTokens();
    std::vector<TokenType> expectedTypes = {tok_call, tok_lParen, tok_identifier, tok_rParen, tok_eof};

    REQUIRE(expectedTypes.size() == results.size());

    for(size_t i = 0; i < results.size(); i++)
    {
        REQUIRE(expectedTypes[i] == results[i].type);
    }
}

TEST_CASE("Test 5","[test5]")
{
    Lexer lx = Lexer(test5);
    try {
         lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> results = lx.getTokens();
    std::vector<TokenType> expectedTypes = {tok_call, tok_lParen, tok_identifier, tok_comma, tok_number, tok_mul, tok_identifier, tok_rParen,tok_eof};

    REQUIRE(expectedTypes.size() == results.size());

    for(size_t i = 0; i < results.size(); i++)
    {
        REQUIRE(expectedTypes[i] == results[i].type);
    }
}
