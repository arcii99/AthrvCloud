//FormAI DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <string.h>

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    for(int i=0; i<message_length; i++) {
        message[i] = message[i] ^ key[i % key_length];
    }
}

void decrypt(char* message, char* key) {
    encrypt(message, key); // Since XOR is a reversible operation, we can reapply it to decrypt
}

int main() {
    // User inputs the message and key
    char message[100];
    char key[50];
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove the newline character at the end of the input
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    printf("Original message: %s\n", message);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message); // Print the encrypted message

    decrypt(message, key);
    printf("Decrypted message: %s\n", message); // Print the decrypted message

    return 0;
}