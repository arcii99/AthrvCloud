//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Generates a random prime number between 2 and max
int generate_prime(int max) {
    int num;
    int is_prime = 0;
    // keep generating random numbers until a prime is found
    while (!is_prime) {
        num = (rand() % (max - 2)) + 2;
        is_prime = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }
    return num;
}

// Calculates the greatest common divisor using Euclid's algorithm
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Finds the modular inverse of a using the extended Euclidean algorithm
int mod_inv(int a, int m) {
    int m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

// Generates public and private keys based on given input
void gen_keys(int p, int q) {
    int n = p * q; // calculate n
    int phi = (p - 1) * (q - 1); // calculate phi(n)
    int e;
    // find a random number between 1 and phi-1 that is coprime to phi
    do {
        e = (rand() % (phi - 1)) + 1;
    } while (gcd(e, phi) != 1);
    int d = mod_inv(e, phi); // calculate private key
    printf("Public key: (%d, %d)\nPrivate key: (%d, %d)\n", e, n, d, n);
}

int main() {
    // seed random number generator with current time
    srand(time(NULL));
    int p = generate_prime(100);
    int q = generate_prime(100);
    // ensure p and q are different
    while (q == p) {
        q = generate_prime(100);
    }
    gen_keys(p, q);
    return 0;
}