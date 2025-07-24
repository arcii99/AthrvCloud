//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function to determine if a number is prime
int is_prime(int n) {
    int i;
    for (i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// function to generate a large prime number
int generate_prime() {
    int n = rand() % 100 + 100;
    while (!is_prime(n)) n++;
    return n;
}

// function to calculate the modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return res;
}

// function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// function to calculate the modular inverse
int mod_inv(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

int main() {
    srand(time(NULL));
    int p = generate_prime();
    int q = generate_prime();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = rand() % phi;
    while (gcd(e, phi) != 1) e = rand() % phi;
    int d = mod_inv(e, phi);
    int m, c;
    printf("Enter a message to encrypt: ");
    scanf("%d", &m);
    c = mod_exp(m, e, n);
    printf("The ciphertext is %d\n", c);
    m = mod_exp(c, d, n);
    printf("The decrypted message is %d\n", m);
    return 0;
}