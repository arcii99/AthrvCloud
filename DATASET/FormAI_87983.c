//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate GCD of two numbers
int gcd(int a, int b) 
{
    int temp;
    while (1) {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

// Function to perform encryption
int encrypt(int message, int e, int n)
{
    int c = 1;
    for (int i = 0; i < e; i++) {
        c = (c * message) % n;
    }
    return c;
}

// Function to perform decryption
int decrypt(int message, int d, int n)
{
    int m = 1;
    for (int i = 0; i < d; i++) {
        m = (m * message) % n;
    }
    return m;
}

int main() {
    int p, q, n, phi, e, d, message;
 
    // Genetrating prime numbers
    p = 7; 
    q = 11;
    n = p * q;
    phi = (p - 1) * (q - 1);
 
    // Generating encryption key
    e = rand() % phi;
    while (gcd(e, phi) != 1) {
        e = rand() % phi;
    }
 
    // Generating decryption key
    d = 0;
    int k = 1;
    while (1) {
        k = k + phi;
        if (k % e == 0) {
            d = k / e;
            break;
        }
    }
 
    // Sample message to be encrypted and decrypted
    message = 56;
 
    // Encryption and Decryption
    int encrypted_msg = encrypt(message, e, n);
    int decrypted_msg = decrypt(encrypted_msg, d, n);
 
    // Output
    printf("Original Message: %d\n", message);
    printf("Encrypted Message: %d\n", encrypted_msg);
    printf("Decrypted Message: %d\n", decrypted_msg);

    return 0;
}