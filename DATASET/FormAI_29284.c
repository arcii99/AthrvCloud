//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a number is prime
int isPrime(int n) {
    // 0 and 1 are not prime
    if (n <= 1) {
        return 0;
    }

    int i;
    // Check for divisibility from 2 to n-1
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random prime number
int generatePrime() {
    int num;
    // Loop until a prime number is generated
    do {
        num = rand() % 1000 + 1; // Generate a random number between 1 and 1000
    } while (!isPrime(num));
    return num;
}

// Function to find the greatest common divisor using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to generate public-private key pairs
void generateKeyPair(int *pubKey, int *priKey) {
    // Generate two random prime numbers
    int p = generatePrime();
    int q = generatePrime();

    // Compute n and euler's totient function
    int n = p * q;
    int totient = (p - 1) * (q - 1);

    // Choose a random number e which is coprime to totient
    int e;
    do {
      e = rand() % totient;
    } while (gcd(e, totient) != 1);

    // Compute the multiplicative inverse of e mod totient
    int d = 0;
    while ((d * e) % totient != 1) {
        d++;
    }

    // Set the public and private keys
    pubKey[0] = n;
    pubKey[1] = e;
    priKey[0] = n;
    priKey[1] = d;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the public-private key pairs
    int pubKey[2], priKey[2];
    generateKeyPair(pubKey, priKey);

    // Print the keys
    printf("Public key: (%d, %d)\n", pubKey[0], pubKey[1]);
    printf("Private key: (%d, %d)\n", priKey[0], priKey[1]);

    return 0;
}