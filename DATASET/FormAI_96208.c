//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to find if a number is prime
int isPrime(int n) {
    int i;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

// Function to find the greatest common divisor between two integers
int gcd(int a, int b) {
    int temp;
    while (1) {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

// Function to find the smallest prime number greater than n
int getNextPrime(int n) {
    while (1) {
        n++;
        if (isPrime(n))
            return n;
    }
}

// Function to generate the public and private keys
void generateKeys(int p, int q, int *n, int *e, int *d) {
    int phi = (p-1)*(q-1);
    *n = p*q;
    *e = 3; // generally e is chosen as a small prime number
    while (gcd(phi, *e) != 1)
        *e += 2;
    int k = 1;
    while ((k*phi + 1) % *e != 0)
        k++;
    *d = (k*phi + 1) / *e;
}

// Function to encrypt the message
int encrypt(int m, int e, int n) {
    int c = 1;
    for (int i = 0; i < e; i++)
        c = (c*m) % n;
    return c;
}

// Function to decrypt the message
int decrypt(int c, int d, int n) {
    int m = 1;
    for (int i = 0; i < d; i++)
        m = (m*c) % n;
    return m;
}

int main() {
    int p = 11;
    int q = 7;
    int n, e, d;

    // Find the keys
    generateKeys(p, q, &n, &e, &d);

    // Print the keys
    printf("Public Key : {%d, %d}\n", e, n);
    printf("Private Key : {%d, %d}\n", d, n);

    // Encrypt and decrypt a message
    int message = 5;
    int cipher = encrypt(message, e, n);
    int decrypted_message = decrypt(cipher, d, n);

    //Print the original message and the decrypted message
    printf("Original Message : %d\n", message);
    printf("Encrypted Message : %d\n", cipher);
    printf("Decrypted Message : %d\n", decrypted_message);

    return 0;
}