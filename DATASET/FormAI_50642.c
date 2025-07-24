//FormAI DATASET v1.0 Category: Encryption ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *str, int key) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        str[i] = str[i] + key; //shift the ascii code by key
    }
}

void decrypt(char *str, int key) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        str[i] = str[i] - key; //shift the ascii code back by key
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key for encryption: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    decrypt(message, key);
    printf("Decrypted message: %s", message);

    return 0;
}