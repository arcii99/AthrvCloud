//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: decentralized
// Decentralized Public-Key Algorithm Implementation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRIME_NUM_1 41
#define PRIME_NUM_2 17

typedef struct KeySet {
    int public_key;
    int private_key;
} KeySet;

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int gcd(int a, int b) {
    int temp;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

KeySet generate_keys() {
    KeySet keys;

    int p = PRIME_NUM_1;
    int q = PRIME_NUM_2;

    int n = p * q;
    int phi = (p-1) * (q-1);

    int e = 2;

    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }

        e++;
    }

    int k = 2;

    keys.public_key = e;

    keys.private_key = (k*phi + 1) / e;

    return keys;
}

int encrypt(int msg, int public_key, int n) {
    int result = 1;

    for (int i = 0; i < public_key; i++) {
        result = (result * msg) % n;
    }

    return result;
}

int decrypt(int msg, int private_key, int n) {
    return encrypt(msg, private_key, n);
}

int main() {
    srand(time(0)); // Seed random number generator

    KeySet keys = generate_keys();

    int message = rand() % 100; // Generate random message

    printf("Original message: %d\n", message);

    int encrypted = encrypt(message, keys.public_key, PRIME_NUM_1 * PRIME_NUM_2);

    printf("Encrypted message: %d\n", encrypted);

    int decrypted = decrypt(encrypted, keys.private_key, PRIME_NUM_1 * PRIME_NUM_2);

    printf("Decrypted message: %d\n", decrypted);

    return 0;
}