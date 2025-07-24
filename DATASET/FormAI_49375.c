//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Welcome to my Public-Key Algorithm Implementation example program!
 * This program generates two random prime numbers, calculates a public key and a private key for them,
 * encrypts and decrypts a message and outputs the result. 
 *
 * Disclaimer: This code is not actually secure, don't use it to encrypt anything important!
 */

int is_prime(int n) {
    /* Returns 1 if n is prime, 0 otherwise */
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generate_prime_number() {
    /* Generates a random prime number */
    int n = rand() % 1000 + 1000; // Generate a random number between 1000 and 1999
    while (!is_prime(n)) {
        n++;
    }
    return n;
}

int gcd(int a, int b) {
    /* Returns the Greatest Common Divisor of a and b */
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int calculate_public_key(int p, int q) {
    /* Calculates the public key for prime numbers p and q */
    int n = p * q; // Calculate the modulus
    int e = 2; // Start with the smallest possible value for the public key
    while (gcd((p-1)*(q-1), e) != 1) { // Find a value of e that is coprime with (p-1)*(q-1)
        e++;
    }
    return e * n;
}

int calculate_private_key(int p, int q, int e) {
    /* Calculates the private key for prime numbers p and q and public key e */
    int n = p * q; // Calculate the modulus
    int d = 1; // Start with the smallest possible value for the private key
    while ( (d * e) % ((p-1)*(q-1)) != 1 ) { // Find a value of d that satisfies the equation d * e = 1 (mod (p-1)*(q-1))
        d++;
    }
    return d * n;
}

int encrypt(int m, int e, int n) {
    /* Encrypts the message m using public key e and modulus n */
    return (int)pow(m, e) % n;
}

int decrypt(int c, int d, int n) {
    /* Decrypts the message c using private key d and modulus n */
    return (int)pow(c, d) % n;
}

int main() {
    printf("Welcome to my Secure Public-Key Algorithm Implementation example program! 😂\n\n");

    // Generate two random prime numbers
    int p = generate_prime_number();
    int q = generate_prime_number();

    printf("Generated two random prime numbers: p = %d and q = %d\n", p, q);

    // Calculate public and private keys
    int n = p * q;
    int e = calculate_public_key(p, q);
    int d = calculate_private_key(p, q, e);

    printf("Calculated public key (e, n): (%d, %d)\n", e, n);
    printf("Calculated private key (d, n): (%d, %d)\n", d, n);

    // Encrypt and decrypt a message
    int message = 1337;
    int encrypted_message = encrypt(message, e, n);
    int decrypted_message = decrypt(encrypted_message, d, n);

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);

    printf("\nThanks for using my Secure Public-Key Algorithm Implementation example program! 😝\n");

    return 0;
}