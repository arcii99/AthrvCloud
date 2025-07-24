//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Algorithm parameters
#define P_MIN 100
#define P_MAX 999
#define G 2

// Public and private keys
int g_private_key;
int g_public_key;

// Functions for generating random prime number
bool is_prime(int num) {
    if (num < 2) return false;
    int div = 2;
    while (div <= sqrt(num)) {
        if (num % div == 0) return false;
        div++;
    }
    return true;
}

int generate_prime(int min, int max) {
    int num = rand() % (max - min) + min;
    while (!is_prime(num)) {
        num = rand() % (max - min) + min;
    }
    return num;
}

// Function for calculating modular exponentiation
int mod_exp(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b / 2;
    }
    return res;
}

// Function for calculating public key
int generate_public_key(int private_key, int p) {
    return mod_exp(G, private_key, p);
}

// Function for calculating shared secret
int generate_shared_secret(int private_key, int public_key, int p) {
    return mod_exp(public_key, private_key, p);
}

int main() {
    srand(time(NULL)); // Initialize random seed

    // Generate random prime number p
    int p = generate_prime(P_MIN, P_MAX);

    // Generate private key and public key
    g_private_key = rand() % (p-2) + 1; // 1 <= private_key <= p-2
    g_public_key = generate_public_key(g_private_key, p);

    // Output public key and prime number p
    printf("Public key: %d\n", g_public_key);
    printf("Prime number: %d\n", p);

    // User enters their private key
    printf("Enter your private key: ");
    int private_key;
    scanf("%d", &private_key);

    // Generate shared secret and output it
    int shared_secret = generate_shared_secret(private_key, g_public_key, p);
    printf("Shared secret: %d\n", shared_secret);

    return 0;
}