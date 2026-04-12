#include "stochastic_utils.hpp"

REAL generate_random() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<REAL> dis(0.0, 1.0);
    return dis(gen);
}