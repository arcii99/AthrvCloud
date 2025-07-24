//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for encryption
void encrypt(char *plaintext, char *key){
    int keyLen = strlen(key);
    int i, j;
    // XOR operation with key
    for(i=0, j=0; i < strlen(plaintext); i++, j++){
        if(j == keyLen){
            j = 0;
        }

        plaintext[i] = plaintext[i] ^ key[j];
    }
}

// Function for decryption
void decrypt(char *ciphertext, char *key){
    encrypt(ciphertext, key);
}

int main(){
    char plaintext[100] = "Hello, world!";
    char key[100] = "password";
    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, key);
    printf("Ciphertext: %s\n", plaintext);
    decrypt(plaintext, key);
    printf("Original text: %s\n", plaintext);
    return 0;
}