//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// Function to calculate greatest common divisor using Euclid's algorithm
// Will be used in calculating the public key
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    // Declare variables
    int p, q, n, phi, e, d;
    bool isPrime;

    // Seed random number generator
    srand(time(NULL));

    // Generate 2 prime numbers, p and q
    do {
        isPrime = true;

        // Generate p
        p = rand() % 100 + 1; // Generate random number from 1 to 100

        // Check if p is prime
        for (int i = 2; i <= sqrt(p); i++) {
            if (p % i == 0) {
                isPrime = false;
                break;
            }
        } 
    } while (!isPrime);

    do {
        isPrime = true;

        // Generate q
        q = rand() % 100 + 1; // Generate random number from 1 to 100

        // Check if q is prime
        for (int i = 2; i <= sqrt(q); i++) {
            if (q % i == 0) {
                isPrime = false;
                break;
            }
        } 
    } while (!isPrime);

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    do {
        e = rand() % (phi - 2) + 2; // Generate random number from 2 to phi-1
    } while (gcd(e, phi) != 1);

    // Calculate d such that d * e = 1 (mod phi)
    int k = 1;
    while ((k * phi + 1) % e != 0) {
        k++;
    }
    d = (k * phi + 1) / e;

    // Print results
    printf("p: %d\n", p);
    printf("q: %d\n", q);
    printf("n: %d\n", n);
    printf("phi: %d\n", phi);
    printf("e: %d\n", e);
    printf("d: %d\n", d);

    // Example encryption and decryption
    char plaintext = 'A';
    printf("Plaintext: %c\n", plaintext);
    int ciphertext = fmod(pow(plaintext, e), n);
    printf("Ciphertext: %d\n", ciphertext);
    char decrypted_text = fmod(pow(ciphertext, d), n);
    printf("Decrypted text: %c\n", decrypted_text);

    return 0;
}