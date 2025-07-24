//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int gcd(int a, int b) {
    int t;

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int powmod(int base, int exponent, int modulus) {
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

bool is_prime(int num) {
    if (num == 2 || num == 3) {
        return true;
    }

    if (num == 1 || num % 2 == 0) {
        return false;
    }

    int i;

    for (i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int generate_prime(int min, int max) {
    int num;

    do {
        num = rand() % (max - min) + min;
    } while (!is_prime(num));

    return num;
}

int generate_coprime(int num) {
    int coprime;

    do {
        coprime = rand() % num;
    } while (gcd(num, coprime) != 1);

    return coprime;
}

int main() {
    // Generate two prime numbers
    int p = generate_prime(10000, 20000);
    int q = generate_prime(10000, 20000);

    // Calculate n and phi
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Generate public and private keys
    int e = generate_coprime(phi);
    int d = 0;

    while ((d * e) % phi != 1) {
        d++;
    }

    // Print out keys
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    // Message to encrypt
    char message[] = "Hello, world!";

    // Convert message to ASCII code
    int message_len = strlen(message);
    int ascii_codes[message_len];

    for (int i = 0; i < message_len; i++) {
        ascii_codes[i] = (int) message[i];
    }

    // Encrypt message
    int encrypted[message_len];

    for (int i = 0; i < message_len; i++) {
        encrypted[i] = powmod(ascii_codes[i], e, n);
    }

    // Print out encrypted message
    printf("Encrypted message: ");

    for (int i = 0; i < message_len; i++) {
        printf("%d ", encrypted[i]);
    }

    printf("\n");

    // Decrypt message
    char decrypted[message_len];

    for (int i = 0; i < message_len; i++) {
        decrypted[i] = (char) powmod(encrypted[i], d, n);
    }

    // Print out decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}