//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdint.h>

// Define hash function constants
#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))
#define BLOCK_SIZE 64 // Block size in bytes

// Define SHA256 context structure
typedef struct {
    uint8_t data[BLOCK_SIZE]; // 512-bit block to be hashed
    uint32_t datalen; // Number of bits in data
    uint32_t bitlen[2]; // Total number of hashed bits
    uint32_t state[8]; // Hash state
} SHA256_CTX;

// Hash function initialization constants
const uint32_t k[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// SHA256 hash function
void sha256_transform(SHA256_CTX *ctx) {
    uint32_t i, j, t1, t2, m[64];
    uint32_t a, b, c, d, e, f, g, h;

    // Create 16 32-bit blocks from data
    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        m[i] = (ctx->data[j] << 24) | (ctx->data[j + 1] << 16) |
            (ctx->data[j + 2] << 8) | (ctx->data[j + 3]);
    }

    // Extend 16 blocks to 64 blocks
    for (; i < 64; ++i) {
        m[i] = m[i - 16] + ROTL32(m[i - 15], 7) +
            m[i - 7] + ROTL32(m[i - 2], 15);
    }

    // Initialize hash value for this chunk
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    // Main loop
    for (i = 0; i < 64; ++i) {
        t1 = h + ROTL32(e, 6) ^ ROTL32(e, 11) ^ ROTL32(e, 25) +
            ((e & f) ^ (~e & g)) + k[i] + m[i];
        t2 = ROTL32(a, 2) ^ ROTL32(a, 13) ^ ROTL32(a, 22) +
            ((a & b) ^ (a & c) ^ (b & c));

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Add this chunk's hash to the result so far
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

// Initialize SHA256 context
void sha256_init(SHA256_CTX *ctx) {
    ctx->datalen = 0;
    ctx->bitlen[0] = ctx->bitlen[1] = 0;
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}

// Update SHA256 context with input data
void sha256_update(SHA256_CTX *ctx, const uint8_t *data, uint32_t len) {
    uint32_t i, j;

    for (i = 0; i < len; ++i) {
        ctx->data[ctx->datalen++] = data[i];
        if (ctx->datalen == BLOCK_SIZE) {
            sha256_transform(ctx);
            ctx->bitlen[0] += BLOCK_SIZE * 8;
            if (ctx->bitlen[0] == 0) {
                ++ctx->bitlen[1];
            }
            ctx->datalen = 0;
        }
    }
}

// Finalize SHA256 context and output hash
void sha256_final(SHA256_CTX *ctx, uint8_t *hash) {
    uint32_t i;

    i = ctx->datalen;

    // Pad input data
    if (ctx->datalen < 56) {
        ctx->data[i++] = 0x80;
        while (i < 56) {
            ctx->data[i++] = 0x00;
        }
    } else {
        ctx->data[i++] = 0x80;
        while (i < BLOCK_SIZE) {
            ctx->data[i++] = 0x00;
        }
        sha256_transform(ctx);
        memset(ctx->data, 0, 56);
    }

    // Append total bits and hash
    ctx->bitlen[0] += ctx->datalen * 8;
    if (ctx->bitlen[0] < ctx->datalen * 8) {
        ++ctx->bitlen[1];
    }
    ctx->bitlen[1] += ctx->bitlen[0] >> 32;
    ctx->bitlen[0] &= 0xffffffff;
    ctx->bitlen[1] &= 0xffffffff;
    ctx->data[63] = ctx->bitlen[0];
    ctx->data[62] = ctx->bitlen[0] >> 8;
    ctx->data[61] = ctx->bitlen[0] >> 16;
    ctx->data[60] = ctx->bitlen[0] >> 24;
    ctx->data[59] = ctx->bitlen[1];
    ctx->data[58] = ctx->bitlen[1] >> 8;
    ctx->data[57] = ctx->bitlen[1] >> 16;
    ctx->data[56] = ctx->bitlen[1] >> 24;
    sha256_transform(ctx);

    // Output hash
    for (i = 0; i < 4; ++i) {
        hash[i] = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 4] = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 8] = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 20] = (ctx->state[5] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 24] = (ctx->state[6] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 28] = (ctx->state[7] >> (24 - i * 8)) & 0x000000ff;
    }
}

// Test SHA256 hash function
int main() {
    SHA256_CTX ctx;
    uint8_t hash[32];
    const char msg[] = "Hello world!";

    sha256_init(&ctx);
    sha256_update(&ctx, (uint8_t*)msg, strlen(msg));
    sha256_final(&ctx, hash);

    printf("Input message: %s\n", msg);
    printf("Hash value: ");
    for (int i = 0; i < 32; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}