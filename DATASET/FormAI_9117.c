//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

/* Define a struct for public key */
typedef struct Public_Key {
    int n; /* modulus */
    int e; /* public exponent */
} PublicKey;

/* Define a struct for private key */
typedef struct Private_Key {
    int n; /* modulus */
    int d; /* private exponent */
} PrivateKey;

/* Function to generate public and private keys */
void generate_keys(int p, int q, PublicKey *pub_key, PrivateKey *priv_key) {
    int n, phi, e, d;
    /* Calculate modulus */
    n = p * q;
    /* Calculate Euler's totient function */
    phi = (p - 1) * (q - 1);
    /* Choose public exponent */
    e = 3;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }
        e += 2;
    }
    /* Calculate private exponent */
    d = mod_inv(e, phi);
    /* Set public key */
    pub_key->n = n;
    pub_key->e = e;
    /* Set private key */
    priv_key->n = n;
    priv_key->d = d;
}

/* Function to encrypt message */
int encrypt(int message, PublicKey pub_key) {
    int result = mod_exp(message, pub_key.e, pub_key.n);
    return result;
}

/* Function to decrypt message */
int decrypt(int cipher, PrivateKey priv_key) {
    int result = mod_exp(cipher, priv_key.d, priv_key.n);
    return result;
}

/* Main function */
int main() {
    int p = 17, q = 19;
    int message = 11;
    PublicKey pub_key;
    PrivateKey priv_key;
    /* Generate public and private keys */
    generate_keys(p, q, &pub_key, &priv_key);
    /* Encrypt message */
    int cipher = encrypt(message, pub_key);
    /* Decrypt message */
    int decrypted = decrypt(cipher, priv_key);
    /* Print original message, encrypted message, and decrypted message */
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", cipher);
    printf("Decrypted message: %d\n", decrypted);
    return 0;
}

/* Function to calculate greatest common divisor */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/* Function to calculate modular inverse */
int mod_inv(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        /* Integer division */
        q = a / m;
        t = m;
        /* Update m and a */
        m = a % m;
        a = t;
        t = x0;
        /* Update x0 and x1 */
        x0 = x1 - q * x0;
        x1 = t;
    }
    /* Ensure x1 is positive */
    if (x1 < 0) {
        x1 += m0;
    }
    return x1;
}

/* Function to calculate modular exponentiation */
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}