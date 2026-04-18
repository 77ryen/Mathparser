#pragma once
#include<string>
#include<vector>
#include<ostream>

enum class TokenType{
    NUMBER,
    VARIABLE,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LEFT_PAR,
    RIGHT_PAR,
    POWER,
    FUNCTION,
    EOS
};

struct Token{
    TokenType type;
    std::string token_value;
};

std::ostream& operator<<(std::ostream& os, const Token& token);