//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRIME_SIZE 10

// Function to check if a number is prime
int is_prime(int num) {
    int i;
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a prime number
int generate_prime(int lower, int upper) {
    int num;
    do {
        num = rand() % (upper - lower + 1) + lower;
    } while (!is_prime(num));
    return num;
}

// Function to generate public and private keys
void generate_keys(int *e, int *d, int *n) {
    srand(time(NULL));
    int p, q, phi, gcd;
    p = generate_prime(pow(2, PRIME_SIZE - 1), pow(2, PRIME_SIZE));
    q = generate_prime(pow(2, PRIME_SIZE - 1), pow(2, PRIME_SIZE));
    *n = p * q;
    phi = (p - 1) * (q - 1);
    do {
        *e = generate_prime(2, phi - 1);
        gcd = abs((phi * (*d)) % ((*e) * phi));
        *d += 1;
    } while (gcd != 1);
    *d -= 1;
}

// Function to encrypt a message using the public key
int encrypt(int msg, int e, int n) {
    int c = 1, i;
    for (i = 0; i < e; i++) {
        c = (c * msg) % n;
    }
    return c;
}

// Function to decrypt a message using the private key
int decrypt(int c, int d, int n) {
    int m = 1, i;
    for (i = 0; i < d; i++) {
        m = (m * c) % n;
    }
    return m;
}

int main() {
    int e = 0, d = 1, n;
    char msg[100];
    printf("Enter a message: ");
    fgets(msg, 100, stdin);

    // Generate public and private keys
    generate_keys(&e, &d, &n);

    // Encrypt message using public key
    int i, len = strlen(msg), encrypted_msg[len];
    for (i = 0; i < len; i++) {
        encrypted_msg[i] = encrypt(msg[i], e, n);
    }

    // Decrypt message using private key
    char decrypted_msg[len];
    for (i = 0; i < len; i++) {
        decrypted_msg[i] = decrypt(encrypted_msg[i], d, n);
    }

    // Print results
    printf("Public Key: e=%d, n=%d\n", e, n);
    printf("Private Key: d=%d, n=%d\n", d, n);
    printf("Encrypted Message: ");
    for (i = 0; i < len; i++) {
        printf("%d ", encrypted_msg[i]);
    }
    printf("\nDecrypted Message: %s\n", decrypted_msg);

    return 0;
}