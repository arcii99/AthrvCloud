//FormAI DATASET v1.0 Category: modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
void encrypt(char message[], char key[]) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    char encrypted_message[message_len+1];

    // Iterate over each character in the message
    for (int i = 0; i < message_len; i++) {

        // Get the ASCII value of the character
        int message_char = message[i];
        int key_char = key[i%key_len];

        // Perform XOR operation on the characters
        int encrypted_char = message_char ^ key_char;
        encrypted_message[i] = encrypted_char;
    }

    encrypted_message[message_len] = '\0'; // Add null terminator
    printf("Encrypted Message: %s\n", encrypted_message);
}

int main() {
    char message[100], key[100];

    // Get message from user input
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character at the end

    // Get key from user input
    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character at the end

    encrypt(message, key); // Call encryption function

    return 0; // End of program
}