//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the size of the hash output
#define HASH_SIZE 32

// Define the number of rounds to be used in the hashing algorithm
#define ROUNDS 10

// Define the block size used in the hashing algorithm
#define BLOCK_SIZE 64

// Define the number of bytes in a word
#define WORD_SIZE 4

// Define the rotation constants used in the hashing algorithm
#define ROT_CONST_1 7
#define ROT_CONST_2 12
#define ROT_CONST_3 17
#define ROT_CONST_4 22
#define ROT_CONST_5 5
#define ROT_CONST_6 9
#define ROT_CONST_7 14
#define ROT_CONST_8 20
#define ROT_CONST_9 4
#define ROT_CONST_10 11
#define ROT_CONST_11 16
#define ROT_CONST_12 23
#define ROT_CONST_13 6
#define ROT_CONST_14 10
#define ROT_CONST_15 15
#define ROT_CONST_16 21

// Function prototypes
uint32_t ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t rotl(uint32_t x, uint32_t n);
uint32_t rotr(uint32_t x, uint32_t n);
void sha256_transform(uint32_t *state, uint8_t *data);
void sha256(uint8_t *data, size_t length, uint8_t *hash);

// The SHA-256 hash function
void sha256(uint8_t *data, size_t length, uint8_t *hash)
{
    uint32_t state[8] =
    {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    uint8_t *data_ptr = data;
    uint32_t *state_ptr = state;
    size_t block_count = length / BLOCK_SIZE;
    for (size_t i = 0; i < block_count; i++)
    {
        // Perform the SHA-256 transformation on each block
        sha256_transform(state_ptr, data_ptr);
        data_ptr += BLOCK_SIZE;
    }
    // Compute the final hash value from the state array
    for (size_t i = 0; i < HASH_SIZE; i += WORD_SIZE)
    {
        hash[i]     = (state[i / WORD_SIZE] >> 24) & 0xff;
        hash[i + 1] = (state[i / WORD_SIZE] >> 16) & 0xff;
        hash[i + 2] = (state[i / WORD_SIZE] >> 8) & 0xff;
        hash[i + 3] = state[i / WORD_SIZE] & 0xff;
    }
}

// Perform the SHA-256 transformation on a single block of data
void sha256_transform(uint32_t *state, uint8_t *data)
{
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, t1, t2;
    for (size_t i = 0; i < 16; i++)
    {
        w[i] = ((uint32_t)data[i * WORD_SIZE] << 24) |
               ((uint32_t)data[i * WORD_SIZE + 1] << 16) |
               ((uint32_t)data[i * WORD_SIZE + 2] << 8) |
               (uint32_t)data[i * WORD_SIZE + 3];
    }
    for (size_t i = 16; i < 64; i++)
    {
        uint32_t s0 = rotr(w[i-15], ROT_CONST_1) ^ rotr(w[i-15], ROT_CONST_2) ^ (w[i-15] >> ROT_CONST_3);
        uint32_t s1 = rotr(w[i-2], ROT_CONST_4) ^ rotr(w[i-2], ROT_CONST_5) ^ (w[i-2] >> ROT_CONST_6);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }
    a = state[0]; b = state[1]; c = state[2]; d = state[3];
    e = state[4]; f = state[5]; g = state[6]; h = state[7];
    for (size_t i = 0; i < ROUNDS; i++)
    {
        t1 = h + ROT_CONST_13 + maj(e,f,g) + ch(e,f,g) + w[i];
        t2 = ROT_CONST_9 + rotr(a, ROT_CONST_10) + (a^b^c);
        h = g; g = f; f = e; e = d + t1;
        d = c; c = b; b = a; a = t1 + t2;
    }
    state[0] += a; state[1] += b; state[2] += c; state[3] += d;
    state[4] += e; state[5] += f; state[6] += g; state[7] += h;
}

// The choice function
uint32_t ch(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (~x & z);
}

// The majority function
uint32_t maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

// Left rotate function
uint32_t rotl(uint32_t x, uint32_t n)
{
    return (x << n) | (x >> (32-n));
}

// Right rotate function
uint32_t rotr(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32-n));
}

int main()
{
    char input[512];
    printf("Enter a string to hash: ");
    fgets(input, 512, stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character
    size_t length = strlen(input);
    uint8_t hash[HASH_SIZE];
    sha256((uint8_t*)input, length, hash);
    printf("Hash of '%s': ", input);
    for (size_t i = 0; i < HASH_SIZE; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}