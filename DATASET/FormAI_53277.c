//FormAI DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char message[], char key[]) {
    //Converts the ascii characters to their corresponding numeric values
    int message_num[strlen(message)];
    int key_num[strlen(key)];
    int encrypted[strlen(message)];

    for (int i = 0; i < strlen(message); i++) {
        message_num[i] = (int) message[i];
    }

    for (int i = 0; i < strlen(key); i++) {
        key_num[i] = (int) key[i];
    }

    //Encrypting the message using the key
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = message_num[i] ^ key_num[i % strlen(key)];
    }

    //Converts the numeric values back to ascii characters
    char* result = (char*) malloc(strlen(message) * sizeof(char));
    for (int i = 0; i < strlen(message); i++) {
        result[i] = (char) encrypted[i];
    }

    return result;
}

int main() {
    char message[100], key[100];
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    printf("Enter the key: ");
    fgets(key, 100, stdin);

    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s", encrypted_message);

    free(encrypted_message);
    return 0;
}