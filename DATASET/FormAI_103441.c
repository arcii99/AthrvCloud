//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate a random prime number
int generate_prime() {
    int n = rand() % 500 + 500; // generate random number between 500 and 999
    while (!is_prime(n)) {
        n++;
    }
    return n;
}

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to generate a random number coprime to n
int generate_coprime(int n) {
    int e = rand() % (n - 1) + 1; // generate random number between 1 and n-1
    while (gcd(n, e) != 1) {
        e++;
    }
    return e;
}

// Function to calculate the modular exponentiation
int mod_exp(int a, int b, int mod) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Generate two random prime numbers: p and q
    int p = generate_prime();
    int q = generate_prime();

    // Calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Generate public key (e)
    int e = generate_coprime(phi);

    // Calculate private key (d)
    int d;
    for (int i = 1; i <= phi; i++) {
        if ((i * e) % phi == 1) {
            d = i;
            break;
        }
    }

    // Print public and private keys
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    // Encrypt a message
    char message[100];
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    int encrypted[100];
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = mod_exp(message[i], e, n);
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    // Decrypt the encrypted message
    char decrypted[100];
    for (int i = 0; i < strlen(message); i++) {
        decrypted[i] = mod_exp(encrypted[i], d, n);
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0;
}