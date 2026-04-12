#include "calc_module.hpp"
#include "stochastic_utils.hpp"
#include<math.h>
#include<random>
#include<stdexcept>

REAL_FUNCTION differentiate(REAL_FUNCTION funct, REAL h){

    return [h, funct](REAL a) -> REAL {

        return (funct(a + h) - funct(a - h))/(2 * h);

    };
}

REAL _find_roots_simple(REAL_FUNCTION funct,
    REAL a, 
    REAL b,
    REAL precision,
    long long maximum_number_of_iterations){

    auto f_prime = differentiate(funct);

    REAL root = (a + b)/2;

    for(int i = 0; i < maximum_number_of_iterations; i++){

        REAL deriviative_at_root = f_prime(root);

        if(abs(deriviative_at_root) < 10e-10){
            REAL t = generate_random();
            root = a * t + (1 - t) * b;
            continue;
        }

        REAL next_root_iteration = root - funct(root)/deriviative_at_root;

        if(abs(root - next_root_iteration) < precision){
            return next_root_iteration;
        }

        root = next_root_iteration;

    }

    throw std::logic_error("Number of iterations exceeded without achieving desired precision.
        Maybe too few iterations or the function does not have roots?");

}

REAL compute_integral(REAL_FUNCTION funct, REAL a, REAL b, long long number_of_divisions){

    REAL h = (b - a) / number_of_divisions;

    REAL sum = 0;

    sum += (funct(b) + funct(a))/2;

    for(int i = 1; i < number_of_divisions; i++){

        sum += funct(a + (i*h));

    }

    sum *= h;

    return sum;
}