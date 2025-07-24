//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Public-Private key struct
typedef struct {
    long long p, q; // Prime numbers
    long long n; // Modulus
    long long e; // Public key
    long long d; // Private key
} PublicKey;

// Calculates the greatest common divisor of a and b using Euclid's algorithm
long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Generates a prime number
long long generatePrime() {
    srand(time(NULL));
    long long n = 0;
    while (n < 1000 || n > 100000) { // Limits prime numbers between 1000 to 100000
        n = rand() % 100000 + 1;
        int i;
        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                n = 0;
                break;
            }
        }
    }
    return n;
}

// Calculates the modulo of a and b
long long mod(long long a, long long b) {
    long long result = a % b;
    if (result < 0) {
        result += b;
    }
    return result;
}

// Calculates the inverse of a mod m using the extended Euclidean algorithm
long long modInverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

// Generates a public-private key pair
PublicKey generateKeys() {
    PublicKey keys;
    keys.p = generatePrime();
    keys.q = generatePrime();
    keys.n = keys.p * keys.q;
    keys.e = 65537; // Common value for public key
    long long phi = (keys.p - 1) * (keys.q - 1);
    keys.d = modInverse(keys.e, phi); // Private key
    return keys;
}

// Encrypts message using the public key
long long encrypt(long long message, PublicKey keys) {
    return mod(pow(message, keys.e), keys.n);
}

// Decrypts the cipher using the private key
long long decrypt(long long cipher, PublicKey keys) {
    return mod(pow(cipher, keys.d), keys.n);
}

int main() {
    PublicKey keys = generateKeys();
    printf("Public Key (p, q, n, e): %lld %lld %lld %lld\n", keys.p, keys.q, keys.n, keys.e);
    printf("Private Key (d): %lld\n", keys.d);

    char message[50];
    printf("Enter message (max 50 characters): ");
    fgets(message, 50, stdin);
    message[strlen(message) - 1] = '\0';

    int i;
    for (i = 0; i < strlen(message); i++) {
        long long encrypted = encrypt((long long) message[i], keys);
        printf("%lld ", encrypted);
    }
    printf("\n");

    int cipher;
    printf("Enter cipher: ");
    scanf("%d", &cipher);
    printf("Decrypted Message: ");
    printf("%c", decrypt(cipher, keys));

    return 0;
}