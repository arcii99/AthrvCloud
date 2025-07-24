//FormAI DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <stdint.h>

// Size of the encryption key
#define KEY_SIZE 4

// Encryption function
void encrypt(uint8_t key[], uint8_t plaintext[], uint8_t ciphertext[]) {
    uint32_t v0 = *(uint32_t*)plaintext;
    uint32_t v1 = *(uint32_t*)(plaintext + 4);
    uint32_t sum = 0;
    uint32_t delta = 0x9e3779b9;
    for (int i = 0; i < 32; i++) {
        sum += delta;
        v0 += ((v1 << 4) + key[0]) ^ (v1 + sum) ^ ((v1 >> 5) + key[1]);
        v1 += ((v0 << 4) + key[2]) ^ (v0 + sum) ^ ((v0 >> 5) + key[3]);
    }
    *(uint32_t*)ciphertext = v0;
    *(uint32_t*)(ciphertext + 4) = v1;
}

int main() {
    uint8_t key[KEY_SIZE] = {1, 2, 3, 4};
    uint8_t plaintext[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    uint8_t ciphertext[8] = {0};
    encrypt(key, plaintext, ciphertext);
    printf("Plaintext: ");
    for (int i = 0; i < 8; i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\n");
    printf("Ciphertext: ");
    for (int i = 0; i < 8; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    return 0;
}