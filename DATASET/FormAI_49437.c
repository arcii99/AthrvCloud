//FormAI DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>

// function to encrypt the message
void encrypt(char *message, int key) {
    int i = 0;
    // loop through each character of the message
    while (message[i] != '\0') {
        // add the key to the ASCII value of the character
        message[i] += key;
        i++;
    }
}

// function to decrypt the message
void decrypt(char *message, int key) {
    int i = 0;
    // loop through each character of the message
    while (message[i] != '\0') {
        // subtract the key from the ASCII value of the character
        message[i] -= key;
        i++;
    }
}

int main() {
    char message[100];
    int key;

    // get the message and key from the user
    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s", message);

    // decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}