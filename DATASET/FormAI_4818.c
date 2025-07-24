//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (a == 0) 
        return b;
    return gcd(b % a, a);
}

// function to calculate power of a number
int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) 
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}

// function to generate a prime number
int generatePrime(int min, int max) {
    int i, j, flag;
    int prime;

    srand(time(NULL));

    // check for prime numbers between min and max
    for (i = min; i <= max; i++) {
        flag = 1;
        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) 
            prime = i;
    }

    return prime;
}

int main() {
    int p, q, n, e, d, phi, plaintext, encrypted, decrypted;

    // generate two prime numbers
    p = generatePrime(3, 50);
    q = generatePrime(51, 100);

    // calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // choose e
    do {
        srand(time(NULL));
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    // calculate d
    d = power(e, phi-2, phi);

    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    // encryption
    printf("\nEnter plaintext to encrypt: ");
    scanf("%d", &plaintext);

    encrypted = power(plaintext, e, n);
    printf("\nEncrypted message: %d", encrypted);

    // decryption
    decrypted = power(encrypted, d, n);
    printf("\nDecrypted message: %d", decrypted);

    return 0;
}