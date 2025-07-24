//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *msg, int key) {
    int len = strlen(msg);
    for(int i = 0; i < len; i++) {
        msg[i] = (msg[i] + key) % 256;
    }
}

void decrypt(char *msg, int key) {
    int len = strlen(msg);
    for(int i = 0; i < len; i++) {
        msg[i] = (msg[i] - key + 256) % 256;
    }
}

int main() {

    char msg[1000];
    int key;

    printf("Enter message to encrypt: ");
    gets(msg);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(msg, key);
    printf("Encrypted message: %s\n", msg);

    decrypt(msg, key);
    printf("Decrypted message: %s\n", msg);

    return 0;
}