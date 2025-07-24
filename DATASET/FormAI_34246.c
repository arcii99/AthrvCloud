//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRIME_RANGE 100

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int is_prime(int n) {
    if (n <= 1) return 0;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}

int generate_prime() {
    int prime, flag = 0;

    while (!flag) {
        prime = rand() % PRIME_RANGE;
        if (is_prime(prime)) flag = 1;
    }

    return prime;
}

int main() {
    srand(time(NULL));

    int p = generate_prime();
    int q = generate_prime();
    int n = p*q;
    int phi_n = (p-1)*(q-1);

    int e = 2;
    while (e < phi_n) {
        if (gcd(e, phi_n) == 1) break;
        else e++;
    }

    int d, k = 1;
    while (1) {
        k += phi_n;
        if (k % e == 0) {
            d = k / e;
            break;
        }
    }

    printf("Public Key (e, n): (%d, %d)\nPrivate Key (d, n): (%d, %d)\n", e, n, d, n);

    return 0;
}