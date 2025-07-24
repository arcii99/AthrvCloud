//FormAI DATASET v1.0 Category: Encryption ; Style: unmistakable
#include<stdio.h>
#include<string.h>

void encryption(char*);

int main() {
    char message[100];

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    printf("Original message: %s", message);

    encryption(message);

    printf("Encrypted message: %s\n", message);

    return 0;
}

// Function to perform encryption using XOR operation with a key
void encryption(char* message) {
    char key[11] = "encryption";
    int keyLength = strlen(key);
    int messageLength = strlen(message);

    // Apply XOR operation with the key on each character of the message
    // repeating the key if necessary
    for(int i = 0; i < messageLength; i++) {
        message[i] = message[i] ^ key[i % keyLength];
    }

    // Add a flag at the end of the message to signal that it is encrypted
    strcat(message, "_enc");
}