//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1024

void generate_key(char* key, int key_len) {
    srand(time(NULL));
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char* msg, int msg_len, char* key, int key_len) {
    for (int i = 0; i < msg_len; i++) {
        msg[i] ^= key[i % key_len];
    }
}

void decrypt(char* msg, int msg_len, char* key, int key_len) {
    encrypt(msg, msg_len, key, key_len);
}

int main() {
    char message[MAX_LEN];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LEN, stdin);
    strtok(message, "\n");

    int len = strlen(message);

    char key[len];
    generate_key(key, len);

    encrypt(message, len, key, len);

    printf("Encrypted message:\n");
    for (int i = 0; i < len; i++) {
        printf("%02X ", message[i]);
    }
    printf("\n");

    decrypt(message, len, key, len);

    printf("Decrypted message:\n");
    printf("%s\n", message);

    return 0;
}