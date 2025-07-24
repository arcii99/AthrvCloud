//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char *input, char *key, int len_input, int len_key) {
    int i, j;
    for(i = 0, j = 0; i < len_input; i++, j++) {
        if(j == len_key) {
            j = 0;
        }
        input[i] ^= key[j];
    }
}

void decrypt(char *input, char *key, int len_input, int len_key) {
    int i, j;
    for(i = 0, j = 0; i < len_input; i++, j++) {
        if(j == len_key) {
            j = 0;
        }
        input[i] ^= key[j];
    }
}

int main(void) {
    char input[1000] = "The quick brown fox jumps over the lazy dog";
    char key[100] = "supersecretpassphrase";
    int len_input = strlen(input);
    int len_key = strlen(key);

    printf("Original message: %s\n", input);

    encrypt(input, key, len_input, len_key);
    printf("Encrypted message: %s\n", input);

    decrypt(input, key, len_input, len_key);
    printf("Decrypted message: %s\n", input);

    return 0;
}