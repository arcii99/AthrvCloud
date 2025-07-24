//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define MAX digits for the prime numbers
#define MAX_DIGITS 1000

// Function to generate a random prime number
long int generatePrime() {
    long int prime, num;
    int i, flag;
    do {
        prime = rand() % MAX_DIGITS;
        flag = 1;
        for (i = 2; i <= sqrt(prime); i++) {
            if (prime % i == 0) {
                flag = 0;
                break;
            }
        }
    } while (flag == 0);
    return prime;
}

// Function to calculate the Greatest Common Divisor of two numbers
long int gcd(long int a, long int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

// Function to calculate the Multiplicative Inverse of a number
long int multiplicativeInverse(long int e, long int phi) {
    long int d;

    for (d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            break;
        }
    }
    return d;
}

// Main function
int main() {
    long int p, q, n, phi, e, d, plaintext, ciphertext;
    char message[MAX_DIGITS];

    // Generate prime numbers p and q
    p = generatePrime();
    q = generatePrime();

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Generate public key e
    e = generatePrime();

    // Ensure that gcd(e, phi) = 1
    while (gcd(e, phi) != 1) {
        e = generatePrime();
    }

    // Calculate private key d
    d = multiplicativeInverse(e, phi);

    // Get input message from user
    printf("Enter the message you wish to encrypt: ");
    fflush(stdin);
    fgets(message, MAX_DIGITS, stdin);

    // Loop through each character of the message
    for (int i = 0; i < strlen(message); i++) {
        plaintext = message[i];

        // Calculate ciphertext
        ciphertext = fmod(pow(plaintext, e), n);

        // Output ciphertext
        printf("%ld ", ciphertext);
    }

    printf("\n");

    return 0;
}