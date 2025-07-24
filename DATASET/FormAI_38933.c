//FormAI DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *message, int key) {
    int i;

    // Loop through each character of the message
    for (i = 0; i < strlen(message); i++) {
        // If the character is a lowercase letter
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        // If the character is an uppercase letter
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

int main() {
    char message[100];
    int key;

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Remove the newline character from the end of the string
    if (message[strlen(message)-1] == '\n') {
        message[strlen(message)-1] = '\0';
    }

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s", message);

    return 0;
}