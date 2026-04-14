#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include "calc_module.hpp"

using namespace std;
using namespace std::chrono;

int main() {
    // Set up a function that is slightly more computationally heavy
    // so we can really see the CPU work.
    auto f = [](REAL x) -> REAL { 
        return sin(x) + exp(-x) + (1.0 / x); 
    };

    // 1 Billion divisions to ensure a heavy workload
    long long divisions = 10000000000LL; 
    REAL a = 1.0;
    REAL b = 10.0;

    cout << fixed << setprecision(10);
    cout << "Starting Benchmark with " << divisions << " divisions..." << endl;
    cout << "---------------------------------------------------" << endl;

    // --- 1. SEQUENTIAL BENCHMARK ---
    cout << "Running Sequential Version..." << endl;
    auto start_seq = high_resolution_clock::now();
    
    REAL res_seq = compute_integral(f, a, b, divisions, false);
    
    auto end_seq = high_resolution_clock::now();
    duration<double> time_seq = end_seq - start_seq;
    cout << "Sequential Result : " << res_seq << endl;
    cout << "Sequential Time   : " << time_seq.count() << " seconds" << endl;
    cout << "---------------------------------------------------" << endl;

    // --- 2. PARALLEL BENCHMARK ---
    cout << "Running Parallel Version..." << endl;
    auto start_par = high_resolution_clock::now();
    
    REAL res_par = compute_integral(f, a, b, divisions, true);
    
    auto end_par = high_resolution_clock::now();
    duration<double> time_par = end_par - start_par;
    cout << "Parallel Result   : " << res_par << endl;
    cout << "Parallel Time     : " << time_par.count() << " seconds" << endl;
    cout << "---------------------------------------------------" << endl;

    // --- 3. ANALYSIS ---
    double speedup = time_seq.count() / time_par.count();
    cout << setprecision(2);
    cout << "Speedup Factor    : " << speedup << "x" << endl;
    
    // Quick sanity check to ensure both methods got the exact same math result
    if (abs(res_seq - res_par) > 1e-9) {
        cout << "WARNING: Results do not match! Check for race conditions." << endl;
    }

    return 0;
}