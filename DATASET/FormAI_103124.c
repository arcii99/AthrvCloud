//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PRIME_MAX 1000000
#define MSG_MAX 100

// Returns 1 if n is a prime number, 0 otherwise.
int is_prime(int n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    for (int i = 3; i <= n / i; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Generates a random prime number within the specified range.
int generate_prime(int min, int max) {
    int n = rand() % (max - min + 1) + min;
    while (!is_prime(n)) {
        n = rand() % (max - min + 1) + min;
    }
    return n;
}

// Returns gcd of a and b.
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Returns a random number within the specified range
int generate_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator with a random value.
    srand(time(NULL));

    // Generate two random primes within the specified range.
    int p = generate_prime(100, PRIME_MAX);
    int q = generate_prime(100, PRIME_MAX);

    // Calculate n and phi(n), which are used in the public and private keys.
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose a random number e that is relatively prime to phi(n).
    int e = generate_random(2, phi);
    while (gcd(e, phi) != 1) {
        e = generate_random(2, phi);
    }

    // Calculate the modular multiplicative inverse of e mod phi(n) to get d.
    int d;
    for (d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            break;
        }
    }

    // Print the generated values.
    printf("p: %d\n", p);
    printf("q: %d\n", q);
    printf("n: %d\n", n);
    printf("phi(n): %d\n", phi);
    printf("e: %d\n", e);
    printf("d: %d\n", d);

    // Encrypt a message using the public key (n, e).
    char message[MSG_MAX];
    printf("Enter a message to encrypt (max length %d): ", MSG_MAX - 1);
    fgets(message, MSG_MAX, stdin);
    int encrypted_msg[MSG_MAX];
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message) - 1; i++) {
        encrypted_msg[i] = 1;
        for (int j = 0; j < e; j++) {
            encrypted_msg[i] = (encrypted_msg[i] * message[i]) % n;
        }
        printf("%d ", encrypted_msg[i]);
    }
    printf("\n");

    // Decrypt the encrypted message using the private key d.
    printf("Decrypted message: ");
    for (int i = 0; i < strlen(message) - 1; i++) {
        int decrypted_msg = 1;
        for (int j = 0; j < d; j++) {
            decrypted_msg = (decrypted_msg * encrypted_msg[i]) % n;
        }
        printf("%c", decrypted_msg);
    }
    printf("\n");

    return 0;
}