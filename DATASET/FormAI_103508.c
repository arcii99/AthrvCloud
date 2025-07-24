//FormAI DATASET v1.0 Category: Encryption ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000  // Maximum number of characters to encrypt

void xor_encrypt(char* input_text, char* encryption_key, char* output_text);

int main() {

    char input_text[MAX_SIZE];
    char encryption_key[MAX_SIZE];
    char output_text[MAX_SIZE];
    int input_length, key_length;

    // Get input from user
    printf("Enter the text to be encrypted (max %d characters): ", MAX_SIZE);
    fgets(input_text, MAX_SIZE, stdin);
    input_length = strlen(input_text);

    printf("Enter the encryption key: ");
    fgets(encryption_key, MAX_SIZE, stdin);
    key_length = strlen(encryption_key);

    // Perform an XOR encryption
    xor_encrypt(input_text, encryption_key, output_text);

    printf("Original text: %s\n", input_text);
    printf("Encryption key: %s\n", encryption_key);
    printf("Encrypted text: %s\n", output_text);

    return 0;
}

// XOR Encryption function
void xor_encrypt(char* input_text, char* encryption_key, char* output_text) {

    int i, j, key_length;
    key_length = strlen(encryption_key);

    for(i = 0, j = 0; i < strlen(input_text); ++i, ++j) {
        if(j == key_length) j = 0;
        output_text[i] = input_text[i] ^ encryption_key[j];
    }
    output_text[i] = '\0';
}