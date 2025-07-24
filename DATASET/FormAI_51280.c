//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Define global variables */
uint64_t p, q, n, m, e, d;

/* Function to check if a number is prime */
int is_prime(uint64_t num) {
    if (num <= 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    uint64_t i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
        i += 6;
    }
    return 1;
}

/* Function to find a random prime number within a specified range */
uint64_t find_prime(uint64_t min, uint64_t max) {
    uint64_t num;
    do {
        num = (rand() % (max - min + 1)) + min;
    } while (!is_prime(num));
    return num;
}

/* Function to compute greatest common divisor */
uint64_t gcd(uint64_t a, uint64_t b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

/* Function to compute modular exponentiation */
uint64_t mod_exp(uint64_t base, uint64_t exponent, uint64_t modulus) {
    uint64_t result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

/* Function to generate public and private keys */
void generate_keys() {
    /* Choose random prime numbers p and q */
    srand(time(NULL));
    p = find_prime(1000000000, 9999999999);
    q = find_prime(1000000000, 9999999999);
    n = p * q;

    /* Compute Euler's totient function of n */
    m = (p - 1) * (q - 1);

    /* Choose a random number e such that gcd(e, m) = 1 */
    do {
        e = rand() % (m - 2) + 2;
    } while (gcd(e, m) != 1);

    /* Compute d such that e*d = 1 (mod m) */
    uint64_t k = 1;
    while ((k * m + 1) % e != 0) {
        k++;
    }
    d = (k * m + 1) / e;
}

/* Function to encrypt a message using the public key */
uint64_t encrypt(uint64_t message) {
    return mod_exp(message, e, n);
}

/* Function to decrypt a message using the private key */
uint64_t decrypt(uint64_t message) {
    return mod_exp(message, d, n);
}

int main() {
    generate_keys();

    uint64_t message;
    printf("Enter a message to encrypt: ");
    scanf("%lu", &message);

    uint64_t encrypted = encrypt(message);
    printf("Encrypted message: %lu\n", encrypted);

    uint64_t decrypted = decrypt(encrypted);
    printf("Decrypted message: %lu\n", decrypted);

    return 0;
}