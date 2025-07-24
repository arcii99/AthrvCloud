//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MESSAGE_LENGTH 100

/* Function to encrypt a message using a simple mathematical formula */
char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* encrypted_message = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        encrypted_message[i] = (message[i] ^ key) * (int)pow(2, key % 4);
    }
    encrypted_message[len] = '\0';
    return encrypted_message;
}

/* Function to decrypt an encrypted message using the same key and formula */
char* decrypt(char* encrypted_message, int key) {
    int len = strlen(encrypted_message);
    char* decrypted_message = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        decrypted_message[i] = (encrypted_message[i] / (int)pow(2, key % 4)) ^ key;
    }
    decrypted_message[len] = '\0';
    return decrypted_message;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int key = 5;
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s", message);

    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}