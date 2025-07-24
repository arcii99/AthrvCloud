//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar; // Define new type for unsigned chars

void encrypt(uchar *text, uchar *key, uchar *cipher, int len) {
    for (int i = 0; i < len; i++) {
        cipher[i] = text[i] ^ key[i % strlen(key)]; // XOR with key
    }
}

int main() {
    char text[1000];
    char key[100];

    printf("Enter text to encrypt: ");
    fgets(text, 1000, stdin);
    printf("Enter encryption key: ");
    fgets(key, 100, stdin);

    int text_len = strlen(text) - 1; // Exclude newline character from input
    int key_len = strlen(key) - 1;

    uchar *text_uc = (uchar *) text; // Convert char arrays to unsigned char arrays for bitwise operations
    uchar *key_uc = (uchar *) key;

    uchar cipher[text_len];

    encrypt(text_uc, key_uc, cipher, text_len);

    printf("\n---------------\n");
    printf("Encrypted text:\n");
    for (int i = 0; i < text_len; i++) {
        printf("%02X ", cipher[i]); // Print out encrypted text in hexadecimal format
    }
    printf("\n---------------\n");

    return 0; // Exit the program
}