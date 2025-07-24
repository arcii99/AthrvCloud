//FormAI DATASET v1.0 Category: modern Encryption ; Style: complex
#include <stdio.h>
#include <string.h>

// function to perform encryption
void performEncryption(char message[], int key) {
    char encryptedMessage[strlen(message)];
    int i;

    // iterate over each character in message
    for (i = 0; i < strlen(message); i++) {
        // shift the character by key positions
        encryptedMessage[i] = message[i] + key;

        // if the shifted character exceeds z or Z by 1, wrap to a or A
        if (encryptedMessage[i] > 'z') {
            encryptedMessage[i] = encryptedMessage[i] - 'z' + 'a' - 1;
        } else if (encryptedMessage[i] > 'Z' && encryptedMessage[i] <= 'z') {
            encryptedMessage[i] = encryptedMessage[i] - 'Z' + 'A' - 1;
        }
    }

    // print the encrypted message
    printf("Encrypted message: %s\n", encryptedMessage);
}

int main() {
    char message[1000];
    int key;

    // get initial message from user
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // get encryption key from user
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // perform encryption
    performEncryption(message, key);

    return 0;
}