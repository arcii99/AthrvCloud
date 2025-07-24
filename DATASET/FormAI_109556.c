//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16
#define ROUNDS 4

// XOR operation for two blocks
void xor_blocks(unsigned char *x, unsigned char *y) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        x[i] ^= y[i];
    }
}

// S-box substitution
void sbox_substitution(unsigned char *block) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = (block[i] + i) % 256;
    }
}

// P-box permutation
void pbox_permutation(unsigned char *block) {
    unsigned char temp[BLOCK_SIZE];
    memcpy(temp, block, BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = temp[(i * 3) % BLOCK_SIZE];
    }
}

// Key schedule generation
void generate_round_keys(unsigned char *key, unsigned char round_keys[ROUNDS][KEY_SIZE]) {
    memcpy(round_keys[0], key, KEY_SIZE);
    for (int i = 1; i < ROUNDS; i++) {
        memcpy(round_keys[i], round_keys[i-1], KEY_SIZE);
        sbox_substitution(round_keys[i]);
        pbox_permutation(round_keys[i]);
        xor_blocks(round_keys[i], round_keys[i-1]);
    }
}

// Substitution of the block with the key
void substitute_with_key(unsigned char *block, unsigned char *key) {
    unsigned char temp[BLOCK_SIZE];
    memcpy(temp, block, BLOCK_SIZE);
    memcpy(block, key, BLOCK_SIZE);
    sbox_substitution(block);
    pbox_permutation(block);
    xor_blocks(block, temp);
}

// Encryption function
void encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    unsigned char round_keys[ROUNDS][KEY_SIZE];
    generate_round_keys(key, round_keys);
    memcpy(ciphertext, plaintext, BLOCK_SIZE);
    for (int i = 0; i < ROUNDS; i++) {
        substitute_with_key(ciphertext, round_keys[i]);
    }
}

// Decryption function
void decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *plaintext) {
    unsigned char round_keys[ROUNDS][KEY_SIZE];
    generate_round_keys(key, round_keys);
    memcpy(plaintext, ciphertext, BLOCK_SIZE);
    for (int i = ROUNDS-1; i >= 0; i--) {
        substitute_with_key(plaintext, round_keys[i]);
    }
}

// Driver function
int main() {
    unsigned char key[KEY_SIZE] = {0x7b, 0x68, 0xfd, 0xed, 0x12, 0x7d, 0xa5, 0x12, 0x52, 0x84, 0x3f, 0x16, 0xc6, 0xe1, 0xbb, 0x33};
    unsigned char plaintext[BLOCK_SIZE] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char ciphertext[BLOCK_SIZE];
    unsigned char decryptedtext[BLOCK_SIZE];

    encrypt(plaintext, key, ciphertext);
    decrypt(ciphertext, key, decryptedtext);

    printf("Plaintext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", plaintext[i]);
    }
    printf("\nCiphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\nDecrypted text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", decryptedtext[i]);
    }
    printf("\n");
    return 0;
}