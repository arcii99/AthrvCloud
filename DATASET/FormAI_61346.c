//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Returns true if n is prime, false otherwise
int isPrime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Generates a prime number between min and max
int generatePrime(int min, int max) {
    int num;
    do {
        num = (rand() % (max - min)) + min;
    } while (!isPrime(num));
    return num;
}

// Returns the greatest common divisor of a and b
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Generates public and private keys for RSA algorithm
void generateKeys(int *public_key, int *private_key, int *n) {
    int p, q, phi, e, d;
    p = generatePrime(100, 1000);
    q = generatePrime(100, 1000);
    *n = p * q;
    phi = (p - 1) * (q - 1);
    e = generatePrime(3, phi-1);
    while (gcd(e, phi) != 1) {
        e = generatePrime(3, phi-1);
    }
    d = 1;
    while ((d * e) % phi != 1 || d == e) {
        d++;
    }
    *public_key = e;
    *private_key = d;
}

// Encrypts the message using RSA algorithm
int encrypt(int message, int public_key, int n) {
    int cipher = pow(message, public_key);
    cipher = cipher % n;
    return cipher;
}

// Decrypts the cipher using RSA algorithm
int decrypt(int cipher, int private_key, int n) {
    int message = pow(cipher, private_key);
    message = message % n;
    return message;
}

int main() {
    srand(time(NULL));
    int public_key, private_key, n, message, cipher;
    generateKeys(&public_key, &private_key, &n);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    printf("n: %d\n", n);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    cipher = encrypt(message, public_key, n);
    printf("Encrypted cipher: %d\n", cipher);
    message = decrypt(cipher, private_key, n);
    printf("Decrypted message: %d\n", message);
    return 0;
}