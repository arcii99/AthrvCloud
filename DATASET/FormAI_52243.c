//FormAI DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t encrypt(uint32_t plaintext, uint32_t key)
{
    uint32_t ciphertext = plaintext;
    uint32_t round_key = key;
    int i;

    for (i = 1; i <= 32; i++)
    {
        ciphertext ^= round_key;
        ciphertext = (ciphertext << i) | (ciphertext >> (32 - i));
        round_key ^= i;
    }

    return ciphertext;
}

int main()
{
    uint32_t plaintext = 0x12345678;
    uint32_t key = 0x9abcdef0;

    printf("Plaintext: 0x%08x\n", plaintext);
    printf("Key: 0x%08x\n", key);

    uint32_t ciphertext = encrypt(plaintext, key);

    printf("Ciphertext: 0x%08x\n", ciphertext);

    return 0;
}