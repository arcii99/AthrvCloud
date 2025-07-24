//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BLOCK_SIZE 256
#define KEY_SIZE 1024

unsigned long long int p, q, n, totient, e, d;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    if (a == 0) return b;
    else return gcd(b%a, a);
}

unsigned long long int mod_power(unsigned long long int base, unsigned long long int exponent, unsigned long long int modulus) {
    unsigned long long int result = 1;
    while (exponent > 0) {
        if (exponent & 1) result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

void generate_keys() {
    srand(time(NULL));
    p = rand() % (KEY_SIZE/2) + KEY_SIZE/4;
    q = rand() % (KEY_SIZE/2) + KEY_SIZE/4;

    while (p == q) {
        q = rand() % (KEY_SIZE/2) + KEY_SIZE/4;
    }

    n = p * q;
    totient = (p - 1) * (q - 1);

    e = 3;
    while (gcd(totient, e) != 1) {
        e += 2;
    }

    d = mod_power(e, -1, totient);
}

unsigned long long int rsa_encrypt(unsigned long long int message) {
    return mod_power(message, e, n);
}

unsigned long long int rsa_decrypt(unsigned long long int cipher) {
    return mod_power(cipher, d, n);
}

int main() {
    generate_keys();

    unsigned char message[BLOCK_SIZE] = "Hello, world!";
    unsigned char plain[BLOCK_SIZE], cipher[BLOCK_SIZE];
    memcpy(plain, message, BLOCK_SIZE);

    // Encryption
    for (int i = 0; i < BLOCK_SIZE/sizeof(unsigned long long int); ++i) {
        unsigned long long int block = 0;
        memcpy(&block, plain+i*sizeof(unsigned long long int), sizeof(unsigned long long int));
        unsigned long long int encrypted_block = rsa_encrypt(block);
        memcpy(cipher+i*sizeof(unsigned long long int), &encrypted_block, sizeof(unsigned long long int));
    }

    // Decryption
    for (int i = 0; i < BLOCK_SIZE/sizeof(unsigned long long int); ++i) {
        unsigned long long int encrypted_block = 0;
        memcpy(&encrypted_block, cipher+i*sizeof(unsigned long long int), sizeof(unsigned long long int));
        unsigned long long int decrypted_block = rsa_decrypt(encrypted_block);
        memcpy(plain+i*sizeof(unsigned long long int), &decrypted_block, sizeof(unsigned long long int));
    }

    printf("Plain text : ");
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        printf("%c", plain[i]);
    }
    printf("\n");

    printf("Cipher text : ");
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        printf("%llu ", cipher[i]);
    }
    printf("\n");

    return 0;
}