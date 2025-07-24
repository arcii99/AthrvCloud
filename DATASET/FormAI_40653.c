//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function prototypes
int gcd(int a, int b);
int generatePrime();
int generatePublicKey(int phi);
int generatePrivateKey(int e, int phi);
int encrypt(int m, int e, int n);
int decrypt(int c, int d, int n);

// Main Function
int main() {
    int p, q, n, phi, e, d, message, encrypted, decrypted;
    
    // Generate two prime numbers
    p = generatePrime();
    q = generatePrime();
    
    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Generate public key
    e = generatePublicKey(phi);

    // Generate private key
    d = generatePrivateKey(e, phi);

    // Generate message
    printf("Enter message to encrypt: ");
    scanf("%d", &message);

    // Encrypt message
    encrypted = encrypt(message, e, n);

    // Decrypt message
    decrypted = decrypt(encrypted, d, n);

    // Output results
    printf("\nPublic Key (e): %d\n", e);
    printf("Private Key (d): %d\n", d);
    printf("Original Message: %d\n", message);
    printf("Encrypted Message: %d\n", encrypted);
    printf("Decrypted Message: %d\n", decrypted);

    return 0;
}

// Function to calculate greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to generate prime number
int generatePrime() {
    int num, isPrime = 0;
    
    // Keep generating random numbers until a prime number is found
    while (!isPrime) { 
        num = rand() % 1000 + 2;
        isPrime = 1;

        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    return num;
}

// Function to generate public key
int generatePublicKey(int phi) {
    int e = 2;
    
    // Keep increasing e until it is relatively prime with phi
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        } else {
            e++;
        }
    }
    
    return e;
}

// Function to generate private key
int generatePrivateKey(int e, int phi) {
    int d = 1;
    
    // Keep increasing d until it satisfies the condition
    while ((d * e) % phi != 1) {
        d++;
    }
    
    return d;
}

// Function to encrypt message
int encrypt(int m, int e, int n) {
    int c = fmod(pow(m, e), n);
    return c;
}

// Function to decrypt message
int decrypt(int c, int d, int n) {
    int m = fmod(pow(c, d), n);
    return m;
}