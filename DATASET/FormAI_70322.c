//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's create a struct for our public and private key pairs
typedef struct {
    int public_key;
    int private_key;
} KeyPair;

// Function to generate a random prime number
int generatePrime() {
    srand(time(NULL));
    int num = rand() % 100;
    while (num < 2 || num % 2 == 0) {
        num = rand() % 100;
    }
    int i;
    for (i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            num = generatePrime();
            break;
        }
    }
    return num;
}

// Function to generate the keys
KeyPair generateKeys() {
    KeyPair keys;
    int prime1, prime2, phi, n, e, d;
    // Generate two distinct random primes
    prime1 = generatePrime();
    prime2 = generatePrime();
    while (prime1 == prime2) {
        prime2 = generatePrime();
    }
    // Calculate n and phi
    n = prime1 * prime2;
    phi = (prime1 - 1) * (prime2 - 1);
    // Choose a random e coprime to phi
    srand(time(NULL));
    e = rand() % (phi - 2) + 2;
    while (e >= phi || gcd(e, phi) != 1) {
        e = rand() % (phi - 2) + 2;
    }
    // Calculate d as the inverse of e modulo phi
    d = modInverse(e, phi);
    // Set the keys
    keys.public_key = n;
    keys.private_key = d;
    printf("Public key: %d\nPrivate key: %d\n", keys.public_key, keys.private_key);
    return keys;
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;
        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    // Make x1 positive
    if (x1 < 0) {
        x1 += m0;
    }
    return x1;
}

// Main function to use the keys
int main() {
    KeyPair keys = generateKeys();
    int message;
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    int encrypted_message = encrypt(message, keys.public_key);
    printf("Encrypted message: %d\n", encrypted_message);
    int decrypted_message = decrypt(encrypted_message, keys.private_key, keys.public_key);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}

// Function to encrypt a message using the public key
int encrypt(int message, int public_key) {
    return modPow(message, public_key, public_key);
}

// Function to decrypt a message using the private key and public key
int decrypt(int encrypted_message, int private_key, int public_key) {
    return modPow(encrypted_message, private_key, public_key);
}

// Function to calculate the modular exponentiation
int modPow(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}