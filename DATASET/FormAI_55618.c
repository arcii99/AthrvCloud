//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 8
#define NUMBER_OF_ROUNDS 16

void printBytes(unsigned char *ptr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%02x", ptr[i]);
    }
    printf("\n");
}

void encrypt(unsigned char *plaintext, unsigned char *key) {
    unsigned char *ciphertext = (unsigned char*) malloc(sizeof(unsigned char) * KEY_LENGTH);
    memset(ciphertext, 0, KEY_LENGTH);

    for(int i = 0; i < NUMBER_OF_ROUNDS; i++) {
        for(int j = 0; j < KEY_LENGTH; j++) {
            ciphertext[j] ^= key[j];
        }
        for(int j = 0; j < KEY_LENGTH; j++) {
            ciphertext[j] ^= plaintext[j];
        }
        unsigned char temp = ciphertext[0];
        for(int j = 0; j < KEY_LENGTH - 1; j++) {
            ciphertext[j] = ciphertext[j+1];
        }
        ciphertext[KEY_LENGTH - 1] = temp;
    }

    printBytes(ciphertext, KEY_LENGTH);

    free(ciphertext);
}

int main() {
    unsigned char plaintext[KEY_LENGTH] = "Hello123";
    unsigned char key[KEY_LENGTH] = "mysecret";

    encrypt(plaintext, key);

    return 0;
}