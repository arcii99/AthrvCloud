//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// Define constants for SHA_256
#define SHA256_BLOCK_SIZE 32
#define SHA256_DIGEST_SIZE 32
#define SHA256_ROUNDS 64

// Define a SHA_256 context struct
typedef struct {
    uint32_t state[8];
    uint32_t count[2];
    uint8_t buffer[SHA256_BLOCK_SIZE];
} sha256_ctx;

// Define the SHA_256 round constant values
static const uint32_t K[SHA256_ROUNDS] = {
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

// Define SHA_256 helper functions
#define rotr(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define shr(x, n) ((x) >> (n))
#define ch(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define maj(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define bsig0(x) (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22))
#define bsig1(x) (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25))
#define ssig0(x) (rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3))
#define ssig1(x) (rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10))

// Initial SHA_256 hash values
static const uint32_t H[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

// Initialize a SHA_256 context
void sha256_init(sha256_ctx *ctx) {
    memset(ctx, 0, sizeof(sha256_ctx));
    memcpy(ctx->state, H, sizeof(H));
}

// Perform a SHA_256 transformation
void sha256_transform(sha256_ctx *ctx, const uint8_t *message) {
    uint32_t W[SHA256_ROUNDS];
    uint32_t A, B, C, D, E, F, G, H, T1, T2;
    int i;
    for (i = 0; i < 16; i++) {
        W[i] = (message[(i * 4)] << 24) |
               (message[(i * 4) + 1] << 16) |
               (message[(i * 4) + 2] << 8)  |
               (message[(i * 4) + 3]);
    }
    for (i = 16; i < SHA256_ROUNDS; i++) {
        W[i] = ssig1(W[i-2]) + W[i-7] + ssig0(W[i-15]) + W[i-16];
    }
    A = ctx->state[0];
    B = ctx->state[1];
    C = ctx->state[2];
    D = ctx->state[3];
    E = ctx->state[4];
    F = ctx->state[5];
    G = ctx->state[6];
    H = ctx->state[7];
    for (i = 0; i < SHA256_ROUNDS; i++) {
        T1 = H + bsig1(E) + ch(E, F, G) + K[i] + W[i];
        T2 = bsig0(A) + maj(A, B, C);
        H = G;
        G = F;
        F = E;
        E = D + T1;
        D = C;
        C = B;
        B = A;
        A = T1 + T2;
    }
    ctx->state[0] += A;
    ctx->state[1] += B;
    ctx->state[2] += C;
    ctx->state[3] += D;
    ctx->state[4] += E;
    ctx->state[5] += F;
    ctx->state[6] += G;
    ctx->state[7] += H;
}

// Update a SHA_256 context with the given message data
void sha256_update(sha256_ctx *ctx, const uint8_t *message, size_t len) {
    uint32_t i, index = (uint32_t)((ctx->count[0] >> 3) & 0x3F);
    ctx->count[0] += len << 3;
    if (ctx->count[0] < (len << 3)) ctx->count[1]++;
    ctx->count[1] += len >> 29;
    for (i = 0; i < len; i++) {
        ctx->buffer[index++] = message[i];
        if (index == SHA256_BLOCK_SIZE) {
            sha256_transform(ctx, ctx->buffer);
            index = 0;
        }
    }
}

// Finalize a SHA_256 context and output the digest
void sha256_final(sha256_ctx *ctx, uint8_t *digest) {
    uint32_t i, index = (uint32_t)((ctx->count[0] >> 3) & 0x3F);
    uint64_t bits = ctx->count[0] + (ctx->count[1] << 32);
    ctx->buffer[index++] = 0x80;
    if (index > 56) {
        while (index < SHA256_BLOCK_SIZE) ctx->buffer[index++] = 0;
        sha256_transform(ctx, ctx->buffer);
        index = 0;
    }
    while (index < 56) ctx->buffer[index++] = 0;
    for (i = 0; i < 8; i++) {
        ctx->buffer[56 + i] = (uint8_t)(bits >> ((7 - i) * 8));
    }
    sha256_transform(ctx, ctx->buffer);
    for (i = 0; i < 8; i++) {
        digest[(i * 4)]     = (ctx->state[i] >> 24) & 0xFF;
        digest[(i * 4) + 1] = (ctx->state[i] >> 16) & 0xFF;
        digest[(i * 4) + 2] = (ctx->state[i] >> 8) & 0xFF;
        digest[(i * 4) + 3] = ctx->state[i] & 0xFF;
    }
}

int main() {
    sha256_ctx ctx;
    uint8_t message[30] = "Hello, world!";
    uint8_t digest[SHA256_DIGEST_SIZE];
    sha256_init(&ctx);
    sha256_update(&ctx, message, strlen((char *)message));
    sha256_final(&ctx, digest);
    printf("SHA-256: ");
    int i;
    for (i = 0; i < SHA256_DIGEST_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}