//FormAI DATASET v1.0 Category: Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MSG_LEN 1000

void encrypt(char* message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        if(isalpha(message[i])) {
            message[i] = toupper(message[i]);
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
    }
}

void decrypt(char* message, int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        if(isalpha(message[i])) {
            message[i] = toupper(message[i]);
            message[i] = ((message[i] - 'A') + 26 - key) % 26 + 'A';
        }
    }
}

int main() {
    char message[MAX_MSG_LEN];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MSG_LEN, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}