//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

/* Donald Knuth style C Cryptography Implementation example */

/* Constants */
#define BLOCK_SIZE 16 /* Size of block in bytes */
#define KEY_SIZE 16 /* Size of key in bytes */
#define MAX_ROUNDS 32 /* Maximum rounds */
#define DELTA 0x9E3779B9 /* Golden ratio constant */
#define PHI 0x9E3779B9 /* Modular additive constant */

/* Functions */
void addRoundKey(uint32_t *block, uint32_t *key);
void subBytes(uint32_t *block, int decrypt);
void shiftRows(uint32_t *block, int decrypt);
void mixColumns(uint32_t *block, int decrypt);
void encrypt(uint32_t *block, uint32_t *key, int rounds);
void decrypt(uint32_t *block, uint32_t *key, int rounds);

/* Main Function */
int main(){
    /* Initialize random seed */
    srand(time(NULL));
    
    /* Generate random plaintext and key */
    uint32_t plaintext[BLOCK_SIZE / sizeof(uint32_t)];
    uint32_t key[KEY_SIZE / sizeof(uint32_t)];
    for (int i = 0; i < BLOCK_SIZE / sizeof(uint32_t); i++){
        plaintext[i] = rand();
    }
    for (int i = 0; i < KEY_SIZE / sizeof(uint32_t); i++){
        key[i] = rand();
    }
    
    /* Print plaintext and key */
    printf("Plaintext:\n");
    for (int i = 0; i < BLOCK_SIZE / sizeof(uint32_t); i++){
        printf("%08X ", plaintext[i]);
    }
    printf("\n");
    printf("Key:\n");
    for (int i = 0; i < KEY_SIZE / sizeof(uint32_t); i++){
        printf("%08X ", key[i]);
    }
    printf("\n");
    
    /* Encrypt and decrypt plaintext */
    encrypt(plaintext, key, MAX_ROUNDS);
    printf("Ciphertext:\n");
    for (int i = 0; i < BLOCK_SIZE / sizeof(uint32_t); i++){
        printf("%08X ", plaintext[i]);
    }
    printf("\n");
    decrypt(plaintext, key, MAX_ROUNDS);
    printf("Decrypted plaintext:\n");
    for (int i = 0; i < BLOCK_SIZE / sizeof(uint32_t); i++){
        printf("%08X ", plaintext[i]);
    }
    printf("\n");
    
    return 0;
}

/* XOR block with key */
void addRoundKey(uint32_t *block, uint32_t *key){
    for (int i = 0; i < BLOCK_SIZE / sizeof(uint32_t); i++){
        block[i] ^= key[i];
    }
}

/* Substitute bytes in block */
void subBytes(uint32_t *block, int decrypt){
    uint8_t *b = (uint8_t*) block;
    uint8_t sbox[256] = {
        /* S-box */
        0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
        0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
        0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
        0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
        0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
        0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
        0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
        0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
        0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
        0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
        0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
        0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
        0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
        0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
        0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
        0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
    };
    for (int i = 0; i < BLOCK_SIZE; i++){
        b[i] = sbox[b[i]];
    }
}

/* Shift rows in block */
void shiftRows(uint32_t *block, int decrypt){
    uint8_t *b = (uint8_t*) block;
    uint8_t temp[BLOCK_SIZE];
    memcpy(temp, b, BLOCK_SIZE);
    for (int i = 1; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int k = (i + j) % 4;
            if (decrypt){
                k = (4 + j - i) % 4;
            }
            b[i * 4 + j] = temp[k * 4 + j];
        }
    }
}

/* Mix columns in block */
void mixColumns(uint32_t *block, int decrypt){
    uint8_t *b = (uint8_t*) block;
    uint8_t matrix[][4] = {
        /* Mix columns matrix */
        {0x02, 0x03, 0x01, 0x01},
        {0x01, 0x02, 0x03, 0x01},
        {0x01, 0x01, 0x02, 0x03},
        {0x03, 0x01, 0x01, 0x02}
    };
    if (decrypt){
        uint8_t invMatrix[][4] = {
            /* Inverse mix columns matrix */
            {0x0E, 0x0B, 0x0D, 0x09},
            {0x09, 0x0E, 0x0B, 0x0D},
            {0x0D, 0x09, 0x0E, 0x0B},
            {0x0B, 0x0D, 0x09, 0x0E}
        };
        memcpy(matrix, invMatrix, sizeof(matrix));
    }
    for (int i = 0; i < 4; i++){
        uint8_t temp[4];
        memcpy(temp, &b[i * 4], sizeof(temp));
        for (int j = 0; j < 4; j++){
            b[i * 4 + j] = 0;
            for (int k = 0; k < 4; k++){
                uint8_t x = temp[k];
                uint8_t y = matrix[j][k];
                uint8_t z;
                /* Multiplication in Galois Field (GF(2^8)) */
                for (z = 0; x && y; y ^= ((y & 1) * x) | ((y & 0x80) >> 7), x ^= (x & 1) * 0x11, x <<= 1){
                    z ^= y & (x >> 1);
                }
                b[i * 4 + j] ^= z;
            }
        }
    }
}

/* Encrypt block */
void encrypt(uint32_t *block, uint32_t *key, int rounds){
    addRoundKey(block, key);
    for (int i = 1; i < rounds; i++){
        subBytes(block, 0);
        shiftRows(block, 0);
        mixColumns(block, 0);
        uint32_t roundKey[4] = {0};
        for (int j = 0; j < 4; j++){
            uint32_t temp = key[j + 1] << 24 | key[j + 2] << 16 | key[j + 3] << 8 | key[j + 4];
            roundKey[j] = temp;
        }
        addRoundKey(block, roundKey);
    }
    subBytes(block, 0);
    shiftRows(block, 0);
    uint32_t lastRoundKey[4] = {0};
    for (int j = 0; j < 4; j++){
        uint32_t temp = key[j + 13] << 24 | key[j + 14] << 16 | key[j + 15] << 8 | key[j + 16];
        lastRoundKey[j] = temp;
    }
    addRoundKey(block, lastRoundKey);
}

/* Decrypt block */
void decrypt(uint32_t *block, uint32_t *key, int rounds){
    uint32_t roundKeys[rounds + 1][4];
    memcpy(roundKeys[rounds], &key[13], 16);
    for (int i = rounds - 1; i >= 1; i--){
        uint32_t invRoundKey[4];
        memcpy(invRoundKey, &key[(i - 1) * 4 + 1], 16);
        mixColumns(invRoundKey, 1);
        shiftRows(invRoundKey, 1);
        subBytes(invRoundKey, 1);
        roundKeys[i][0] = roundKeys[i + 1][0] ^ invRoundKey[0];
        roundKeys[i][1] = roundKeys[i + 1][1] ^ invRoundKey[1];
        roundKeys[i][2] = roundKeys[i + 1][2] ^ invRoundKey[2];
        roundKeys[i][3] = roundKeys[i + 1][3] ^ invRoundKey[3];
    }
    addRoundKey(block, roundKeys[1]);
    for (int i = 1; i < rounds; i++){
        mixColumns(block, 1);
        shiftRows(block, 1);
        subBytes(block, 1);
        addRoundKey(block, roundKeys[i + 1]);
    }
    shiftRows(block, 1);
    subBytes(block, 1);
    addRoundKey(block, key);
}