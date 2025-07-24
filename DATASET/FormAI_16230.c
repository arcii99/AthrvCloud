//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int generate_random_prime_number() {
    int prime = rand() % 100 + 1;
    printf("Generated prime number: %d\n", prime);
    return prime;
}

int calculate_public_key(int prime1, int prime2) {
    int public_key = prime1 * prime2;
    printf("Public key is: %d\n", public_key);
    return public_key;
}

int calculate_private_key(int prime1, int prime2) {
    int phi = (prime1 - 1) * (prime2 - 1);
    int private_key = rand() % phi + 1;
    printf("Private key is: %d\n", private_key);
    return private_key;
}

int encrypt_message(int message, int public_key) {
    int encrypted_message = message * public_key;
    printf("Encrypted message is: %d\n", encrypted_message);
    return encrypted_message;
}

int main() {
    printf("***** Welcome to my unique public-key algorithm implementation program *****\n");

    int prime1 = generate_random_prime_number();
    int prime2 = generate_random_prime_number();

    int public_key = calculate_public_key(prime1, prime2);
    int private_key = calculate_private_key(prime1, prime2);

    printf("\nEnter the message you want to encrypt: ");
    int message;
    scanf("%d", &message);

    int encrypted_message = encrypt_message(message, public_key);
    printf("\nEncrypted message: %d\n", encrypted_message);

    printf("\n***** Thank you for using my program *****\n");

    return 0;
}