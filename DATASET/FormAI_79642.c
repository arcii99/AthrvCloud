//FormAI DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void encrypt(char* message, char* key) {
    int len_msg = strlen(message);
    int len_key = strlen(key);
    int i, j;

    for(i = 0, j = 0; i < len_msg; ++i, ++j) {
        if(j == len_key) {
            j = 0;
        }
        message[i] = ((message[i] + key[j]) % 128);
    }
}

void decrypt(char* message, char* key) {
    int len_msg = strlen(message);
    int len_key = strlen(key);
    int i, j;

    for(i = 0, j = 0; i < len_msg; ++i, ++j) {
        if(j == len_key) {
            j = 0;
        }
        message[i] = ((message[i] - key[j] + 128) % 128);
    }
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_SIZE, stdin);

    //remove newline character from the input string
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}