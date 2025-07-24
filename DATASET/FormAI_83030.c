//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define a struct for the hash context
typedef struct 
{
    uint32_t state[4];  // Hash state
    uint32_t count[2];  // Count of bits processed so far
    uint8_t buffer[64]; // Block being hashed
} hash_ctx;

// Rotate a 32-bit value left
static inline uint32_t left_rotate(uint32_t value, uint32_t shift)
{
    return (value << shift) | (value >> (32 - shift));
}

// Round functions for the hash function
static inline uint32_t round1(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) | (~x & z);
}

static inline uint32_t round2(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & z) | (y & ~z);
}

static inline uint32_t round3(uint32_t x, uint32_t y, uint32_t z)
{
    return x ^ y ^ z;
}

static inline uint32_t round4(uint32_t x, uint32_t y, uint32_t z)
{
    return y ^ (x | ~z);
}

// Hash function
void hash(const uint8_t* data, size_t length, uint8_t* result)
{
    // Initialize hash context
    hash_ctx ctx;
    ctx.state[0] = 0x67452301;
    ctx.state[1] = 0xefcdab89;
    ctx.state[2] = 0x98badcfe;
    ctx.state[3] = 0x10325476;
    ctx.count[0] = 0;
    ctx.count[1] = 0;

    // Process each 64-byte block of input data
    for (size_t i = 0; i < length / 64; i++)
    {
        const uint8_t* block = data + i * 64;

        // Copy block into context buffer
        memcpy(ctx.buffer, block, 64);

        // Process block
        uint32_t a = ctx.state[0];
        uint32_t b = ctx.state[1];
        uint32_t c = ctx.state[2];
        uint32_t d = ctx.state[3];

        uint32_t* words = (uint32_t*)ctx.buffer;
        for (size_t j = 0; j < 16; j++)
        {
            uint32_t temp = words[j];
            words[j] = (temp << 24) | ((temp & 0xff00) << 8) | ((temp >> 8) & 0xff00) | (temp >> 24);
        }

        for (size_t j = 0; j < 64; j++)
        {
            uint32_t f, g;
            if (j < 16)
            {
                f = round1(b, c, d);
                g = j;
            }
            else if (j < 32)
            {
                f = round2(b, c, d);
                g = (5 * j + 1) % 16;
            }
            else if (j < 48)
            {
                f = round3(b, c, d);
                g = (3 * j + 5) % 16;
            }
            else
            {
                f = round4(b, c, d);
                g = (7 * j) % 16;
            }

            uint32_t temp = d;
            d = c;
            c = b;
            b = b + left_rotate((a + f + *(words + g) + 0x5a827999), 12);
            a = temp;
        }

        // Update hash context
        ctx.state[0] += a;
        ctx.state[1] += b;
        ctx.state[2] += c;
        ctx.state[3] += d;
        ctx.count[0] += 64;
        if (ctx.count[0] < 64)
        {
            ctx.count[1]++;
        }
    }

    // Compute final hash value
    size_t remaining = length - (length / 64) * 64;
    uint8_t* last_block = data + (length / 64) * 64;
    memcpy(ctx.buffer, last_block, remaining);
    memset(ctx.buffer + remaining, 0, 64 - remaining);
    *((uint64_t*)(ctx.buffer + 56)) = ctx.count[0] * 8;
    *((uint64_t*)(ctx.buffer + 48)) = ctx.count[1] * 8;
    *((uint32_t*)(ctx.buffer + 60)) = remaining;

    uint32_t a = ctx.state[0];
    uint32_t b = ctx.state[1];
    uint32_t c = ctx.state[2];
    uint32_t d = ctx.state[3];

    uint32_t* words = (uint32_t*)ctx.buffer;
    for (size_t j = 0; j < 16; j++)
    {
        uint32_t temp = words[j];
        words[j] = (temp << 24) | ((temp & 0xff00) << 8) | ((temp >> 8) & 0xff00) | (temp >> 24);
    }

    for (size_t j = 0; j < 64; j++)
    {
        uint32_t f, g;
        if (j < 16)
        {
            f = round1(b, c, d);
            g = j;
        }
        else if (j < 32)
        {
            f = round2(b, c, d);
            g = (5 * j + 1) % 16;
        }
        else if (j < 48)
        {
            f = round3(b, c, d);
            g = (3 * j + 5) % 16;
        }
        else
        {
            f = round4(b, c, d);
            g = (7 * j) % 16;
        }

        uint32_t temp = d;
        d = c;
        c = b;
        b = b + left_rotate((a + f + *(words + g) + 0x5a827999), 12);
        a = temp;
    }

    result[0] = (uint8_t)(ctx.state[0] >> 24);
    result[1] = (uint8_t)(ctx.state[0] >> 16);
    result[2] = (uint8_t)(ctx.state[0] >> 8);
    result[3] = (uint8_t)ctx.state[0];
    result[4] = (uint8_t)(ctx.state[1] >> 24);
    result[5] = (uint8_t)(ctx.state[1] >> 16);
    result[6] = (uint8_t)(ctx.state[1] >> 8);
    result[7] = (uint8_t)ctx.state[1];
    result[8] = (uint8_t)(ctx.state[2] >> 24);
    result[9] = (uint8_t)(ctx.state[2] >> 16);
    result[10] = (uint8_t)(ctx.state[2] >> 8);
    result[11] = (uint8_t)ctx.state[2];
    result[12] = (uint8_t)(ctx.state[3] >> 24);
    result[13] = (uint8_t)(ctx.state[3] >> 16);
    result[14] = (uint8_t)(ctx.state[3] >> 8);
    result[15] = (uint8_t)ctx.state[3];
}

// Entry point
int main(int argc, char** argv)
{
    const char* test_data = "Hello, world!";
    uint8_t hash_result[16];
    hash((const uint8_t*)test_data, strlen(test_data), hash_result);

    printf("Input: %s\n", test_data);
    printf("Hash: ");
    for (size_t i = 0; i < 16; i++)
    {
        printf("%02x", hash_result[i]);
    }
    printf("\n");

    return 0;
}