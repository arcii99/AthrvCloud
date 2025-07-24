//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BLOCK_SIZE 64
#define SHA256_DIGEST_SIZE 32
#define THREADS_COUNT 4

struct sha256_context {
    unsigned char data[BLOCK_SIZE];
    unsigned int datalen;
    unsigned long long bitlen;
    unsigned int state[8];
    pthread_mutex_t lock;
};

unsigned int K[] = {
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

char* sha256(const char* message);
void sha256_transform(struct sha256_context* ctx, const unsigned char* data);
void sha256_update(struct sha256_context* ctx, const unsigned char* data, unsigned int len);
void sha256_final(struct sha256_context* ctx, unsigned char* hash);

void sha256_transform(struct sha256_context* ctx, const unsigned char* data) {
    pthread_mutex_lock(&ctx->lock);

    unsigned int a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

    for (i = 0, j = 0; i < 16; ++i, j += 4)
    {
        m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
    }
    for (; i < 64; ++i)
    {
        m[i] = (m[i - 16] + m[i - 7] + ((m[i - 15] >> 7) | (m[i - 15] << 25)) + ((m[i - 15] >> 18) | (m[i - 15] << 14)) +
            ((m[i - 15] >> 3) ^ (m[i - 15] >> 11) ^ (m[i - 15] << 21)) +
            ((m[i - 2] >> 17) | (m[i - 2] << 15)) + ((m[i - 2] >> 19) | (m[i - 2] << 13)) +
            ((m[i - 2] >> 10) ^ (m[i - 2] >> 12) ^ (m[i - 2] << 22))) & 0xffffffff;
    }

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    for (i = 0; i < 64; ++i)
    {
        t1 = h + ((e >> 6) | (e << 26)) + (((e & f) ^ (~e & g)) + K[i] + m[i]);
        t2 = ((a >> 2) | (a << 30)) + ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;

    pthread_mutex_unlock(&ctx->lock);
}

void sha256_update(struct sha256_context* ctx, const unsigned char* data, unsigned int len) {
    unsigned int i;

    for (i = 0; i < len; ++i)
    {
        ctx->data[ctx->datalen] = data[i];
        ctx->datalen++;
        if (ctx->datalen == 64)
        {
            sha256_transform(ctx, ctx->data);
            ctx->bitlen += 512;
            ctx->datalen = 0;
        }
    }
}

void sha256_final(struct sha256_context* ctx, unsigned char* hash) {
    unsigned int i;

    i = ctx->datalen;

    if (ctx->datalen < 56)
    {
        ctx->data[i++] = 0x80;
        while (i < 56)
        {
            ctx->data[i++] = 0x00;
        }
    }
    else
    {
        ctx->data[i++] = 0x80;
        while (i < 64)
        {
            ctx->data[i++] = 0x00;
        }
        sha256_transform(ctx, ctx->data);
        memset(ctx->data, 0, 56);
    }

    ctx->bitlen += ctx->datalen * 8;
    ctx->data[63] = (unsigned char)ctx->bitlen;
    ctx->data[62] = (unsigned char)(ctx->bitlen >> 8);
    ctx->data[61] = (unsigned char)(ctx->bitlen >> 16);
    ctx->data[60] = (unsigned char)(ctx->bitlen >> 24);
    ctx->data[59] = (unsigned char)(ctx->bitlen >> 32);
    ctx->data[58] = (unsigned char)(ctx->bitlen >> 40);
    ctx->data[57] = (unsigned char)(ctx->bitlen >> 48);
    ctx->data[56] = (unsigned char)(ctx->bitlen >> 56);
    sha256_transform(ctx, ctx->data);

    for (i = 0; i < 8; ++i)
    {
        hash[i * 4 + 0] = (ctx->state[i] >> 24);
        hash[i * 4 + 1] = (ctx->state[i] >> 16);
        hash[i * 4 + 2] = (ctx->state[i] >> 8);
        hash[i * 4 + 3] = (ctx->state[i]);
    }
}

void* thread_sha256(void* arg) {
    struct sha256_context* ctx = (struct sha256_context*)arg;
    sha256_final(ctx, ctx->data);
    return NULL;
}

char* sha256(const char* message) {
    int message_len = strlen(message);

    struct sha256_context ctx[THREADS_COUNT];

    unsigned char hash[SHA256_DIGEST_SIZE];

    int i;

    for (i = 0; i < THREADS_COUNT; i++) {
        ctx[i].datalen = 0;
        ctx[i].bitlen = 0;

        ctx[i].state[0] = 0x6a09e667;
        ctx[i].state[1] = 0xbb67ae85;
        ctx[i].state[2] = 0x3c6ef372;
        ctx[i].state[3] = 0xa54ff53a;
        ctx[i].state[4] = 0x510e527f;
        ctx[i].state[5] = 0x9b05688c;
        ctx[i].state[6] = 0x1f83d9ab;
        ctx[i].state[7] = 0x5be0cd19;

        pthread_mutex_init(&ctx[i].lock, NULL);
    }

    for (i = 0; i < THREADS_COUNT; i++) {
        sha256_update(&ctx[i], message, message_len / THREADS_COUNT);
    }
    if (message_len % THREADS_COUNT != 0) {
        sha256_update(&ctx[THREADS_COUNT - 1], message + message_len - message_len % THREADS_COUNT, message_len % THREADS_COUNT);
    }

    pthread_t threads[THREADS_COUNT];

    for (i = 0; i < THREADS_COUNT; i++) {
        pthread_create(&threads[i], NULL, &thread_sha256, &ctx[i]);
    }

    for (i = 0; i < THREADS_COUNT; i++) {
        pthread_join(threads[i], NULL);
        pthread_mutex_destroy(&ctx[i].lock);
    }

    for (i = 1; i < THREADS_COUNT; i++) {
        sha256_update(&ctx[0], ctx[i].data, SHA256_DIGEST_SIZE);
    }

    sha256_final(&ctx[0], hash);

    char* output = (char*)malloc(SHA256_DIGEST_SIZE * 2 + 1);

    for (i = 0; i < SHA256_DIGEST_SIZE; i++) {
        sprintf(output + i * 2, "%02x", hash[i]);
    }

    output[SHA256_DIGEST_SIZE * 2] = '\0';

    return output;
}

int main() {
    char* hash = sha256("Hello, world!");
    printf("%s\n", hash);
    free(hash);
    return 0;
}