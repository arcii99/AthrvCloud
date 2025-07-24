//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a given number is prime
int isPrime(int num) {
    int i;
    for(i=2; i<=sqrt(num); i++) {
        if(num%i==0) {
            return 0; // num is not prime
        }
    }
    return 1; // num is prime
}

// Function to generate a random prime number within a given range
int generateRandomPrime(int lowerBound, int upperBound) {
    int num;
    do {
        num = rand() % (upperBound - lowerBound + 1) + lowerBound;
    } while(!isPrime(num));
    return num;
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;
    if(m==1) {
        return 0; // Not defined
    }
    while(a>1) {
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if(x<0) {
        x += m0;
    }
    return x;
}

// Function to perform modular exponentiation
int modularExponentiation(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while(exponent>0) {
        if(exponent%2==1) {
            result = (result * base) % modulus;
        }
        exponent /= 2;
        base = (base * base) % modulus;
    }
    return result;
}

// Function to perform key generation
void generateKeys(int *publicKey, int *privateKey, int p, int q) {
    // Calculate n and phi(n)
    int n = p * q;
    int phi_n = (p-1) * (q-1);

    // Choose a random number e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    int e;
    do {
        e = rand() % phi_n + 1;
    } while(gcd(e, phi_n) != 1);

    // Calculate d such that e * d mod phi(n) = 1
    int d = modInverse(e, phi_n);

    // Set the public and private keys
    publicKey[0] = e;
    publicKey[1] = n;
    privateKey[0] = d;
    privateKey[1] = n;
}

// Function to perform encryption
int encrypt(int message, int publicKey[]) {
    return modularExponentiation(message, publicKey[0], publicKey[1]);
}

// Function to perform decryption
int decrypt(int cipherText, int privateKey[]) {
    return modularExponentiation(cipherText, privateKey[0], privateKey[1]);
}

int main() {
    int p = generateRandomPrime(100, 1000);
    int q = generateRandomPrime(100, 1000);

    int publicKey[2], privateKey[2];
    generateKeys(publicKey, privateKey, p, q);

    int message = 123;
    int cipherText = encrypt(message, publicKey);
    int decryptedText = decrypt(cipherText, privateKey);

    printf("Generated prime numbers: %d, %d\n", p, q);
    printf("Public key: {%d, %d}\n", publicKey[0], publicKey[1]);
    printf("Private Key: {%d, %d}\n", privateKey[0], privateKey[1]);
    printf("Message: %d\n", message);
    printf("Encrypted Text: %d\n", cipherText);
    printf("Decrypted Text: %d\n", decryptedText);

    return 0;
}