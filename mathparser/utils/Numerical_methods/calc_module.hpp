#pragma once
#include<functional>
#include<vector>
#include "macros_and_constants.hpp"

REAL_FUNCTION differentiate(REAL_FUNCTION funct, REAL h = 10e-5);

REAL compute_integral(REAL_FUNCTION, REAL, REAL, long long);

std::vector<REAL> find_roots(REAL_FUNCTION, REAL, REAL);

REAL _find_roots_simple(REAL_FUNCTION funct, REAL a, REAL b, REAL precision = 10e-5, long long maximum_number_of_iterations = 1000);
