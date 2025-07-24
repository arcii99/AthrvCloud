//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PRIME_NUMBER_SIZE 100 // Size of prime numbers array
#define MAX_NUM_ATTEMPTS 100 // Maximum number of attempts to find a prime number

int primeNumberList[PRIME_NUMBER_SIZE] = {2}; // Prime number array initialized with 2

// Returns 1 if a number is prime, 0 otherwise
int isPrime(int n) {
    if (n == 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Initializes prime number array with prime numbers up to a given limit
void initPrimeNumberList(int limit) {
    int count = 1;
    for (int i = 3; i <= limit; i += 2) {
        if (isPrime(i)) {
            primeNumberList[count++] = i;
        }
    }
}

// Generates a random prime number of a given length
int generatePrimeNumber(int length) {
    int attempts = 0;
    while (attempts < MAX_NUM_ATTEMPTS) {
        int randomNumber = rand() % ((int) pow(10, length) - 1) + (int) pow(10, length - 1);
        if (isPrime(randomNumber)) {
            return randomNumber;
        }
        attempts++;
    }
    return -1; // Could not generate a prime number
}

// Finds the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Calculates the public key (e) and private key (d) values
void calculateKeyValues(int p, int q, int *e, int *d) {
    int phi = (p - 1) * (q - 1);
    int n = p * q;
    *e = 2;
    while (gcd(*e, phi) != 1) {
        *e += 1;
    }
    for (int i = 1; ; i++) {
        int temp = 1 + (i * phi);
        if (temp % *e == 0) {
            *d = temp / *e;
            break;
        }
    }
}

// Encrypts a message using the public key (e) and modulus (n)
int encrypt(int message, int e, int n) {
    int cipherText = (int) pow(message, e) % n;
    return cipherText;
}

// Decrypts a message using the private key (d) and modulus (n)
int decrypt(int cipherText, int d, int n) {
    int message = (int) pow(cipherText, d) % n;
    return message;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    initPrimeNumberList(1000); // Initialize the prime number array

    int p = generatePrimeNumber(3);
    int q = generatePrimeNumber(3);

    int e, d;
    calculateKeyValues(p, q, &e, &d);

    int n = p * q;
    printf("Public key: (%d,%d)\n", e, n);
    printf("Private key: (%d,%d)\n", d, n);

    int message = 123;
    printf("Original message: %d\n", message);

    int cipherText = encrypt(message, e, n);
    printf("Encrypted message: %d\n", cipherText);

    int decryptedMessage = decrypt(cipherText, d, n);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}