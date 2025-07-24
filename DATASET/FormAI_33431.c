//FormAI DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <string.h>

void encrypt(char* message, int key) {
    // Loop through each character in message
    for(int i = 0; i < strlen(message); i++) {
        // Shift the character by key (Caesar Cipher)
        message[i] = ((message[i] - 'a' + key) % 26) + 'a';
    }
}

void decrypt(char* message, int key) {
    // Loop through each character in message
    for(int i = 0; i < strlen(message); i++) {
        // Shift the character by -key (Undo Caesar Cipher)
        message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
    }
}

int main() {
    char message[100];
    int key;

    // Get input from user
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key (1-25): ");
    scanf("%d", &key);

    // Encrypt message
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}