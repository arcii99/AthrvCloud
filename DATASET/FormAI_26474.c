//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct public_key {
    unsigned long n;
    unsigned long e;
};

struct private_key {
    unsigned long n;
    unsigned long d;
};

//Find greatest common divisor of two numbers
unsigned long gcd(unsigned long a, unsigned long b) {
    unsigned long tmp;
    while(b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

//"Fast" modular exponentiation (base^exp mod m)
unsigned long mod_pow(unsigned long base, unsigned long exp, unsigned long m) {
    unsigned long result = 1;
    base %= m;
    while(exp) {
        if(exp & 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        exp >>= 1;
    }
    return result;
}

//Generate public and private keys
void generate_key_pair(struct public_key *pub_key, struct private_key *priv_key, unsigned long p, unsigned long q) {
    unsigned long n = p * q, phi = (p - 1) * (q - 1), e, d = 0;
    do {
        e = rand() % phi + 1;
    } while(gcd(e, phi) != 1);
    while((d * e) % phi != 1) {
        d++;
    }
    pub_key->n = priv_key->n = n;
    pub_key->e = e;
    priv_key->d = d;
}

//Encrypt message with public key
unsigned long encrypt(unsigned long msg, struct public_key pub_key) {
    return mod_pow(msg, pub_key.e, pub_key.n);
}

//Decrypt message with private key
unsigned long decrypt(unsigned long msg, struct private_key priv_key) {
    return mod_pow(msg, priv_key.d, priv_key.n);
}

int main() {
    srand(time(NULL));
    struct public_key pub_key;
    struct private_key priv_key;
    unsigned long p = 61, q = 53, msg = 123456789;
    generate_key_pair(&pub_key, &priv_key, p, q);
    printf("Public key: %lu %lu\n", pub_key.n, pub_key.e);
    printf("Private key: %lu %lu\n", priv_key.n, priv_key.d);
    printf("Original message: %lu\n", msg);
    unsigned long encrypted = encrypt(msg, pub_key);
    printf("Encrypted message: %lu\n", encrypted);
    unsigned long decrypted = decrypt(encrypted, priv_key);
    printf("Decrypted message: %lu\n", decrypted);
    return 0;
}