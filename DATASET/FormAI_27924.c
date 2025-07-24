//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PRIME_UPPER_BOUND 1000
#define KEY_SIZE 128

// function to check if a number is prime or not
int is_prime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    for (i=2; i<=sqrt(n); i++) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to generate a random prime number less than n
int generate_prime(int n) {
    int p, i;
    do {
        p = rand() % n;
    } while (is_prime(p) == 0);
    return p;
}

// function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int p, q, n, phi_n, e=3, d, i;
    do {
        p = generate_prime(PRIME_UPPER_BOUND);
        q = generate_prime(PRIME_UPPER_BOUND);
        n = p * q;
        phi_n = (p-1) * (q-1);
    } while (n < KEY_SIZE || phi_n < KEY_SIZE);

    // calculate public key (e, n)
    *public_key = n;

    // calculate private key (d)
    while (1) {
        if ((e*d) % phi_n == 1) {
            break;
        }
        d++;
    }
    *private_key = d;
}

// main function
int main() {
    int public_key, private_key, i;
    srand(time(0));
    generate_keys(&public_key, &private_key);

    printf("public key: %d\n", public_key);
    printf("private key: %d\n", private_key);

    return 0;
}