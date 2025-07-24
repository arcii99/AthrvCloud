//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) ((x << n) | (x >> (32 - n)))

#define F1(x, y, z) (x & y) | (~x & z)
#define F2(x, y, z) (x & y) | (x & z) | (y & z)
#define F3(x, y, z) x ^ y ^ z
#define F4(x, y, z) y ^ (x | ~z)

#define ROUND1(a, b, c, d, x, s) \
{ \
    a += F1(b, c, d) + x; \
    a = ROTL(a, s); \
}

#define ROUND2(a, b, c, d, x, s) \
{ \
    a += F2(b, c, d) + x + 0x5A827999; \
    a = ROTL(a, s); \
}

#define ROUND3(a, b, c, d, x, s) \
{ \
    a += F3(b, c, d) + x + 0x6ED9EBA1; \
    a = ROTL(a, s); \
}

#define ROUND4(a, b, c, d, x, s) \
{ \
    a += F4(b, c, d) + x + 0x8F1BBCDC; \
    a = ROTL(a, s); \
}

void MD5Transform(uint32_t state[], const uint8_t block[])
{
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t buffer[16];

    for (int i = 0; i < 16; i++)
        buffer[i] = (uint32_t)block[i * 4] | ((uint32_t)block[i * 4 + 1] << 8) |
                    ((uint32_t)block[i * 4 + 2] << 16) | ((uint32_t)block[i * 4 + 3] << 24);

    ROUND1(a, b, c, d, buffer[0], 7)
    ROUND1(d, a, b, c, buffer[1], 12)
    ROUND1(c, d, a, b, buffer[2], 17)
    ROUND1(b, c, d, a, buffer[3], 22)
    ROUND1(a, b, c, d, buffer[4], 7)
    ROUND1(d, a, b, c, buffer[5], 12)
    ROUND1(c, d, a, b, buffer[6], 17)
    ROUND1(b, c, d, a, buffer[7], 22)
    ROUND1(a, b, c, d, buffer[8], 7)
    ROUND1(d, a, b, c, buffer[9], 12)
    ROUND1(c, d, a, b, buffer[10], 17)
    ROUND1(b, c, d, a, buffer[11], 22)
    ROUND1(a, b, c, d, buffer[12], 7)
    ROUND1(d, a, b, c, buffer[13], 12)
    ROUND1(c, d, a, b, buffer[14], 17)
    ROUND1(b, c, d, a, buffer[15], 22)

    ROUND2(a, b, c, d, buffer[1], 5)
    ROUND2(d, a, b, c, buffer[6], 9)
    ROUND2(c, d, a, b, buffer[11], 14)
    ROUND2(b, c, d, a, buffer[0], 20)
    ROUND2(a, b, c, d, buffer[5], 5)
    ROUND2(d, a, b, c, buffer[10], 9)
    ROUND2(c, d, a, b, buffer[15], 14)
    ROUND2(b, c, d, a, buffer[4], 20)
    ROUND2(a, b, c, d, buffer[9], 5)
    ROUND2(d, a, b, c, buffer[14], 9)
    ROUND2(c, d, a, b, buffer[3], 14)
    ROUND2(b, c, d, a, buffer[8], 20)
    ROUND2(a, b, c, d, buffer[13], 5)
    ROUND2(d, a, b, c, buffer[2], 9)
    ROUND2(c, d, a, b, buffer[7], 14)
    ROUND2(b, c, d, a, buffer[12], 20)

    ROUND3(a, b, c, d, buffer[5], 4)
    ROUND3(d, a, b, c, buffer[8], 11)
    ROUND3(c, d, a, b, buffer[11], 16)
    ROUND3(b, c, d, a, buffer[14], 23)
    ROUND3(a, b, c, d, buffer[1], 4)
    ROUND3(d, a, b, c, buffer[4], 11)
    ROUND3(c, d, a, b, buffer[7], 16)
    ROUND3(b, c, d, a, buffer[10], 23)
    ROUND3(a, b, c, d, buffer[13], 4)
    ROUND3(d, a, b, c, buffer[0], 11)
    ROUND3(c, d, a, b, buffer[3], 16)
    ROUND3(b, c, d, a, buffer[6], 23)
    ROUND3(a, b, c, d, buffer[9], 4)
    ROUND3(d, a, b, c, buffer[12], 11)
    ROUND3(c, d, a, b, buffer[15], 16)
    ROUND3(b, c, d, a, buffer[2], 23)

    ROUND4(a, b, c, d, buffer[0], 6)
    ROUND4(d, a, b, c, buffer[7], 10)
    ROUND4(c, d, a, b, buffer[14], 15)
    ROUND4(b, c, d, a, buffer[5], 21)
    ROUND4(a, b, c, d, buffer[12], 6)
    ROUND4(d, a, b, c, buffer[3], 10)
    ROUND4(c, d, a, b, buffer[10], 15)
    ROUND4(b, c, d, a, buffer[1], 21)
    ROUND4(a, b, c, d, buffer[8], 6)
    ROUND4(d, a, b, c, buffer[15], 10)
    ROUND4(c, d, a, b, buffer[6], 15)
    ROUND4(b, c, d, a, buffer[13], 21)
    ROUND4(a, b, c, d, buffer[4], 6)
    ROUND4(d, a, b, c, buffer[11], 10)
    ROUND4(c, d, a, b, buffer[2], 15)
    ROUND4(b, c, d, a, buffer[9], 21)

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

void MD5Init(uint32_t state[])
{
    state[0] = 0x67452301;
    state[1] = 0xEFCDAB89;
    state[2] = 0x98BADCFE;
    state[3] = 0x10325476;
}

void MD5Update(uint32_t state[], const uint8_t data[], uint32_t length)
{
    uint32_t i, j;

    for (i = 0, j = length; j >= 64; i += 64, j -= 64)
        MD5Transform(state, &data[i]);

    // process remaining bytes
    uint8_t block[64] = { 0 };
    memcpy(block, &data[i], j);
    block[j] = 0x80;
    i += j;

    if (j > 56)
    {
        MD5Transform(state, block);
        memset(block, 0, 64);
    }

    uint64_t bitlen = length * 8;
    memcpy(&block[56], &bitlen, 8);
    MD5Transform(state, block);
}

void MD5Final(uint8_t digest[], uint32_t state[])
{
    memcpy(digest, state, 16);
    memset(state, 0, sizeof(state));
}

void MD5(const uint8_t data[], uint32_t length, uint8_t digest[])
{
    uint32_t state[4];
    MD5Init(state);
    MD5Update(state, data, length);
    MD5Final(digest, state);
}

int main(int argc, char* argv[])
{
    // Test
    const uint8_t data[] = "Hello, World!";
    uint8_t digest[16]; // 128-bit MD5 hash 
    MD5(data, strlen(data), digest);

    printf("MD5 hash of \"%s\" is:\n", data);
    for (int i = 0; i < 16; i++)
        printf("%02x", digest[i]);
    printf("\n");

    return 0;
}