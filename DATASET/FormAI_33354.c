//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Fast modular exponentiation function
int fast_mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Check if a number is prime
int is_prime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Generate a prime number
int generate_prime(int min, int max) {
    int num = rand() % (max - min + 1) + min;
    while (!is_prime(num)) {
        num = rand() % (max - min + 1) + min;
    }
    return num;
}

// Generate keys
void generate_keys(int *p, int *q, int *n, int *e, int *d) {
    srand(time(NULL));
    *p = generate_prime(100, 499);
    *q = generate_prime(500, 999);
    *n = *p * *q;
    int phi = (*p - 1) * (*q - 1);
    *e = generate_prime(2, phi - 1);
    while (fast_mod_exp(*e, 1, phi) != 1) {
        *e = generate_prime(2, phi - 1);
    }
    int k = 0;
    while (1) {
        k++;
        *d = (1 + k * phi) / (*e);
        if (fast_mod_exp(*e, 1, phi) == 1 && fast_mod_exp(*e * *d, 1, phi) == 1 &&
            *d != *e && *d > 0) {
            break;
        }
    }
}

int main() {
    int p, q, n, e, d;
    generate_keys(&p, &q, &n, &e, &d);
    printf("Public Key: {n=%d, e=%d}\n", n, e);
    printf("Private Key: {p=%d, q=%d, d=%d}\n", p, q, d);
    return 0;
}