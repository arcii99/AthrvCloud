//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to check if a number is prime
int is_prime(int n) {
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

// function to generate a random prime number
int generate_prime() {
    int n = rand() % 500;
    while (1) {
        if (is_prime(n)) {
            return n;
        }
        n++;
    }
}

// function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// function to calculate the public key
int calculate_public_key(int phi_n) {
    int e = 2;
    while (e < phi_n) {
        if (gcd(e, phi_n) == 1) {
            return e;
        }
        e++;
    }
    return -1;
}

// function to calculate the private key
int calculate_private_key(int e, int phi_n) {
    int k = 1;
    while (1) {
        if ((k * phi_n + 1) % e == 0) {
            return (k * phi_n + 1) / e;
        }
        k++;
    }
}

// function to encrypt a message using the public key
int encrypt(int message, int e, int n) {
    int encrypted = 1;
    for (int i = 0; i < e; i++) {
        encrypted = (encrypted * message) % n;
    }
    return encrypted;
}

// function to decrypt a message using the private key
int decrypt(int message, int d, int n) {
    int decrypted = 1;
    for (int i = 0; i < d; i++) {
        decrypted = (decrypted * message) % n;
    }
    return decrypted;
}

int main() {
    // generate two random prime numbers
    int p = generate_prime();
    int q = generate_prime();
    
    // calculate n and phi_n
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    
    // calculate the public and private keys
    int e = calculate_public_key(phi_n);
    int d = calculate_private_key(e, phi_n);
    
    // print the public and private keys
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    
    // encrypt and decrypt a message
    int message = 123;
    int encrypted = encrypt(message, e, n);
    int decrypted = decrypt(encrypted, d, n);
    
    // print the encrypted and decrypted message
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted);
    printf("Decrypted message: %d\n", decrypted);
    
    return 0;
}