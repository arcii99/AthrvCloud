//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PUBLIC_KEY_BITS 1024

typedef struct {
    int n;
    int e;
} pubkey;

typedef struct {
    int n;
    int d;
} privkey;

/* function to check if a number is prime */
int is_prime(int num) {
    if (num == 2 || num == 3)
        return 1;
    if (num == 1 || num % 2 == 0)
        return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

/* function to generate a random prime number */
int generate_prime() {
    int prime;
    do {
        prime = rand() % (1 << 31);
    } while (!is_prime(prime));

    return prime;
}

/* function to calculate the greatest common divisor of two numbers */
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

/* function to generate public and private keys */
void gen_keys(pubkey * pub, privkey * priv) {
    int p, q, N, phi, e, d;

    // generate two random prime numbers p and q
    p = generate_prime();
    q = generate_prime();

    // calculate N
    N = p * q;

    // calculate phi
    phi = (p - 1) * (q - 1);

    // select a random integer e such that 1 < e < phi, and gcd(e,phi)=1
    do {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    // calculate d, the modular multiplicative inverse of e modulo phi
    int k = 1;
    while ((k * phi + 1) % e != 0) {
        k++;
    }
    d = (k * phi + 1) / e;

    // store public and private keys in the provided structures
    pub->n = N;
    pub->e = e;
    priv->n = N;
    priv->d = d;
}

/* function to encrypt a message using the public key */
int encrypt(int message, pubkey pub) {
    int encrypted = 1;
    for (int i = 0; i < pub.e; i++) {
        encrypted *= message;
        encrypted %= pub.n;
    }
    return encrypted;
}

/* function to decrypt a message using the private key */
int decrypt(int message, privkey priv) {
    int decrypted = 1;
    for (int i = 0; i < priv.d; i++) {
        decrypted *= message;
        decrypted %= priv.n;
    }
    return decrypted;
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // generate public and private keys
    pubkey pub_key;
    privkey priv_key;
    gen_keys(&pub_key, &priv_key);

    // encrypt and decrypt a message
    int message = 123456;
    int encrypted = encrypt(message, pub_key);
    int decrypted = decrypt(encrypted, priv_key);

    printf("Original message:\t%d\n", message);
    printf("Encrypted message:\t%d\n", encrypted);
    printf("Decrypted message:\t%d\n", decrypted);

    return 0;
}