//FormAI DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define KEY "my_secret_key"
#define MAX_LENGTH 100

void encryption(char *plain_text, char *cipher_text);
void decryption(char *cipher_text, char *plain_text);

int main() {
    char plain_text[MAX_LENGTH], cipher_text[MAX_LENGTH];

    printf("Enter plain text to be encrypted: ");
    fgets(plain_text, MAX_LENGTH, stdin);

    encryption(plain_text, cipher_text);
    printf("Cipher text: %s\n", cipher_text);

    decryption(cipher_text, plain_text);
    printf("Plain text: %s\n", plain_text);

    return 0;
}

void encryption(char *plain_text, char *cipher_text) {
    int key_length = strlen(KEY);
    int text_length = strlen(plain_text);
    int i, j;

    for (i = 0, j = 0; i < text_length; ++i, ++j) {
        if (j == key_length) j = 0;
        cipher_text[i] = plain_text[i] + KEY[j];
    }
    cipher_text[i] = '\0';
}

void decryption(char *cipher_text, char *plain_text) {
    int key_length = strlen(KEY);
    int text_length = strlen(cipher_text);
    int i, j;

    for (i = 0, j = 0; i < text_length; ++i, ++j) {
        if (j == key_length) j = 0;
        plain_text[i] = cipher_text[i] - KEY[j];
    }
    plain_text[i] = '\0';
}