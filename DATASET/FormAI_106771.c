//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PRIME_LOWER_BOUND 1000
#define PRIME_UPPER_BOUND 10000

// Returns 1 if num is prime, 0 otherwise
int is_prime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Returns a random prime number between PRIME_LOWER_BOUND and PRIME_UPPER_BOUND
int generate_prime() {
    int num;
    do {
        num = (rand() % (PRIME_UPPER_BOUND - PRIME_LOWER_BOUND + 1)) + PRIME_LOWER_BOUND;
    } while (!is_prime(num));
    return num;
}

// Returns the greatest common divisor of a and b
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Generates the public and private keys for the RSA algorithm
void generate_key_pair(int *public_key, int *private_key) {
    srand(time(NULL));
    int p = generate_prime();
    int q = generate_prime();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e;
    do {
        e = (rand() % (phi - 2)) + 2;
    } while (gcd(e, phi) != 1);
    int d;
    int k = 1;
    do {
        d = (1 + k * phi) / e;
        k++;
    } while ((d * e) % phi != 1);
    *public_key = e;
    *private_key = d;
}

// Encrypts a message with the given public key
int encrypt(int message, int public_key, int modulus) {
    int encrypted = 1;
    int i;
    for (i = 0; i < public_key; i++) {
        encrypted = (encrypted * message) % modulus;
    }
    return encrypted;
}

// Decrypts a message with the given private key
int decrypt(int message, int private_key, int modulus) {
    int decrypted = 1;
    int i;
    for (i = 0; i < private_key; i++) {
        decrypted = (decrypted * message) % modulus;
    }
    return decrypted;
}

// Example usage
int main() {
    int public_key, private_key;
    generate_key_pair(&public_key, &private_key);
    printf("Public key: %d\nPrivate key: %d\n", public_key, private_key);
    int message = 1234;
    int modulus = 35821;
    int encrypted = encrypt(message, public_key, modulus);
    int decrypted = decrypt(encrypted, private_key, modulus);
    printf("Original message: %d\nEncrypted message: %d\nDecrypted message: %d\n", message, encrypted, decrypted);
    return 0;
}