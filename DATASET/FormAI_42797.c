//FormAI DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <string.h>

void encrypt(char* message, int key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        // shifting each character by key value
        if (message[i] >= 'a' && message[i] <= 'z') {
            // wrap around the alphabet
            message[i] = (((message[i] - 'a') + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            // wrap around the alphabet
            message[i] = (((message[i] - 'A') + key) % 26) + 'A';
        }
    }
}

void decrypt(char* message, int key) {
    // decrypting is the same as encrypting but with the opposite key value
    encrypt(message, 26 - key);
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter a key (integer between 1 and 25): ");
    scanf("%d", &key);

    if (key < 1 || key > 25) {
        printf("Invalid key value. Please enter a integer between 1 and 25.\n");
        return 1;
    }

    printf("\nOriginal message: %s", message);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}