//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LEN 16
#define BLOCK_SIZE 16

// function to xor two strings
char* xor(char* a, char* b) {
    char* result = malloc(strlen(a)+1);
    for(int i=0; i<strlen(a); i++) {
        result[i] = a[i] ^ b[i];
    }
    result[strlen(a)] = '\0';
    return result;
}

// function to generate a random key based on system time
void generate_random_key(char* key) {
    srand(time(NULL));
    for(int i=0; i<KEY_LEN; i++) {
        key[i] = rand() % 256;
    }
}

// function to pad the plaintext with zeros if necessary
void pad_plaintext(char* plaintext, int plaintext_len, int block_size) {
    int padding_size = block_size - (plaintext_len % block_size);
    for(int i=0; i<padding_size; i++) {
        plaintext[plaintext_len+i] = '\0';
    }
}

// function to perform encryption using AES
void aes_encrypt(char* plaintext, char* key, char* ciphertext) {
    char* iv = malloc(BLOCK_SIZE);
    generate_random_key(iv);
    memcpy(ciphertext, iv, BLOCK_SIZE);

    char* prev_cipher = malloc(BLOCK_SIZE);
    memcpy(prev_cipher, iv, BLOCK_SIZE);

    for(int i=0; i<strlen(plaintext); i+=BLOCK_SIZE) {
        char* block = malloc(BLOCK_SIZE+1);
        memcpy(block, &plaintext[i], BLOCK_SIZE);
        block[BLOCK_SIZE] = '\0';

        char* xored_block = xor(block, prev_cipher);
        char* block_key = xor(key, prev_cipher);

        char* cipher_block = malloc(BLOCK_SIZE);
        for(int j=0; j<BLOCK_SIZE; j++) {
            cipher_block[j] = xored_block[j] ^ block_key[j];
        }

        memcpy(prev_cipher, cipher_block, BLOCK_SIZE);
        memcpy(&ciphertext[i+BLOCK_SIZE], cipher_block, BLOCK_SIZE);
        free(xored_block);
        free(block_key);
        free(cipher_block);
    }

    free(prev_cipher);
}

// function to perform decryption using AES
void aes_decrypt(char* ciphertext, char* key, char* plaintext) {
    char* iv = malloc(BLOCK_SIZE);
    memcpy(iv, ciphertext, BLOCK_SIZE);

    char* prev_cipher = malloc(BLOCK_SIZE);
    memcpy(prev_cipher, iv, BLOCK_SIZE);

    for(int i=BLOCK_SIZE; i<strlen(ciphertext); i+=BLOCK_SIZE) {
        char* block = malloc(BLOCK_SIZE);
        memcpy(block, &ciphertext[i], BLOCK_SIZE);

        char* block_key = xor(key, prev_cipher);
        char* deciphered_block = malloc(BLOCK_SIZE);
        for(int j=0; j<BLOCK_SIZE; j++) {
            deciphered_block[j] = block[j] ^ block_key[j];
        }

        char* xored_block = xor(deciphered_block, prev_cipher);
        memcpy(&plaintext[i-BLOCK_SIZE], xored_block, BLOCK_SIZE);

        memcpy(prev_cipher, block, BLOCK_SIZE);
        free(block_key);
        free(deciphered_block);
        free(xored_block);
    }

    free(prev_cipher);
}

int main() {
    char* plaintext = "Cryptography is the future of security!";
    int plaintext_len = strlen(plaintext);
    pad_plaintext(plaintext, plaintext_len, BLOCK_SIZE);

    char* key = malloc(KEY_LEN);
    generate_random_key(key);

    char* ciphertext = malloc(strlen(plaintext));
    aes_encrypt(plaintext, key, ciphertext);

    char* decrypted_text = malloc(strlen(plaintext));
    aes_decrypt(ciphertext, key, decrypted_text);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for(int i=0; i<KEY_LEN; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");

    printf("Ciphertext: ");
    for(int i=0; i<strlen(plaintext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    printf("Decrypted text: %s\n", decrypted_text);

    free(key);
    free(ciphertext);
    free(decrypted_text);

    return 0;
}