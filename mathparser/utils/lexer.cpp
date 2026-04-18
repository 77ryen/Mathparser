#include "lexer.hpp"

Lexer::Lexer(std::string expr){
    expression = expr;
    position = 0;
}

Token Lexer::parse_number(){

    std::string token_value;

    while(position < expression.length() && (
        isdigit(expression[position]) || expression[position] == '.'
    )){
        token_value += expression[position++];
    }

    return {TokenType::NUMBER, token_value};

}

Token Lexer::parse_identifier(){

    std::string token_value;

    while(position < expression.length() &&
        isalpha(expression[position])){
            token_value += expression[position++];
    }

    if(token_value == "x") {
        return {TokenType::VARIABLE, token_value};
    }

    return {TokenType::FUNCTION, token_value};
}

std::vector<Token> Lexer::tokenize(){

    std::vector<Token> tokenized_expression;

    while(position < expression.length()){

        char current = expression[position];

        if(isspace(current)){
            position++;
        } else if(isdigit(current)){
            tokenized_expression.push_back(parse_number());
        } else if(isalpha(current)){
            tokenized_expression.push_back(parse_identifier());
        } else if(current == '+'){
            tokenized_expression.push_back({TokenType::PLUS, "+"});
            position++;
        } else if(current == '-'){
            tokenized_expression.push_back({TokenType::MINUS, "-"});
            position++;
        } else if(current == '*'){
            tokenized_expression.push_back({TokenType::MUL, "*"});
            position++;
        } else if(current == '/'){
            tokenized_expression.push_back({TokenType::DIV, "/"});
            position++;
        } else if(current == '^'){
            tokenized_expression.push_back({TokenType::POWER, "^"});
            position++;
        } else if(current == '('){
            tokenized_expression.push_back({TokenType::LEFT_PAR, "("});
            position++;
        } else if(current == ')'){
            tokenized_expression.push_back({TokenType::RIGHT_PAR, ")"});
            position++;
        } else {
            position++;
        }
    }

    tokenized_expression.push_back({TokenType::EOS, ""});
    return tokenized_expression;
}