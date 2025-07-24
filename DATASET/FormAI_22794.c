//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
char* encrypt(char* plain_text, char* key){

    // Length of plaintext and key
    int pt_len = strlen(plain_text);
    int key_len = strlen(key);

    // Copying key to make it same length as plaintext
    char* expanded_key = (char*)malloc(pt_len * sizeof(char));
    for(int i=0; i<pt_len; i++){
        expanded_key[i] = key[i % key_len];
    }

    // Encrypting plain text using XOR operation
    char* cipher_text = (char*)malloc(pt_len * sizeof(char));
    for(int i=0; i<pt_len; i++){
        cipher_text[i] = plain_text[i] ^ expanded_key[i];
    }

    // Free the memory used by expanded_key
    free(expanded_key);
    return cipher_text;
}

int main(){

    // Input plaintext and key
    char plain_text[100], key[100];
    printf("Enter plain text: ");
    scanf("%s", plain_text);
    printf("Enter key: ");
    scanf("%s", key);

    // Performing encryption
    char* cipher_text = encrypt(plain_text, key);

    // Displaying cipher text
    printf("Cipher text: %s\n", cipher_text);

    // Free the memory used by cipher_text
    free(cipher_text);

    return 0;
}