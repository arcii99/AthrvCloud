//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
// Romeo and Juliet Cryptography Implementation
// By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption and decryption
int key = 3;

// Function to encrypt a message
void encrypt(char *message) {
    int i = 0;
    while (message[i] != '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)(((int)message[i] - 'a' + key) % 26 + 'a');
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)(((int)message[i] - 'A' + key) % 26 + 'A');
        }
        i++;
    }
}

// Function to decrypt a message
void decrypt(char *message) {
    int i = 0;
    while (message[i] != '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char)(((int)message[i] - 'a' - key + 26) % 26 + 'a');
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char)(((int)message[i] - 'A' - key + 26) % 26 + 'A');
        }
        i++;
    }
}

// Main function to run the program
int main() {
    char message[100];

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    // Remove the newline character at the end of the input
    message[strcspn(message, "\n")] = 0;

    // Encrypt the message using the key
    encrypt(message);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}