#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include "calc_module.hpp"
#include "lexer.hpp"

using namespace std;
using namespace std::chrono;

std::ostream& operator<<(std::ostream& os, const vector<Token>& vect){
    os << "[";
    for(int i = 0; i < vect.size(); i++) {
        os << vect[i] << ", ";
    }
    os << "]";
    return os;
}

int main() {
    
    string exp;

    cin >> exp;

    Lexer expr = Lexer(exp);

    cout << expr.tokenize();

    return 0;
}