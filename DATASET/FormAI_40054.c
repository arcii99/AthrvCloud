//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int e; // Public Key
    int d; // Private Key
    int n; // Modulus
} KeyPair;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) {
        x1 += m0;
    }
    return x1;
}

int is_prime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generate_prime(int min, int max) {
    int p, flag;
    do {
        p = rand() % (max - min + 1) + min;
        flag = is_prime(p);
    } while (flag == 0);
    return p;
}

int generate_coprime(int n) {
    int i, a;
    for (i = 2; i < n; i++) {
        if (gcd(i, n) == 1) {
            return i;
        }
    }
    return -1;
}

KeyPair generate_keypair(int p, int q) {
    KeyPair pair;
    pair.n = p * q;
    int phi = (p - 1) * (q - 1);

    pair.e = generate_coprime(phi);
    pair.d = mod_inverse(pair.e, phi);

    return pair;
}

int main() {
    int p = generate_prime(100, 200);
    int q = generate_prime(200, 300);

    KeyPair keys = generate_keypair(p, q);

    printf("Public Key: %d\n", keys.e);
    printf("Private Key: %d\n", keys.d);
    printf("Modulus: %d\n", keys.n);

    return 0;
}