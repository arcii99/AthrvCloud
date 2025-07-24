//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* encrypt(char* message, char* key);
char* decrypt(char* message, char* key);

int main() {
    srand(time(NULL)); // Seed the random number generator
    char *message = "Hello, world!"; // Message to encrypt
    char *key = "secret"; // Key to use for encryption
    printf("Original message: %s\n", message);
    char* encrypted = encrypt(message, key); // Encrypt the message
    printf("Encrypted message: %s\n", encrypted);
    char* decrypted = decrypt(encrypted, key); // Decrypt the message
    printf("Decrypted message: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    return 0;
}

char* encrypt(char* message, char* key) {
    int len = strlen(message);
    char* encrypted = malloc(sizeof(char) * (len + 1)); // Allocate memory for the encrypted message
    strcpy(encrypted, message); // Initialize the encrypted message with the original message
    int keylen = strlen(key);
    int j = 0;
    for (int i = 0; i < len; i++) {
        encrypted[i] = ((encrypted[i] + key[j]) % 256); // Encrypt each character
        j = (j+1) % keylen; // Rotate through the key
    }
    return encrypted;
}

char* decrypt(char* message, char* key) {
    int len = strlen(message);
    char* decrypted = malloc(sizeof(char) * (len + 1)); // Allocate memory for the decrypted message
    strcpy(decrypted, message); // Initialize the decrypted message with the encrypted message
    int keylen = strlen(key);
    int j = 0;
    for (int i = 0; i < len; i++) {
        decrypted[i] = ((decrypted[i] - key[j] + 256) % 256); // Decrypt each character
        j = (j+1) % keylen; // Rotate through the key
    }
    return decrypted;
}