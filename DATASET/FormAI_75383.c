//FormAI DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <string.h>

void encrypt(char* message, char* key) {
    int messagelen = strlen(message);
    int keylen = strlen(key);
    int i, j;

    for(i = 0, j = 0; i < messagelen; i++, j++) {
        if(j >= keylen) {
            j = 0;
        }

        message[i] = ((message[i] - 'a' + key[j] - 'a') % 26) + 'a';
    }
}

void decrypt(char* message, char* key) {
    int messagelen = strlen(message);
    int keylen = strlen(key);
    int i, j;

    for(i = 0, j = 0; i < messagelen; i++, j++) {
        if(j >= keylen) {
            j = 0;
        }

        message[i] = ((message[i] - key[j] + 26) % 26) + 'a';
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key: ");
    fgets(key, 100, stdin);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}