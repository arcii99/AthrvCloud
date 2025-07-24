//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// struct to hold public and private keys
typedef struct KeyPair {
    int public_key;
    int private_key;
} KeyPair;

// function to generate a random prime number
int generatePrime(int min, int max) {
    int num;
    srand(time(NULL));
    while(1) {
        num = (rand() % (max - min + 1)) + min;
        if(isPrime(num)) {
            return num;
        }
    }
}

// function to check if a number is prime
int isPrime(int num) {
    if(num == 1) {
        return 0;
    }

    for(int i = 2; i < num/2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// function to calculate gcd of two numbers
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

// function to calculate modular inverse
int modInverse(int a, int m) {
    for(int i = 1; i < m; i++) {
        if((a*i) % m == 1) {
            return i;
        }
    }

    return 0;
}

// function to generate public and private keys
KeyPair generateKeys() {
    int p = generatePrime(100, 1000);
    int q = generatePrime(100, 1000);
    int n = p * q;

    int phi_n = (p - 1) * (q - 1);

    int e = 2;
    while(e < phi_n) {
        if(gcd(e, phi_n) == 1) {
            break;
        }
        e++;
    }

    int d = modInverse(e, phi_n);

    KeyPair keyPair;
    keyPair.public_key = e;
    keyPair.private_key = d;

    return keyPair;
}

int main(void) {
    KeyPair keyPair = generateKeys();

    printf("Public key: %d\n", keyPair.public_key);
    printf("Private key: %d\n", keyPair.private_key);

    return 0;
}