//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 64 // 512-bit block size
#define WORD_SIZE 4 // 32-bit word size
#define HASH_SIZE 20 // 160-bit hash size

// Constants for SHA-1
uint32_t K[] = {0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6};

// Defines the SHA-1 hash structure
typedef struct {
    uint32_t h[HASH_SIZE/WORD_SIZE];
    uint32_t data[BLOCK_SIZE/WORD_SIZE];
    uint32_t datalen;
    uint64_t bitlen;
} SHA1_CTX;

// Initialization function, called before starting the hash computation
void sha1_init(SHA1_CTX *ctx) {
    ctx->h[0] = 0x67452301;
    ctx->h[1] = 0xefcdab89;
    ctx->h[2] = 0x98badcfe;
    ctx->h[3] = 0x10325476;
    ctx->h[4] = 0xc3d2e1f0;
    ctx->datalen = 0;
    ctx->bitlen = 0;
}

// Computes the SHA-1 hash of the given message
void sha1_update(SHA1_CTX *ctx, const uint8_t *data, size_t len) {
    uint32_t i, j;
    for (i = 0; i < len; ++i) {
        ctx->data[ctx->datalen] = data[i];
        ++ctx->datalen;
        if (ctx->datalen == BLOCK_SIZE/WORD_SIZE) {
            for (j = 0; j < BLOCK_SIZE/WORD_SIZE; ++j) {
                ctx->data[j] = ctx->data[j] << 24 | 
                               (ctx->data[j] << 8 & 0xff0000) | 
                               (ctx->data[j] >> 8 & 0xff00) | 
                               (ctx->data[j] >> 24 & 0xff);
            }
            uint32_t a = ctx->h[0], b = ctx->h[1], c = ctx->h[2], d = ctx->h[3], e = ctx->h[4], f, temp;
            for (j = 0; j < BLOCK_SIZE/WORD_SIZE; ++j) {
                f = (b & c) | ((~b) & d);
                temp = ((a << 5) | (a >> 27)) + f + e + K[j] + ctx->data[j];
                e = d;
                d = c;
                c = (b << 30) | (b >> 2);
                b = a;
                a = temp;
            }
            ctx->h[0] += a;
            ctx->h[1] += b;
            ctx->h[2] += c;
            ctx->h[3] += d;
            ctx->h[4] += e;
            ctx->datalen = 0;
        }
    }
    ctx->bitlen += len * 8;
}

// Finalization function, called after all the data has been fed to update
void sha1_final(SHA1_CTX *ctx, uint8_t *hash) {
    uint32_t i;
    i = ctx->datalen;
    if (ctx->datalen < BLOCK_SIZE/WORD_SIZE) {
        ctx->data[i++] = 0x80;
        while (i < BLOCK_SIZE/WORD_SIZE) {
            ctx->data[i++] = 0x00;
        }
    }
    else {
        ctx->data[i++] = 0x80;
        while (i < BLOCK_SIZE/WORD_SIZE) {
            ctx->data[i++] = 0x00;
        }
        for (i = 0; i < BLOCK_SIZE/WORD_SIZE; ++i) {
            ctx->data[i] = ctx->data[i] << 24 | 
                           (ctx->data[i] << 8 & 0xff0000) | 
                           (ctx->data[i] >> 8 & 0xff00) | 
                           (ctx->data[i] >> 24 & 0xff);
        }
        uint32_t a = ctx->h[0], b = ctx->h[1], c = ctx->h[2], d = ctx->h[3], e = ctx->h[4], f, temp;
        for (i = 0; i < 16; ++i) {
            f = (b & c) | ((~b) & d);
            temp = ((a << 5) | (a >> 27)) + f + e + K[i] + ctx->data[i];
            e = d;
            d = c;
            c = (b << 30) | (b >> 2);
            b = a;
            a = temp;
        }
        for (i = 16; i < 80; ++i) {
            f = (b ^ c ^ d);
            temp = ((a << 5) | (a >> 27)) + f + e + K[i] + ctx->data[i%BLOCK_SIZE/WORD_SIZE];
            e = d;
            d = c;
            c = (b << 30) | (b >> 2);
            b = a;
            a = temp;
        }
        ctx->h[0] += a;
        ctx->h[1] += b;
        ctx->h[2] += c;
        ctx->h[3] += d;
        ctx->h[4] += e;
    }
    for (i = 0; i < HASH_SIZE/WORD_SIZE; ++i) {
        uint32_t val = ctx->h[i];
        hash[i*4+0] = val >> 24;
        hash[i*4+1] = val >> 16;
        hash[i*4+2] = val >> 8;
        hash[i*4+3] = val;
    }
}

// Test function to verify that the hash is working correctly
void sha1_test() {
    char msg1[] = "The quick brown fox jumps over the lazy dog";
    uint8_t h1[] = {0x2f, 0xd4, 0xe1, 0xc6, 0x7a, 0x2d, 0x28, 0xfc, 0xed, 0x84, 0x9e, 0xe1, 0xbb, 0x76, 0xe7, 0x39, 0x1b, 0x93, 0xeb, 0x12};
    char msg2[] = "Hello, world!";
    uint8_t h2[] = {0x0a, 0x4d, 0x55, 0x5a, 0xd6, 0x0e, 0x07, 0x98, 0x6d, 0xc5, 0xc5, 0xc7, 0x16, 0x45, 0x3c, 0xbf, 0x40, 0xee, 0xb5, 0x27};
    SHA1_CTX ctx;
    uint8_t hash[HASH_SIZE/WORD_SIZE];
    sha1_init(&ctx);
    sha1_update(&ctx, (uint8_t*)msg1, strlen(msg1));
    sha1_final(&ctx, hash);
    printf("SHA-1 hash of \"%s\" is: ", msg1);
    for (int i = 0; i < HASH_SIZE/WORD_SIZE; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    if (memcmp(hash, h1, HASH_SIZE/WORD_SIZE) != 0) {
        printf("FAILED: SHA-1 hash of \"%s\" is incorrect.\n", msg1);
    }
    sha1_init(&ctx);
    sha1_update(&ctx, (uint8_t*)msg2, strlen(msg2));
    sha1_final(&ctx, hash);
    printf("SHA-1 hash of \"%s\" is: ", msg2);
    for (int i = 0; i < HASH_SIZE/WORD_SIZE; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    if (memcmp(hash, h2, HASH_SIZE/WORD_SIZE) != 0) {
        printf("FAILED: SHA-1 hash of \"%s\" is incorrect.\n", msg2);
    }
}

// Main function
int main() {
    sha1_test();
    return 0;
}