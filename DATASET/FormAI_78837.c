//FormAI DATASET v1.0 Category: Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paranoid_encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, key_len, plain_len;
    char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.;:/?!@#$&*()-_+=";
    int alpha_len = strlen(alphabet);

    key_len = strlen(key);
    plain_len = strlen(plaintext);

    // First, scramble the plaintext
    for (i = 0; i < plain_len; i++) {
        for (j = 0; j < key_len; j++) {
            plaintext[i] ^= key[j];
        }
    }

    // Then, scramble the alphabet
    for (i = 0; i < alpha_len; i++) {
        for (j = 0; j < key_len; j++) {
            alphabet[i] ^= key[j];
        }
    }

    // Finally, encrypt the plaintext using the scrambled alphabet
    for (i = 0; i < plain_len; i++) {
        for (j = 0; j < alpha_len; j++) {
            if (plaintext[i] == alphabet[j]) {
                ciphertext[i] = alphabet[(j + 1) % alpha_len];
                break;
            }
        }
    }
    ciphertext[plain_len] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100];
    printf("Enter plaintext (max 100 characters):\n");
    fgets(plaintext, 100, stdin);
    printf("Enter encryption key:\n");
    fgets(key, 100, stdin);

    paranoid_encrypt(plaintext, key, ciphertext);

    printf("\nEncrypted text is: %s\n", ciphertext);

    return 0;
}