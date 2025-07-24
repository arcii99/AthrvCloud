//FormAI DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *message, char *key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);
    int i, j;

    for(i = 0, j = 0; i < msg_len; ++i, ++j) {
        if(j == key_len) {
            j = 0;
        }
        message[i] = (message[i] + key[j]) % 128;
    }
}

void decrypt(char *message, char *key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);
    int i, j;

    for(i = 0, j = 0; i < msg_len; ++i, ++j) {
        if(j == key_len) {
            j = 0;
        }
        message[i] = (message[i] - key[j] + 128) % 128;
    }
}

int main() {
    char message[1000], key[1000];
    
    printf("Enter message: ");
    fgets(message, 1000, stdin);

    printf("Enter key: ");
    fgets(key, 1000, stdin);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}