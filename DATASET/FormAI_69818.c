//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))

uint32_t mix(uint32_t a, uint32_t b, uint32_t c)
{
    a -= c, a ^= ROTL32(c, 4), c += b;
    b -= a, b ^= ROTL32(a, 6), a += c;
    c -= b, c ^= ROTL32(b, 8), b += a;
    a -= c, a ^= ROTL32(c, 16), c += b;
    b -= a, b ^= ROTL32(a, 19), a += c;
    c -= b, c ^= ROTL32(b, 4), b += a;
    return a;
}

void hash(const char *msg, uint32_t *out)
{
    uint32_t h1 = 0xdeadbeef, h2 = 0x41c6ce57;
    uint32_t len = strlen(msg);
    uint32_t i;

    for (i = 0; i + 4 <= len; i += 4) {
        uint32_t k = ((uint32_t *)msg)[i / 4];
        h2 ^= k;
        h1 = mix(h1, h2, k);
        h1 = ROTL32(h1, 13);
        h2 = mix(h2, h1, k);
        h2 = ROTL32(h2, 16);
    }

    uint32_t k1 = 0, k2 = 0;
    uint8_t *tail = (uint8_t *)(msg + i);
    switch (len & 3) {
        case 3: k2 ^= tail[2] << 16;
        case 2: k2 ^= tail[1] << 8;
        case 1: k2 ^= tail[0];
                h2 ^= k2;
        case 0: k1 ^= 0;
                h1 ^= k1;
    }

    h1 += h2;
    h2 += h1;
    h1 ^= ROTL32(h1, 16);
    h2 ^= ROTL32(h2, 13);
    h1 += h2;
    h2 += h1;
    out[0] = h1;
    out[1] = h2;
}

int main(void)
{
    const char *msg = "Hello World!";
    uint32_t out[2];

    hash(msg, out);

    printf("Message: %s\n", msg);
    printf("Hash: %08x%08x\n", out[0], out[1]);

    return EXIT_SUCCESS;
}