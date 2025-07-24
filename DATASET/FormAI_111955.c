//FormAI DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *key = "thereisnohope";
int key_length = 13;

void encrypt(char *message, char *output) {
    int i, j = 0;
    int len = strlen(message);
    for (i = 0; i < len; i++) {
        char c = message[i];
        int k = key[j % key_length];
        j++;
        output[i] = (c ^ k) + (rand() % 10);
    }
}

void decrypt(char *message, char *output) {
    int i, j = 0;
    int len = strlen(message);
    for (i = 0; i < len; i++) {
        int k = key[j % key_length];
        j++;
        output[i] = (message[i] - (rand() % 10)) ^ k;
    }
    output[len] = '\0';
}

int main() {
    char message[1000];
    char encrypted_message[1000];
    char decrypted_message[1000];

    printf("Enter your message:\n");
    scanf("%[^\n]", message);

    encrypt(message, encrypted_message);
    printf("\nEncrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, decrypted_message);
    printf("\nDecrypted message: %s\n", decrypted_message);

    return 0;
}