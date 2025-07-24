//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cyberpunk
// C Public-Key Algorithm Implementation
// Written in typical Cyberpunk fashion

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate random numbers
int random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate power
int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b = b >> 1;
    }
    return res;
}

// Function to find greatest common divisor
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

//Function to encrypt message
int encrypt(int msg, int e_key, int n) {
    int c = power(msg, e_key);
    c = c % n;
    return c;
}

//Function to decrypt message
int decrypt(int cipher, int d_key, int n) {
    int m = power(cipher, d_key);
    m = m % n;
    return m;
}

int main() {
    srand(time(0));
    int p = 0, q = 0, n = 0, phin = 0, e_key = 0, d_key = 0, msg = 0, cipher = 0;
    // Generate random prime number p
    do {
        p = random_num(100, 500);
    } while (p % 2 == 0);
    // Generate random prime number q
    do {
        q = random_num(100, 500);
    } while (q % 2 == 0 || q == p);
    // Calculate n
    n = p * q;
    // Calculate Euler's totient function
    phin = (p - 1) * (q - 1);
    // Generate random encryption key
    do {
        e_key = random_num(2, phin - 1);
    } while (gcd(e_key, phin) != 1);
    // Calculate decryption key
    d_key = 1;
    while ((d_key * e_key) % phin != 1 || d_key == e_key) {
        d_key++;
    }
    // Ask user to enter message
    printf("Enter message to encrypt: ");
    scanf("%d", &msg);
    // Encrypt message using public key
    cipher = encrypt(msg, e_key, n);
    // Print encrypted message
    printf("Encrypted Message: %d\n", cipher);
    // Decrypt message using private key
    msg = decrypt(cipher, d_key, n);
    // Print decrypted message
    printf("Decrypted Message: %d\n", msg);
    // Exit program
    return 0;
}