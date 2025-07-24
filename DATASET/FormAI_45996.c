//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Encryption function */
void encrypt(char *plaintext, char *key) {
    int keylen = strlen(key);
    int plaintextlen = strlen(plaintext);
    int i, j;
    
    /* Loop through each character in plaintext */
    for(i = 0, j = 0; i < plaintextlen; ++i, ++j) {
        if(j >= keylen) {
            j = 0;
        }
        plaintext[i] = ((plaintext[i] - 'A') + (key[j] - 'A')) % 26 + 'A';
    }
}

/* Decryption function */
void decrypt(char *ciphertext, char *key) {
    int keylen = strlen(key);
    int ciphertextlen = strlen(ciphertext);
    int i, j;
    
    /* Loop through each character in ciphertext */
    for(i = 0, j = 0; i < ciphertextlen; ++i, ++j) {
        if(j >= keylen) {
            j = 0;
        }
        ciphertext[i] = ((ciphertext[i] - 'A') - (key[j] - 'A') + 26) % 26 + 'A';
    }
}

int main() {
    char plaintext[1000], ciphertext[1000], key[100];
    
    /* Get input from user */
    printf("Enter plaintext: ");
    fgets(plaintext, 1000, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    
    printf("Enter key: ");
    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = 0;
    
    /* Encrypt plaintext */
    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);
    printf("Encrypted Text: %s\n", ciphertext);
    
    /* Decrypt ciphertext */
    decrypt(ciphertext, key);
    printf("Decrypted Text: %s\n", ciphertext);
    
    return 0;
}