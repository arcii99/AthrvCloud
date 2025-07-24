//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    int i;
    for (i = 2; i < sqrt(num) + 1; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int generate_prime() {
    int prime;
    do {
        prime = rand() % 100;
    } while (!is_prime(prime));
    return prime;
}

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void generate_keys(int *e, int *n, int *d) {
    srand(time(NULL));
    int p = generate_prime();
    int q = generate_prime();
    while (p == q) {
        q = generate_prime();
    }
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    *e = 2;
    while (gcd(*e, phi) != 1) {
        *e = rand() % (phi - 1) + 1;
    }
    int k = 1;
    while (1) {
        *d = (1 + (k * phi)) / *e;
        if ((*d) * (*e) == 1 + (k * phi)) {
            break;
        }
        k++;
    }
}

int main() {
    int e, n, d;
    generate_keys(&e, &n, &d);
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: %d\n", d);

    return 0;
}