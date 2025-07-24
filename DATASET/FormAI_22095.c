//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the prime number
#define P 61
#define G 31
#define SECRET_A 23

// Function to calculate the modular exponentiation
long long int modular_exponentiation(long long int base, long long int exponent, long long int modulo) {
    long long int result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulo;
        }

        exponent = exponent / 2;
        base = (base * base) % modulo;
    }

    return result;
}

// Function to generate the public key
long long int generate_public_key(long long int secret) {
    long long int public_key = modular_exponentiation(G, secret, P);
    return public_key;
}

// Function to generate the shared secret
long long int generate_shared_secret(long long int public_key, long long int secret) {
    long long int shared_secret = modular_exponentiation(public_key, secret, P);
    return shared_secret;
}

int main(void) {
    // Generate the public key for Alice
    long long int alice_public_key = generate_public_key(SECRET_A);

    // Generate the public key for Bob
    long long int bob_secret_b = rand() % P;
    long long int bob_public_key = generate_public_key(bob_secret_b);

    // Generate the shared secret for Alice
    long long int alice_shared_secret = generate_shared_secret(bob_public_key, SECRET_A);

    // Generate the shared secret for Bob
    long long int bob_shared_secret = generate_shared_secret(alice_public_key, bob_secret_b);

    // Print the results
    printf("Alice Public Key: %lld\n", alice_public_key);
    printf("Bob Public Key: %lld\n", bob_public_key);
    printf("Alice shared secret: %lld\n", alice_shared_secret);
    printf("Bob shared secret: %lld\n", bob_shared_secret);

    return 0;
}