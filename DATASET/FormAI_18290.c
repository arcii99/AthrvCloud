//FormAI DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <string.h>

/* Function to encrypt the given message */
void encrypt(char message[], int key) {
    int i;
    for(i = 0; i < strlen(message); ++i) {
        /* Shift each character by the key */
        message[i] = message[i] + key;
    }
}

/* Function to decrypt the given message */
void decrypt(char message[], int key) {
    int i;
    for(i = 0; i < strlen(message); ++i) {
        /* Shift each character back by the key */
        message[i] = message[i] - key;
    }
}

int main() {
    char message[100];
    int key;

    /* Get the message and key from the user */
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter a key: ");
    scanf("%d", &key);

    /* Call the encrypt function on the message */
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    /* Call the decrypt function on the encrypted message */
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}