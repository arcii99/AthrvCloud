//FormAI DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, int key) {
    int len = strlen(plaintext);
    char ciphertext[len];
    for(int i = 0; i < len; i++) {
        ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
    }
    printf("Encrypted Text: %s\n", ciphertext);
}

void decrypt(char *ciphertext, int key) {
    int len = strlen(ciphertext);
    char plaintext[len];
    for(int i = 0; i < len; i++) {
        plaintext[i] = (ciphertext[i] - 'a' - key + 26) % 26 + 'a';
    }
    printf("Decrypted Text: %s\n", plaintext);
}



int main() {
    char input[100];
    int key;
    printf("Enter the text to be encrypted: ");
    scanf("%[^\n]", input);
    printf("Enter the key: ");
    scanf("%d", &key);
    printf("\n");
    encrypt(input, key);
    printf("\n");
    decrypt(input, key);

    return 0;
}