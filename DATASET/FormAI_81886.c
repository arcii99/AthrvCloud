//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_SIZE 16

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Generate a random key
    char key[KEY_SIZE + 1]; // Make space for null terminator
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // Choose a random ASCII code
    }
    key[KEY_SIZE] = '\0';
    
    printf("Generated key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02X", key[i]); // Print the key as two-digit hex numbers
    }
    printf("\n");
    
    // Get a message to encrypt
    char message[101];
    printf("Enter a message to encrypt (100 characters or less): ");
    fgets(message, sizeof(message), stdin);
    // Remove newline character at the end of the message
    message[strcspn(message, "\n")] = '\0';
    
    // Encrypt the message using the key
    for (int i = 0; i < strlen(message); i++) {
        message[i] ^= key[i % KEY_SIZE]; // XOR each character with the corresponding key character
    }
    
    // Print the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%02X", message[i]); // Print each character as a two-digit hex number
    }
    printf("\n");
    
    // Get the key from the user
    char userKey[KEY_SIZE + 1];
    printf("Enter the key to decrypt the message: ");
    fgets(userKey, sizeof(userKey), stdin);
    // Remove newline character at the end of the key
    userKey[strcspn(userKey, "\n")] = '\0';
    
    // Check if the user key matches the generated key
    if (strcmp(key, userKey) != 0) {
        printf("Incorrect key! Exiting...\n");
        return 0;
    }
    
    // Decrypt the message using the key
    for (int i = 0; i < strlen(message); i++) {
        message[i] ^= key[i % KEY_SIZE]; // XOR each character with the corresponding key character
    }
    
    // Print the decrypted message
    printf("Decrypted message: %s", message);
    
    return 0;
}