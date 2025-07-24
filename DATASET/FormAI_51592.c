//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
// A peaceful implementation of the RSA public-key algorithm
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the modular multiplicative inverse of a number
// using the extended Euclidean algorithm
int modinv(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

// Function to generate two prime numbers
void generate_primes(int *p, int *q) {
    int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int num1, num2, index1, index2;
    do {
        index1 = rand() % 25;
        index2 = rand() % 25;
        num1 = primes[index1];
        num2 = primes[index2];
    } while (num1 == num2);
    *p = num1;
    *q = num2;
}

// Function to generate the public and private keys
void generate_keys(int *n, int *e, int *d) {
    int p, q, phi_n;
    generate_primes(&p, &q);
    *n = p * q;
    phi_n = (p - 1) * (q - 1);
    do {
        *e = rand() % phi_n;
    } while (gcd(*e, phi_n) != 1);
    *d = modinv(*e, phi_n);
}

int main() {
    int n, e, d, i, len;
    char msg[1000];
    int encrypted[1000], decrypted[1000];

    generate_keys(&n, &e, &d);

    printf("Public key is: (%d, %d)\n", n, e);
    printf("Private key is: (%d, %d)\n", n, d);

    printf("Enter a message to encrypt: ");
    gets(msg);

    len = strlen(msg);

    // Encryption
    for (i = 0; i < len; i++) {
        encrypted[i] = (int)pow((double)msg[i], e) % n;
    }

    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    // Decryption
    for (i = 0; i < len; i++) {
        decrypted[i] = (int)pow((double)encrypted[i], d) % n;
    }

    printf("Decrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0;
}