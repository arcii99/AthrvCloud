//FormAI DATASET v1.0 Category: Encryption ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i;
    for(i=0; i<message_len; i++) {
        message[i] = message[i] + key[i%key_len];
    }
}
void decrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i;
    for(i=0; i<message_len; i++) {
        message[i] = message[i] - key[i%key_len];
    }
}

int main() {
    char message[100];
    char key[100];
    printf("Enter message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key: ");
    fgets(key, 100, stdin);
    encrypt(message, key);
    printf("Encrypted message: %s", message);
    decrypt(message, key);
    printf("Decrypted message: %s", message);
    return 0;
}