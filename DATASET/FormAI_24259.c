//FormAI DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* plaintext, char* key) {
    int p_len = strlen(plaintext);
    int k_len = strlen(key);
    char* ciphertext = (char*)malloc(sizeof(char)*(p_len+1));

    for(int i = 0; i < p_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % k_len];
    }
    ciphertext[p_len] = '\0';
    return ciphertext;
}

char* decrypt(char* ciphertext, char* key) {
    int c_len = strlen(ciphertext);
    int k_len = strlen(key);
    char* plaintext = (char*)malloc(sizeof(char)*(c_len+1));

    for(int i = 0; i < c_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % k_len];
    }
    plaintext[c_len] = '\0';
    return plaintext;
}

int main() {
    char plaintext[100];
    char key[100];
    printf("Welcome to Curious Encryption!\n");
    printf("Enter the plaintext to be encrypted: ");
    scanf("%s", plaintext);
    printf("Enter the key to be used for encryption: ");
    scanf("%s", key);
    char* ciphertext = encrypt(plaintext, key);
    printf("The encrypted text is: %s\n", ciphertext);
    char* decrypted_text = decrypt(ciphertext, key);
    printf("The decrypted text is: %s\n", decrypted_text);
    free(ciphertext);
    free(decrypted_text);
    return 0;
}