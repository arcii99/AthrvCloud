//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// this function checks if a number is prime
bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// this function finds the gcd of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// this function generates a random prime number
int generate_prime() {
    int num = rand() % 1000 + 1000;
    while (!is_prime(num)) {
        num--;
    }
    return num;
}

// this function calculates the modular inverse of a number
int mod_inverse(int a, int b) {
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
  
    if (b == 1) {
        return 1;
    }
  
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
  
    if (x1 < 0) {
        x1 += b0;
    }
  
    return x1;
}

// this function encrypts a message using the public key
int encrypt(int msg, int e, int n) {
    int c = 1;
    for (int i = 0; i < e; i++) {
        c = (c * msg) % n;
    }
    return c;
}

// this function decrypts a message using the private key
int decrypt(int msg, int d, int n) {
    int m = 1;
    for (int i = 0; i < d; i++) {
        m = (m * msg) % n;
    }
    return m;
}

int main() {
    // generate two random prime numbers
    int p = generate_prime();
    int q = generate_prime();

    // calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // find a random number e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    int e;
    do {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    // calculate the modular inverse of e
    int d = mod_inverse(e, phi);

    // print the public and private key pair
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);

    // encrypt and decrypt a message
    int msg = 123;
    int encrypted_msg = encrypt(msg, e, n);
    int decrypted_msg = decrypt(encrypted_msg, d, n);

    // print the original message, the encrypted message, and the decrypted message
    printf("Original Message: %d\n", msg);
    printf("Encrypted Message: %d\n", encrypted_msg);
    printf("Decrypted Message: %d\n", decrypted_msg);

    return 0;
}