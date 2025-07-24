//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//define long data type to be used in the program
#ifndef _LONG_DEF_
#define _LONG_DEF_
typedef unsigned long ulong;
#endif

//function for generating prime number
int isprime(ulong n) {
    if (n < 2)
        return 0;
    for (ulong i = 2; i <= n / i; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

//function to get a random number
ulong randnum(ulong low, ulong high) {
    return rand() % (high - low + 1) + low;
}

//function for generating two prime numbers
void generate_primes(ulong* p, ulong* q) {
    srand(time(NULL));
    do {
        *p = randnum(100, 999);
    } while (!isprime(*p));
    do {
        *q = randnum(100, 999);
    } while (!isprime(*q) || *p == *q);
}

//function for calculating the greatest common devisor
ulong gcd(ulong a, ulong b) {
    ulong c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

//function for finding the mod inverse
ulong modinv(ulong a, ulong m) {
    ulong q, r, u1 = 1, u2 = 0, v1 = 0, v2 = 1, u, v;
    while (a != 0) {
        q = m / a;
        r = m % a;
        u = u1 - q * u2;
        v = v1 - q * v2;
        m = a;
        a = r;
        u1 = u2;
        u2 = u;
        v1 = v2;
        v2 = v;
    }
    if (m == 1)
        return u1 % m;
    else
        return 0;
}

//function for calculating the modulus
ulong mod(ulong b, ulong e, ulong m) {
    if (e == 0)
        return 1;
    ulong t = mod(b, e / 2, m);
    if (e % 2 == 0)
        return (t * t) % m;
    else
        return (((t * t) % m) * b) % m;
}

//function for generating the public and private keys
void generate_keys(ulong* p, ulong* q, ulong* n, ulong* e, ulong* d) {
    generate_primes(p, q);
    *n = (*p) * (*q);
    ulong phi = (*p - 1) * (*q - 1);
    do {
        *e = randnum(3, phi - 1);
    } while (gcd(*e, phi) != 1);
    *d = modinv(*e, phi);
}

//function for encrypting the message
ulong* encrypt(char* msg, ulong e, ulong n) {
    ulong* encrypted = (ulong*)malloc(sizeof(ulong) * strlen(msg));
    for (int i = 0; i < strlen(msg); i++) {
        encrypted[i] = mod((ulong)msg[i], e, n);
    }
    return encrypted;
}

//function for decrypting the message
char* decrypt(ulong* encrypted, int len, ulong d, ulong n) {
    char* decrypted = (char*)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        decrypted[i] = (char)mod(encrypted[i], d, n);
    }
    return decrypted;
}

int main() {
    ulong p, q, n, e, d;
    char msg[100];
    printf("Enter the message that you want to encrypt: ");
    fgets(msg, 100, stdin);

    generate_keys(&p, &q, &n, &e, &d);

    printf("Public key (e,n): (%ld,%ld)\n", e, n);
    printf("Private key (d,n): (%ld,%ld)\n", d, n);

    ulong* encrypted = encrypt(msg, e, n);
    printf("The encrypted message is: ");
    for (int i = 0; i < strlen(msg); i++) {
        printf("%ld ", encrypted[i]);
    }
    printf("\n");

    char* decrypted = decrypt(encrypted, strlen(msg), d, n);
    printf("The decrypted message is: %s", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}