//FormAI DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, int key) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        // Shift each character by the key
        input[i] = (input[i] + key) % 256;
    }
}

void decrypt(char *input, int key) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        // Shift each character back by the key
        input[i] = (input[i] - key + 256) % 256;
    }
}

int main() {
    char input[100];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(input, 100, stdin);

    printf("Enter a key: ");
    scanf("%d", &key);

    // Encrypt the string
    encrypt(input, key);
    printf("Encrypted: %s\n", input);

    // Decrypt the string
    decrypt(input, key);
    printf("Decrypted: %s\n", input);

    return 0;
}