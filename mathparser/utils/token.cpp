#include "tokens.hpp"

std::ostream& operator<<(std::ostream& os, const Token& token){

    std::string string_token;

    switch (token.type){
        case TokenType::NUMBER:
            string_token = "NUMBER{" + token.token_value + "}";
            break;

        case TokenType::VARIABLE:
            string_token = "VARIABLE{" + token.token_value + "}";
            break;

        case TokenType::PLUS:
            string_token = "PLUS{" + token.token_value + "}";
            break;

        case TokenType::MINUS:
            string_token = "MINUS{" + token.token_value + "}";
            break;

        case TokenType::MUL:
            string_token = "MULTIPLY{" + token.token_value + "}";
            break;

        case TokenType::DIV:
            string_token = "DIVIDE{" + token.token_value + "}";
            break;

        case TokenType::LEFT_PAR:
            string_token = "LEFT_PARENTHESIS{" + token.token_value + "}";
            break;

        case TokenType::RIGHT_PAR:
            string_token = "RIGHT_PARENTHESIS{" + token.token_value + "}";
            break;
        case TokenType::POWER:
            string_token = "POWER{" + token.token_value + "}";
            break;
        case TokenType::FUNCTION:
            string_token = "FUNCTION{" + token.token_value + "}";
            break;
        case TokenType::EOS:
            string_token = "END_OF_STRING{" + token.token_value + "}";
            break;
    }

    os << string_token;

    return os;
}
