//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the public-key algorithm
#define PRIME_1 17
#define PRIME_2 13
#define PUBLIC_KEY 7

// Function prototypes
int gcd(int x, int y);
int generate_private_key(int phi);
int encrypt_message(int message);
int decrypt_message(int message, int private_key);

// Main function
int main() {
    printf("Welcome to the post-apocalyptic Public-Key Algorithm implementation.\n");
    printf("Please enter your message: ");
    
    char message[100];
    fgets(message, 100, stdin);

    // Remove the newline character from the end of the message
    message[strcspn(message, "\n")] = 0;

    // Convert the message to an integer
    int num_message = atoi(message);

    // Encrypt the message using the public key
    int encrypted_message = encrypt_message(num_message);

    // Generate the private key using Euler's totient function
    int phi = (PRIME_1 - 1) * (PRIME_2 - 1);
    int private_key = generate_private_key(phi);

    // Decrypt the message using the private key
    int decrypted_message = decrypt_message(encrypted_message, private_key);

    printf("Your original message: %d\n", num_message);
    printf("Your encrypted message: %d\n", encrypted_message);
    printf("Your decrypted message: %d\n", decrypted_message);

    return 0;
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int x, int y) {
    while(y != 0) {
        int remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

// Function to generate the private key using Euler's totient function
int generate_private_key(int phi) {
    int i;
    for(i = 2; i < phi; i++) {
        if(gcd(i, phi) == 1) {
            return i;
        }
    }
    return 1;
}

// Function to encrypt the message using the public key
int encrypt_message(int message) {
    int encrypted_message = 1;
    int i;
    for(i = 0; i < PUBLIC_KEY; i++) {
        encrypted_message *= message;
        encrypted_message %= (PRIME_1 * PRIME_2);
    }
    return encrypted_message;
}

// Function to decrypt the message using the private key
int decrypt_message(int message, int private_key) {
    int decrypted_message = 1;
    int i;
    for(i = 0; i < private_key; i++) {
        decrypted_message *= message;
        decrypted_message %= (PRIME_1 * PRIME_2);
    }
    return decrypted_message;
}