//FormAI DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i;
    int keylen = strlen(key);
    int plainlen = strlen(plaintext);
    for (i = 0; i < plainlen; i++) {
        ciphertext[i] = ((plaintext[i] + key[i % keylen]) % 26) + 'A';
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i;
    int keylen = strlen(key);
    int cipherlen = strlen(ciphertext);
    for (i = 0; i < cipherlen; i++) {
        plaintext[i] = (((ciphertext[i] - 'A') - (key[i % keylen] - 'A') + 26) % 26) + 'A';
    }
    plaintext[i] = '\0';
}

int main(int argc, char *argv[]) {

    char plaintext[] = "HELLO WORLD";
    char key[] = "SECRETKEY";
    int plainlen = strlen(plaintext);
    char ciphertext[plainlen];
    encrypt(plaintext, key, ciphertext);
    printf("The Encrypted text is: %s\n", ciphertext);
    
    char decryptedtext[plainlen];
    decrypt(ciphertext, key, decryptedtext);
    printf("The Decrypted text is: %s\n", decryptedtext);

    return 0;
}