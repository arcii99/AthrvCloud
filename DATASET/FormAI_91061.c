//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef unsigned long long int uint64_t;
typedef unsigned int uint32_t;
typedef unsigned char uchar;

// Generate a random number in range [min, max]
uint32_t generate_random(uint32_t min, uint32_t max) {
    return (rand() % (max - min + 1)) + min;
}

// Find the greatest common divisor of two numbers
uint64_t gcd(uint64_t a, uint64_t b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

// Find a prime number in range [min, max]
uint32_t generate_prime(uint32_t min, uint32_t max) {
    uint32_t num;
    bool is_prime;

    do {
        num = generate_random(min, max);
        is_prime = true;
        for(uint32_t i = 2; i <= sqrt(num); i++) {
            if(num % i == 0) {
                is_prime = false;
                break;
            }
        }
    } while(!is_prime);

    return num;
}

// Modular exponentiation function: (a^b) mod m
uint64_t mod_pow(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t res = 1;
    while(b > 0) {
        if(b & 1) // If b is odd
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1; // Right-shift b to divide it by 2
    }
    return res;
}

// Check whether the given number is prime or not
bool is_prime(uint64_t num) {
    if(num <= 1)
        return false;
    if(num <= 3)
        return true;
    if(num % 2 == 0 || num % 3 == 0)
        return false;

    for(uint64_t i = 5; i * i <= num; i += 6) {
        if(num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

// Find the multiplicative inverse of e mod phi(n)
uint64_t mod_inverse(uint64_t e, uint64_t phi) {
    // Extended Euclidean algorithm
    uint64_t t, q;
    uint64_t r1 = e, r2 = phi;
    uint64_t s1 = 1, s2 = 0;

    while(r2 > 0) {
        q = r1 / r2;
        t = r1 - q * r2; r1 = r2; r2 = t;
        t = s1 - q * s2; s1 = s2; s2 = t;
    }

    if(s1 < 0)
        s1 += phi;

    return s1;
}

// Generate a public and private key pair for RSA algorithm
void RSA_generate_keypair(uint64_t *e, uint64_t *d, uint64_t *n) {
    uint32_t p, q;
    uint64_t phi;

    // Generate two random prime numbers
    srand(time(NULL));
    p = generate_prime(1000, 9999);
    q = generate_prime(1000, 9999);

    // Calculate n = p * q
    *n = p * q;

    // Calculate phi(n) = (p - 1) * (q - 1)
    phi = (p - 1) * (q - 1);

    // Choose a random number e such that 1 < e < phi and gcd(e, phi) = 1
    do {
        *e = generate_random(2, phi - 1);
    } while(gcd(*e, phi) != 1);

    // Calculate the private key d such that (d * e) mod phi(n) = 1
    *d = mod_inverse(*e, phi);
}

int main() {
    uint64_t e, d, n;
    uchar message[1000];
    uint64_t encrypted[1000];
    uint64_t decrypted[1000];
    uint32_t len;

    RSA_generate_keypair(&e, &d, &n);

    printf("Public Key (e, n): (%llu, %llu)\n", e, n);
    printf("Private Key (d, n): (%llu, %llu)\n", d, n);

    printf("Enter the message to encrypt:\n");
    scanf("%s", message);

    len = strlen(message);

    for(uint32_t i = 0; i < len; i++) {
        // Encrypt each character of the message
        encrypted[i] = mod_pow(message[i], e, n);
    }

    printf("Encrypted message:\n");
    for(uint32_t i = 0; i < len; i++) {
        printf("%llu ", encrypted[i]);
    }
    printf("\n");

    for(uint32_t i = 0; i < len; i++) {
        // Decrypt each character of the message
        decrypted[i] = mod_pow(encrypted[i], d, n);
    }

    printf("Decrypted message:\n");
    for(uint32_t i = 0; i < len; i++) {
        printf("%c", (uchar) decrypted[i]);
    }
    printf("\n");

    return 0;
}