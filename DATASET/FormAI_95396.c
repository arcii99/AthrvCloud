//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random number between min and max (inclusive)
int generate_random_number(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

// Check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Find a primitive root for a prime number
int find_primitive_root(int p) {
    int phi = p - 1;
    int primitive_root;
    int primitive_roots[phi];
    int count = 0;
    for (int i = 1; i <= phi; i++) {
        int is_primitive_root = 1;
        for (int j = 0; j < count; j++) {
            if (i == primitive_roots[j]) {
                is_primitive_root = 0;
                break;
            }
            int a = primitive_roots[j];
            int b = phi;
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            if (i == a) {
                is_primitive_root = 0;
                break;
            }
        }
        if (is_primitive_root) {
            // Check if i is a primitive root
            int powers[phi];
            for (int j = 0; j < phi; j++) {
                powers[j] = 0;
            }
            for (int j = 1; j <= phi; j++) {
                int result = 1;
                for (int k = 0; k < j; k++) {
                    result = (result * i) % p;
                }
                powers[result - 1] = 1;
            }
            int is_primitive_root = 1;
            for (int j = 0; j < phi; j++) {
                if (powers[j] == 0) {
                    is_primitive_root = 0;
                    break;
                }
            }
            if (is_primitive_root) {
                primitive_root = i;
                break;
            }
            primitive_roots[count] = i;
            count++;
        }
    }
    return primitive_root;
}

// Calculate a^b mod p
int mod_pow(int a, int b, int p) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % p;
        }
        a = (a * a) % p;
        b /= 2;
    }
    return result;
}

int main() {
    // Generate a random prime number
    srand(time(NULL));
    int min = 100;
    int max = 1000;
    int p;
    do {
        p = generate_random_number(min, max);
    } while (!is_prime(p));

    // Find a primitive root for p
    int g = find_primitive_root(p);

    printf("Public Key Algorithm Implementation\n\n");
    printf("p = %d\n", p);
    printf("g = %d\n", g);

    // Generate a random secret key
    int a = generate_random_number(1, p-1);

    printf("Private key (a) = %d\n", a);

    // Calculate the public key
    int A = mod_pow(g, a, p);

    printf("Public key (A) = %d\n", A);

    // Send the public key (A) to the recipient

    // Recipient calculates their private key
    int b = generate_random_number(1, p-1);

    printf("Recipient's private key (b) = %d\n", b);

    // Calculate the recipient's public key
    int B = mod_pow(g, b, p);

    printf("Recipient's public key (B) = %d\n\n", B);

    // Calculate the shared secret key
    int shared_secret_key_1 = mod_pow(B, a, p);
    int shared_secret_key_2 = mod_pow(A, b, p);

    printf("Shared secret key = %d\n", shared_secret_key_1);
    printf("Shared secret key = %d\n", shared_secret_key_2);

    return 0;
}