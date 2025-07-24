//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Rotation macros for 32-bit words
#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x, y) ((x >> y) | (x << (32 - y)))

// Hashing constants
#define PRIME1 2654435761u
#define PRIME2 2246822519u
#define PRIME3 3266489917u
#define PRIME4 668265263u
#define PRIME5 374761393u

// Initial state
#define STATE0 0x736f6d65u
#define STATE1 0x646f7261u
#define STATE2 0x6c796765u
#define STATE3 0x74656462u

// Round function for compression
#define ROUND(x)                                                \
    {                                                           \
        x *= PRIME1;                                            \
        x = ROTL32(x, 13);                                      \
        x *= PRIME2;                                            \
        x = ROTL32(x, 13);                                      \
        x *= PRIME3;                                            \
        x = ROTL32(x, 13);                                      \
        x ^= x >> 16;                                           \
        x *= PRIME4;                                            \
        x = ROTL32(x, 13);                                      \
        x *= PRIME5;                                            \
        x = ROTL32(x, 13);                                      \
    }

// Finalize function for generating output
#define FINALIZE(a, b, c, d)                                    \
    {                                                           \
        d ^= c;                                                 \
        c = ROTL32(c, 15);                                      \
        d += c;                                                 \
        b ^= a;                                                 \
        a = ROTL32(a, 13);                                      \
        b += a;                                                 \
        c ^= b;                                                 \
        b = ROTL32(b, 13);                                      \
        c += b;                                                 \
    }

// Main hash function
uint32_t hash(const void *key, size_t len)
{
    // Initialize state variables
    uint32_t a = STATE0, b = STATE1, c = STATE2, d = STATE3;

    // Pointers to the start and end of input buffer
    uint32_t *ptr = (uint32_t *)key;
    uint32_t *end = ptr + (len / 4);

    // Main loop over input buffer
    while (ptr != end)
    {
        // Read a 32-bit word from input buffer
        uint32_t data = *ptr++;

        // First round of mixing
        a += data;
        ROUND(d);
        c ^= b;
        ROUND(c);
        b += a;

        // Second round of mixing
        a += data;
        ROUND(d);
        c ^= b;
        ROUND(c);
        b += a;
    }

    // Finalize and pad the input buffer
    uint8_t *tail = (uint8_t *)ptr;
    uint32_t data = 0;
    if (len & 3)
    {
        memcpy(&data, tail, len & 3);
    }
    switch (len & 3)
    {
        case 3:
            data ^= tail[2] << 16;
        case 2:
            data ^= tail[1] << 8;
        case 1:
            data ^= tail[0];
            a += data;
            ROUND(d);
            c ^= b;
            ROUND(c);
            b += a;
    }

    // Finalize the output
    FINALIZE(a, b, c, d);

    return d;
}

// Test the hash function
int main()
{
    // Message to hash
    const char *message = "Hello, World!";

    // Compute the hash of the message
    uint32_t h = hash(message, strlen(message));

    // Print the hash value
    printf("Hash: 0x%08x\n", h);

    return 0;
}