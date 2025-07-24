//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to generate random prime number
bool isPrime(int num){
    if(num == 2 || num == 3)
        return true;
    if((num % 2) == 0 || num < 2)
        return false;
    for(int i = 3; i * i <= num; i += 2)
        if(num % i == 0)
            return false;
    return true;
}

int generateRandomPrime(int upperBound) {
    int p = rand() % upperBound;
    while(!isPrime(p)){
        p = rand() % upperBound;
    }
    return p;
}

// function to calculate gcd
int gcd (int a, int b){
    int temp;
    while(1){
        temp = a%b;
        if(temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

// function to get random number that is relatively prime to p
int getRelativelyPrime(int p) {
    int e = rand() % p;
    while(gcd(e, p) != 1) {
        e = rand() % p;
    }
    return e;
}

// function to calculate modular exponentiation
int modExp(int base, int exponent, int modulus) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

// function to encrypt data
int encrypt(int message, int e, int n) {
    return modExp(message, e, n);
}

// function to decrypt data
int decrypt(int message, int d, int n) {
    return modExp(message, d, n);
}

int main() {

    //generate random prime numbers for p and q
    srand(time(NULL));
    int p = generateRandomPrime(1000);
    int q = generateRandomPrime(1000);

    // calculate n
    int n = p * q;

    // calculate phi(n)
    int phi = (p - 1) * (q - 1);

    // select random e relatively prime to phi(n)
    int e = getRelativelyPrime(phi);

    // calculate d such that (d * e) % phi(n) = 1
    int d = 0;
    while( ((d * e) % phi) != 1 ) {
        ++d;
    }

    // display public and private keys
    printf("Public Key: {%d, %d}\n", e, n);
    printf("Private Key: {%d, %d}\n", d, n);

    // encrypt and decrypt data
    int message = 456;
    int encryptedMessage = encrypt(message, e, n);
    int decryptedMessage = decrypt(encryptedMessage, d, n);

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encryptedMessage);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}