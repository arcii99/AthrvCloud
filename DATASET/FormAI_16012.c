//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Generate random prime number */
int prime_generator() {
    int num;

    /* Seed random number generator */
    srand(time(NULL));

    /* Loop until prime number is generated */
    while (1) {
        num = rand() % 100 + 1;
        int i;
        for (i = 2; i < num; i++) {
            if (num % i == 0) {
                break;
            }
        }
        if (i == num) {
            return num;
        }
    }
}

/* Generate public and private keys */
void key_generator() {
    int p, q, n, phi_n, e, d;

    /* Generate two different prime numbers */
    p = prime_generator();
    q = prime_generator();
    while (p == q) {
        q = prime_generator();
    }

    /* Calculate n and phi(n) */
    n = p * q;
    phi_n = (p - 1) * (q - 1);

    /* Choose a random integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1 */
    srand(time(NULL));
    do {
        e = rand() % phi_n + 1;
    } while (gcd(e, phi_n) != 1);

    /* Calculate d using modular multiplicative inverse */
    d = inverse(e, phi_n);

    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d, n): (%d, %d)\n", d, n);
}

/* Calculate greatest common divisor */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/* Calculate modular multiplicative inverse */
int inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    /* Apply extended Euclid Algorithm */
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    /* Make x1 positive */
    if (x1 < 0) {
        x1 += m0;
    }
    return x1;
}

int main() {
    key_generator();
    return 0;
}