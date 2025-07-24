//FormAI DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *message, char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;
 
    for(i = 0, j = 0; i < messageLen; ++i, ++j) {
        if(j == keyLen) {
            j = 0;
        }
        message[i] = ((message[i] - 'A' + key[j] - 'A') % 26) + 'A';
    }
}

void decrypt(char *message, char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;
 
    for(i = 0, j = 0; i < messageLen; ++i, ++j) {
        if(j == keyLen) {
            j = 0;
        }
        message[i] = (((message[i] - 'A') - (key[j] - 'A')) + 26) % 26 + 'A';
    }
}

int main() {
    char message[100];
    char key[100];
    printf("Enter message to encrypt:\n");
    fgets(message, 100, stdin);
    printf("Enter key:\n");
    fgets(key, 100, stdin);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}