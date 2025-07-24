//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Initialize public key algorithm constants
const int PRIME_ONE = 17;
const int PRIME_TWO = 19;
const int PUBLIC_KEY = 323;

// Function prototypes
bool isPrime(int n);
int generateRandomPrime(int start, int end);
int calculateGCD(int a, int b);
int calculatePrivateKey(int p, int q, int e);
int encryptMessage(int message, int e, int n);
int decryptMessage(int cipherText, int d, int n);

int main() {
    // Generate two random prime numbers
    int p = generateRandomPrime(3, 100);
    int q = generateRandomPrime(3, 100);

    printf("Prime number 1: %d\n", p);
    printf("Prime number 2: %d\n", q);

    // Calculate modulus and Euler's totient function
    int n = p * q;
    int totient = (p - 1) * (q - 1);
    printf("Modulus n: %d\n", n);
    printf("Euler's totient function: %d\n", totient);

    // Find a random number e that is coprime to totient
    int e = PUBLIC_KEY;
    while (e < totient) {
        if (calculateGCD(totient, e) == 1) {
            break;
        }
        e++;
    }
    printf("Public key exponent e: %d\n", e);

    // Calculate private key exponent d
    int d = calculatePrivateKey(p, q, e);
    printf("Private key exponent d: %d\n", d);

    // Message to be encrypted
    int message = 123;
    printf("Original message: %d\n", message);

    // Encrypt the message using public key
    int cipherText = encryptMessage(message, e, n);
    printf("Encrypted message: %d\n", cipherText);

    // Decrypt the message using private key
    int decryptedMessage = decryptMessage(cipherText, d, n);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}

// Function to check whether a given number is prime or not
bool isPrime(int n) {
    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a random prime number between start and end
int generateRandomPrime(int start, int end) {
    int num = 0;
    while (!isPrime(num)) {
        num = (rand() % (end - start + 1)) + start;
    }
    return num;
}

// Function to calculate the GCD of two numbers
int calculateGCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate private key exponent d
int calculatePrivateKey(int p, int q, int e) {
    int totient = (p - 1) * (q - 1);
    int d = 1;
    while ((e * d) % totient != 1) {
        d++;
    }
    return d;
}

// Function to encrypt a message using public key
int encryptMessage(int message, int e, int n) {
    int cipherText = 1;
    for (int i = 0; i < e; i++) {
        cipherText = (cipherText * message) % n;
    }
    return cipherText;
}

// Function to decrypt a message using private key
int decryptMessage(int cipherText, int d, int n) {
    int decryptedMessage = 1;
    for (int i = 0; i < d; i++) {
        decryptedMessage = (decryptedMessage * cipherText) % n;
    }
    return decryptedMessage;
}