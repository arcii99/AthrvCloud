//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    int num_blocks = plaintext_len / BLOCK_SIZE;
    unsigned char prev_cipher[BLOCK_SIZE]; 
    for(int i = 0; i < BLOCK_SIZE; i++) {
        prev_cipher[i] = iv[i];
    }
    for(int i = 0; i < num_blocks; i++) {
        for(int j = 0; j < BLOCK_SIZE; j++) {
            unsigned char byte = plaintext[i*BLOCK_SIZE+j] ^ prev_cipher[j];
            prev_cipher[j] = byte ^ key[j];
            ciphertext[i*BLOCK_SIZE+j] = prev_cipher[j];
        }
    }
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    int num_blocks = ciphertext_len / BLOCK_SIZE;
    unsigned char prev_cipher[BLOCK_SIZE];
    for(int i = 0; i < BLOCK_SIZE; i++) {
        prev_cipher[i] = iv[i];
    }
    for(int i = 0; i < num_blocks; i++) {
        for(int j = 0; j < BLOCK_SIZE; j++) {
            unsigned char byte = ciphertext[i*BLOCK_SIZE+j];
            plaintext[i*BLOCK_SIZE+j] = byte ^ key[j] ^ prev_cipher[j];
            prev_cipher[j] = byte;
        }
    }
}

int main() {
    printf("Welcome to my happy encryption program!\n");

    // Random key and iv generation
    unsigned char key[BLOCK_SIZE], iv[BLOCK_SIZE];
    FILE *f = fopen("/dev/urandom", "r");
    fread(key, 1, BLOCK_SIZE, f);
    fread(iv, 1, BLOCK_SIZE, f);
    fclose(f);

    char message[256] = "This is a secret message that the world shouldn't know!";
    printf("Message to encrypt is: %s\n", message);

    unsigned char ciphertext[256];
    encrypt((unsigned char*) message, strlen(message), key, iv, ciphertext);

    char decrypted_message[256];
    decrypt(ciphertext, strlen(message), key, iv, (unsigned char*) decrypted_message);
    decrypted_message[strlen(message)] = '\0';

    printf("Encrypted message is: ");
    for(int i = 0; i < strlen(message); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    printf("Decrypted message is: %s\n", decrypted_message);

    return 0;
}