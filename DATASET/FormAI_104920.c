//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 14 // encryption key

/* function: encrypt
 * -----------------
 * encrypts a string using a simple substitution cipher
 *
 * plaintext: the string to encrypt
 * return: a pointer to the encrypted string 
 */
char* encrypt(char *plaintext) {
    char *ciphertext = malloc(strlen(plaintext));

    for(int i = 0; i < strlen(plaintext); i++) {
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + KEY) % 26) + 'a';
        } else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + KEY) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    return ciphertext;
}

int main() {
    char *plaintext = "This is a secret message!";
    char *ciphertext = encrypt(plaintext);

    printf("Original message: %s\n", plaintext);
    printf("Encrypted message: %s\n", ciphertext);

    free(ciphertext); // free memory

    return 0;
}