//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include<stdio.h>
#include<string.h>

void encrypt(char *msg, int key) {
    int len = strlen(msg);
    for(int i = 0; i < len; i++) {
        msg[i] += key;
    }
}

void decrypt(char *msg, int key) {
    int len = strlen(msg);
    for(int i = 0; i < len; i++) {
        msg[i] -= key;
    }
}

int main() {
    char msg[100];
    int key;
    printf("Enter a message to encrypt: ");
    gets(msg);
    printf("Enter key: ");
    scanf("%d", &key);

    // encryption
    encrypt(msg, key);
    printf("Encrypted message: %s\n", msg);

    // decryption
    decrypt(msg, key);
    printf("Decrypted message: %s\n", msg);

    return 0;
}