//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

// The program uses bitwise operators to compute modular arithmetic
// Specifically, it computes the result of (a^b) mod m, where a, b, and m are integers

// Function that computes (a^b) mod m using bitwise operations
unsigned long long modular_pow(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 1;
    while(exponent > 0) {
        // If exponent is odd, multiply base with result
        if((exponent & 1) == 1) {
            result = (result * base) % modulus;
        }
        // Shift exponent to right by one, equivalent to integer division by 2
        exponent >>= 1;
        // Square base and take modulus with m
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    // Input values for a, b, and m
    unsigned long long a = 7;
    unsigned long long b = 123456789123456789ull;
    unsigned long long m = 1000000000ull;

    // Compute (a^b) mod m using bitwise operations
    unsigned long long result = modular_pow(a, b, m);

    // Output the result
    printf("(%llu^%llu) mod %llu = %llu\n", a, b, m, result);

    return 0;
}