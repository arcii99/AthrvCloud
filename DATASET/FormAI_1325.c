//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Rotate left function
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// SHA-256 constants
const uint32_t sha256_k[] = {
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

// SHA-256 functions
#define SHA256_SHR(x, n)    ((x) >> (n))
#define SHA256_SIGMA0(x)    (ROTL((x), 30) ^ ROTL((x), 19) ^ ROTL((x), 10))
#define SHA256_SIGMA1(x)    (ROTL((x), 26) ^ ROTL((x), 21) ^ ROTL((x), 7))
#define SHA256_sigma0(x)    (ROTL((x), 25) ^ ROTL((x), 14) ^ SHA256_SHR((x), 3))
#define SHA256_sigma1(x)    (ROTL((x), 15) ^ ROTL((x), 13) ^ SHA256_SHR((x), 10))
#define SHA256_Ch(x, y, z)  (((x) & (y)) ^ ((~(x)) & (z)))
#define SHA256_Maj(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

// SHA-256 context
typedef struct {
    uint32_t state[8];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA256_CTX;

// SHA-256 initialization
void sha256_init(SHA256_CTX *ctx) {
    ctx->count[0] = 0;
    ctx->count[1] = 0;

    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}

// SHA-256 update
void sha256_update(SHA256_CTX *ctx, const unsigned char *data, size_t len) {
    uint32_t i, j;

    for (i = 0; i < len; ++i) {
        j = (ctx->count[0] >> 3) & 0x3f;
        ctx->buffer[j++] = data[i];
        ++ctx->count[0];
        if (j == 0x40) {
            sha256_transform(ctx, ctx->buffer);
        }
    }
}

// SHA-256 transformation
void sha256_transform(SHA256_CTX *ctx, const unsigned char *data) {
    uint32_t i, t1, t2, m[64];

    // Prepare the message schedule
    for (i = 0; i < 16; ++i) {
        m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) |
               (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    }
    for (; i < 64; ++i) {
        m[i] = SHA256_sigma1(m[i - 2]) + m[i - 7] + SHA256_sigma0(m[i - 15]) + m[i - 16];
    }

    // Initialize the working variables
    uint32_t a = ctx->state[0];
    uint32_t b = ctx->state[1];
    uint32_t c = ctx->state[2];
    uint32_t d = ctx->state[3];
    uint32_t e = ctx->state[4];
    uint32_t f = ctx->state[5];
    uint32_t g = ctx->state[6];
    uint32_t h = ctx->state[7];

    // Perform the compression function
    for (i = 0; i < 64; ++i) {
        t1 = h + SHA256_SIGMA1(e) + SHA256_Ch(e, f, g) + sha256_k[i] + m[i];
        t2 = SHA256_SIGMA0(a) + SHA256_Maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Update the state
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

// SHA-256 finalization
void sha256_final(SHA256_CTX *ctx, unsigned char *hash) {
    uint32_t i, j;
    unsigned char finalcount[8], c;

    // Convert the count to a sequence of bytes
    for (i = 0; i < 8; ++i) {
        finalcount[i] = (unsigned char)((ctx->count[(i >= 4 ? 0 : 1)] >> ((3 - (i & 3)) * 8)) & 255);
    }

    // Compute the final SHA256 hash
    c = 0x80;
    sha256_update(ctx, &c, 1);
    while ((ctx->count[0] & 504) != 448) {
        c = 0;
        sha256_update(ctx, &c, 1);
    }
    sha256_update(ctx, finalcount, 8);
    for (i = 0; i < 32; ++i) {
        hash[i] = (unsigned char)((ctx->state[i >> 2] >> ((3 - (i & 3)) * 8)) & 255);
    }
}

int main(int argc, char *argv[]) {
    // Compute the SHA256 hash of a string
    char plaintext[] = "Hello, world!";
    unsigned char sha256hash[32];
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, (unsigned char*)plaintext, strlen(plaintext));
    sha256_final(&ctx, sha256hash);

    // Print the SHA256 hash
    printf("SHA256 hash of \"%s\":\n", plaintext);
    for (int i = 0; i < 32; ++i) {
        printf("%02x", sha256hash[i]);
    }
    printf("\n");

    return 0;
}