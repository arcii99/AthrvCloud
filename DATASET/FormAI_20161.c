//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define a large prime number
#define PRIME 2147483647

// Define a struct to hold the public key
typedef struct PublicKey {
    int p; // prime number p
    int g; // generator g
    int y; // public key y
} PublicKey;

// Function to generate a random number between 1 and n-1
int generateRandom(int n) {
    int r;
    srand(time(NULL)); // seed the random number generator
    r = rand() % (n-1) + 1; // generate a random number between 1 and n-1
    return r;
}

// Function to calculate a^b mod n
int modExp(int a, int b, int n) {
    int c = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            c = (c * a) % n;
        }
        a = (a * a) % n;
        b = b / 2;
    }
    return c;
}

// Function to generate a primitive root of a prime number
int generatePrimitiveRoot(int p) {
    int i, j, r, flag;
    for (i = 2; i < p; i++) {
        flag = 0;
        for (j = 1; j < p-1; j++) {
            r = modExp(i, j, p);
            if (r == 1) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        }
    }
}

// Function to generate a public key
PublicKey generatePublicKey() {
    PublicKey pk;
    pk.p = PRIME;
    pk.g = generatePrimitiveRoot(pk.p);
    pk.y = modExp(pk.g, generateRandom(pk.p-1), pk.p);
    return pk;
}

// Function to perform public key encryption
int encrypt(int m, PublicKey pk) {
    int k = generateRandom(pk.p-1);
    int c1 = modExp(pk.g, k, pk.p);
    int c2 = (m * modExp(pk.y, k, pk.p)) % pk.p;
    printf("Cipher text: (%d, %d)\n", c1, c2);
    return 0;
}

int main() {
    PublicKey pk = generatePublicKey();
    printf("Public key: (p=%d, g=%d, y=%d)\n", pk.p, pk.g, pk.y);
    int message;
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);
    encrypt(message, pk);
    return 0;
}