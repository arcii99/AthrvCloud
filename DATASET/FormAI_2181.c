//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function declarations
bool isKeyValid(char *key);
void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

// main function
int main() {
    char message[100];
    char key[26];

    // Get the message
    printf("Enter message to be encrypted: ");
    fgets(message, 100, stdin);

    // Remove the newline character in the message
    if ((strlen(message) > 0) && (message[strlen(message) - 1] == '\n')) {
        message[strlen(message) - 1] = '\0';
    }

    // Get the encryption key
    printf("Enter encryption key: ");
    fgets(key, 26, stdin);

    // Remove the newline character in the key
    if ((strlen(key) > 0) && (key[strlen(key) - 1] == '\n')) {
        key[strlen(key) - 1] = '\0';
    }

    // Check if key is valid
    if (!isKeyValid(key)) {
        printf("Invalid key. Please use only 26 unique alphabets.\n");
        return 1;
    }

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}

/**
 * Check if the encryption key is valid.
 * Return true if it contains exactly 26 unique alphabets.
 */
bool isKeyValid(char *key) {
    int frequency[26] = {0};
    int i, len;

    len = strlen(key);

    // Check if key contains exactly 26 characters
    if (len != 26) {
        return false;
    }

    for (i = 0; i < len; i++) {
        // Check if character is an alphabet
        if (!isalpha(key[i])) {
            return false;
        }

        // Convert alphabet to upper case
        key[i] = toupper(key[i]);

        // Check if alphabet is unique
        if (frequency[key[i] - 'A'] > 0) {
            return false;
        }

        frequency[key[i] - 'A']++; // Mark alphabet as used
    }

    return true;
}

/**
 * Encrypt the given message using the given key.
 * This uses the simple substitution cipher algorithm.
 */
void encrypt(char *message, char *key) {
    int i, j, len;

    len = strlen(message);

    for (i = 0; i < len; i++) {
        // Convert the alphabet to upper case
        message[i] = toupper(message[i]);

        // Check if character is an alphabet
        if (isalpha(message[i])) {
            // Encrypt the alphabet using the key
            message[i] = key[message[i] - 'A'];
        }
    }
}

/**
 * Decrypt the given message using the given key.
 * This uses the simple substitution cipher algorithm.
 */
void decrypt(char *message, char *key) {
    int i, j, len;

    len = strlen(message);

    for (i = 0; i < len; i++) {
        // Convert the alphabet to upper case
        message[i] = toupper(message[i]);

        // Check if character is an alphabet
        if (isalpha(message[i])) {
            // Find the position of the alphabet in the key
            for (j = 0; j < 26; j++) {
                if (key[j] == message[i]) {
                    message[i] = 'A' + j;
                    break;
                }
            }
        }
    }
}