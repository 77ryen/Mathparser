#include "tokens.hpp"

class Lexer {

public:

    std::string expression;
    size_t position;

    Lexer(std::string expr);
    Token parse_number();
    Token parse_identifier();
    std::vector<Token> tokenize();

};