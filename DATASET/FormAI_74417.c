//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if a number is prime or not
int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Function to generate Public and Private Keys
void generateKeys() {
    // Set the seed
    srand(time(NULL));

    // Generate 2 large prime numbers
    int p = generateRandomNumber(100, 500);
    int q = generateRandomNumber(100, 500);

    while (!isPrime(p)) {
        p = generateRandomNumber(100, 500);
    }

    while (!isPrime(q) || q == p) {
        q = generateRandomNumber(100, 500);
    }

    // Calculate n and phi(n)
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);

    // Choose a random number e such that gcd(e, phi(n)) = 1
    int e = generateRandomNumber(2, phi_n - 1);
    while (gcd(e, phi_n) != 1) {
        e = generateRandomNumber(2, phi_n - 1);
    }

    // Calculate d using Extended Euclidean Algorithm
    int d, k = 1;
    while (1) {
        k += phi_n;

        if (k % e == 0) {
            d = k / e;
            break;
        }
    }

    // Print the public and private keys
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);
}

int main() {
    generateKeys();
    return 0;
}