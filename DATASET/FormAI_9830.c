//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function for finding the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to generate a random prime number
int generatePrime() {
    int n;
    do {
        n = rand() % 100 + 1;
    } while (!isPrime(n));
    return n;
}

// Function to calculate the modular exponentiation
int modularExponentiation(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent /= 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    // Generate two random prime numbers
    srand(time(NULL));
    int p = generatePrime();
    int q = generatePrime();
    
    // Calculate n and phi(n)
    int n = p * q;
    int phi = (p-1) * (q-1);
    
    // Find e such that it is coprime with phi(n)
    int e;
    do {
        e = rand() % phi + 1;
    } while (gcd(e, phi) != 1);
    
    // Calculate d such that d*e ≡ 1 mod phi(n)
    int d;
    int k = 2;
    while (1) {
        d = (1 + (k * phi)) / e;
        if ((d * e) % phi == 1) break;
        k++;
    }
    
    // Print the public and private key
    printf("Public Key: (%d, %d)\n", n, e);
    printf("Private Key: (%d, %d)\n", n, d);
    
    // Test the encryption and decryption process
    int message = 123;
    printf("Original Message: %d\n", message);
    
    // Encrypt the message using the public key
    int cipher = modularExponentiation(message, e, n);
    printf("Encrypted Message: %d\n", cipher);
    
    // Decrypt the message using the private key
    int decryptedMessage = modularExponentiation(cipher, d, n);
    printf("Decrypted Message: %d\n", decryptedMessage);
    
    return 0;
}