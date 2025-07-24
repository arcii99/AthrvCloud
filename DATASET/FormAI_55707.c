//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 32

// modulo operation for uint64_t types
#define MOD(a, b) (a % b)

// bit shifting operations
#define ROR(a, n) ((a >> n) | (a << (64 - n)))
#define ROL(a, n) ((a << n) | (a >> (64 - n)))

// convert 8 bytes of block to uint64_t
#define GET_UINT64(block, i) (((uint64_t)(block[(i) + 7]))       \
                             | ((uint64_t)(block[(i) + 6]) << 8)  \
                             | ((uint64_t)(block[(i) + 5]) << 16) \
                             | ((uint64_t)(block[(i) + 4]) << 24) \
                             | ((uint64_t)(block[(i) + 3]) << 32) \
                             | ((uint64_t)(block[(i) + 2]) << 40) \
                             | ((uint64_t)(block[(i) + 1]) << 48) \
                             | ((uint64_t)(block[(i)])      << 56))

// convert uint64_t value to 8 bytes
#define PUT_UINT64(hash, block, i) {                \
    (block)[(i)]     = (uint8_t)((hash) >> 56);     \
    (block)[(i) + 1] = (uint8_t)((hash) >> 48);     \
    (block)[(i) + 2] = (uint8_t)((hash) >> 40);     \
    (block)[(i) + 3] = (uint8_t)((hash) >> 32);     \
    (block)[(i) + 4] = (uint8_t)((hash) >> 24);     \
    (block)[(i) + 5] = (uint8_t)((hash) >> 16);     \
    (block)[(i) + 6] = (uint8_t)((hash) >> 8);      \
    (block)[(i) + 7] = (uint8_t)((hash));           \
}

// modular prime values
const uint64_t PRIME1 = 11400714785074694791ul;
const uint64_t PRIME2 = 14029467366897019727ul;

typedef struct {
    uint64_t h[8];
    uint64_t len;
    uint8_t buf[128];
    uint32_t idx;
} hash_context;

// Initialize hash context
void init_hash_context(hash_context *ctx) {
    ctx->idx = 0;
    ctx->len = 0;
    memset(ctx->h, 0, sizeof(ctx->h));
    memset(ctx->buf, 0, sizeof(ctx->buf));
}

// Perform F1 operation
void f1(uint64_t *a, uint64_t b, uint64_t c, uint64_t d) {
    *a += ((b ^ c) & d) ^ c;
    *a = ROR(*a, 32);
}

// Perform F2 operation
void f2(uint64_t *a, uint64_t b, uint64_t c, uint64_t d) {
    *a ^= ((~b) | c) ^ d;
    *a = ROL(*a, 32);
}

// Perform compression operation
void compress(hash_context *ctx) {
    uint64_t h[8];
    memcpy(h, ctx->h, sizeof(h));

    uint64_t *x = (uint64_t *)ctx->buf;
    uint64_t a, b, c, d;

    a = h[0]; b = h[1]; c = h[2]; d = h[3];
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);

    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);

    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);

    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);

    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);
    f1(&a, b, c, d); f1(&d, a, b, c); f1(&c, d, a, b); f1(&b, c, d, a);

    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);
    f2(&a, b, c, d); f2(&d, a, b, c); f2(&c, d, a, b); f2(&b, c, d, a);

    h[0] += a; h[1] += b; h[2] += c; h[3] += d;

    memcpy(ctx->h, h, sizeof(h));
}

// Update hash context with new data
void update_hash_context(hash_context *ctx, uint8_t *data, uint32_t len) {
    while (len > 0) {
        uint32_t remaining = 128 - ctx->idx;
        uint32_t chunk = remaining < len ? remaining : len;

        memcpy(ctx->buf + ctx->idx, data, chunk);
        ctx->idx += chunk; ctx->len += chunk;
        data += chunk; len -= chunk;

        if (ctx->idx == 128) {
            compress(ctx);
            ctx->idx = 0;
        }
    }
}

// Finalize the hash and return the result
void finalize_hash(hash_context *ctx, uint8_t *hash) {
    uint32_t pad_len = ctx->idx < 112 ? 112 - ctx->idx : 240 - ctx->idx;

    // append padding bits
    uint8_t padding[240];
    memset(padding, 0, pad_len);
    padding[0] = 0x80;
    PUT_UINT64(ctx->len * 8, padding + pad_len - 8, 0);

    // compress final block
    update_hash_context(ctx, padding, pad_len);
    memset(padding, 0, sizeof(padding));
    PUT_UINT64(ctx->h[0], padding, 0);
    PUT_UINT64(ctx->h[1], padding, 8);
    PUT_UINT64(ctx->h[2], padding, 16);
    PUT_UINT64(ctx->h[3], padding, 24);
    PUT_UINT64(ctx->h[4], padding, 32);
    PUT_UINT64(ctx->h[5], padding, 40);
    PUT_UINT64(ctx->h[6], padding, 48);
    PUT_UINT64(ctx->h[7], padding, 56);

    // compute final hash
    init_hash_context(ctx);
    update_hash_context(ctx, padding, sizeof(padding));
    memcpy(hash, ctx->h, HASH_SIZE);
}

// Generate hash using the given data
void generate_hash(uint8_t *data, uint32_t len, uint8_t *hash) {
    hash_context ctx;
    init_hash_context(&ctx);
    update_hash_context(&ctx, data, len);
    finalize_hash(&ctx, hash);
}

int main() {
    char *data = "This is a test message";
    uint8_t hash[HASH_SIZE];
    generate_hash((uint8_t *)data, strlen(data), hash);

    printf("Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}