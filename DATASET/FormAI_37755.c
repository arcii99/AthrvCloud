//FormAI DATASET v1.0 Category: modern Encryption ; Style: excited
#include<stdio.h>

void Encrypt(char msg[], int key) {
    int i;
    for(i = 0; msg[i] != '\0'; i++) {
        msg[i] = (msg[i] << 2) ^ key;
    }
}

void Decrypt(char msg[], int key) {
    int i;
    for(i = 0; msg[i] != '\0'; i++) {
        msg[i] = (msg[i] ^ key) >> 2;
    }
}

int main() {
    char msg[100];
    int key = 1234;

    printf("Enter a message to encrypt: ");
    fgets(msg, 100, stdin);
    
    Encrypt(msg, key);
    printf("Encrypted message: %s", msg);

    Decrypt(msg, key);
    printf("Decrypted message: %s", msg);
    
    return 0;
}