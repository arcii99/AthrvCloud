//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int p;
    int q;
    int n;
    int e;
    int d;
} RSA;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int modpow(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int inverse(int a, int b) {
    int s0 = 1, s1 = 0, t0 = 0, t1 = 1;

    while (b > 0) {
        int q, temp;
        q = a / b;
        temp = a % b;
        a = b;
        b = temp;

        temp = s0 - q * s1;
        s0 = s1;
        s1 = temp;

        temp = t0 - q * t1;
        t0 = t1;
        t1 = temp;
    }

    return s0;
}

RSA RSA_new(int p, int q) {
    RSA rsa;
    rsa.p = p;
    rsa.q = q;
    rsa.n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose an encryption key `e` that is coprime to phi
    int e;
    do {
        e = rand() % (phi - 2) + 2; // generate randomly between 2 and phi-1
    } while (gcd(e, phi) != 1);
    rsa.e = e;

    // Compute decryption key 'd'
    rsa.d = inverse(e, phi);

    return rsa;
}

void RSA_encrypt(int plaintext, RSA rsa) {
    int ciphertext = modpow(plaintext, rsa.e, rsa.n);
    printf("Ciphertext: %d\n", ciphertext);
}

void RSA_decrypt(int ciphertext, RSA rsa) {
    int plaintext = modpow(ciphertext, rsa.d, rsa.n);
    printf("Plaintext: %d\n", plaintext);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a new Key-Pair
    RSA rsa = RSA_new(11, 13);

    // Encrypt and Decrypt
    RSA_encrypt(12345, rsa);
    RSA_decrypt(4278, rsa); 

    return 0;
}