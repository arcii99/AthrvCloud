//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x,y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x,y) ((x >> y) | (x << (32 - y)))
#define ROTL64(x,y) ((x << y) | (x >> (64 - y)))
#define ROTR64(x,y) ((x >> y) | (x << (64 - y)))

typedef struct {
    uint32_t state[8];
    uint32_t counter[2];
    uint8_t buffer[64];
    uint32_t buffer_size;
} sha3_ctx_t;

void sha3_init(sha3_ctx_t *context, int bits)
{
    memset(context, 0, sizeof(*context));
    if (bits == 256) {
        context->state[0] = 0x6a09e667;
        context->state[1] = 0xbb67ae85;
        context->state[2] = 0x3c6ef372;
        context->state[3] = 0xa54ff53a;
        context->state[4] = 0x510e527f;
        context->state[5] = 0x9b05688c;
        context->state[6] = 0x1f83d9ab;
        context->state[7] = 0x5be0cd19;
    } else if (bits == 512) {
        context->state[0] = 0x6a09e667;
        context->state[1] = 0xf3bcc908;
        context->state[2] = 0xbb67ae85;
        context->state[3] = 0x84caa73b;
        context->state[4] = 0x3c6ef372;
        context->state[5] = 0xfe94f82b;
        context->state[6] = 0xa54ff53a;
        context->state[7] = 0x5f1d36f1;
    }
}

void sha3_update(sha3_ctx_t *context, const uint8_t *data, size_t length)
{
    int i, j;
    for (i = 0; i < length; i++) {
        context->buffer[context->buffer_size++] = data[i];
        if (context->buffer_size == 64) {
            uint32_t words[16];
            for (j = 0; j < 16; j++) {
                words[j] = ((uint32_t) context->buffer[j * 4 + 0] << 24) |
                    ((uint32_t) context->buffer[j * 4 + 1] << 16) |
                    ((uint32_t) context->buffer[j * 4 + 2] << 8) |
                    ((uint32_t) context->buffer[j * 4 + 3]);
            }
            uint32_t A = context->state[0];
            uint32_t B = context->state[1];
            uint32_t C = context->state[2];
            uint32_t D = context->state[3];
            uint32_t E = context->state[4];
            uint32_t F = context->state[5];
            uint32_t G = context->state[6];
            uint32_t H = context->state[7];
            uint32_t T1, T2;
            for (j = 0; j < 64; j++) {
                T1 = H + ROTR32(E, 6) + ((E & F) ^ (~E & G)) + 0x428a2f98 + words[j];
                T2 = ROTR32(A, 2) + ((A & B) ^ (A & C) ^ (B & C));
                H = G;
                G = F;
                F = E;
                E = D + T1;
                D = C;
                C = B;
                B = A;
                A = T1 + T2;
            }
            context->state[0] += A;
            context->state[1] += B;
            context->state[2] += C;
            context->state[3] += D;
            context->state[4] += E;
            context->state[5] += F;
            context->state[6] += G;
            context->state[7] += H;
            context->buffer_size = 0;
        }
    }
}

void sha3_final(sha3_ctx_t *context, uint8_t *digest, int bits)
{
    int i, j;
    context->buffer[context->buffer_size++] = 0x06;
    while (context->buffer_size != 56) {
        if (context->buffer_size == 64) {
            uint32_t words[16];
            for (j = 0; j < 16; j++) {
                words[j] = ((uint32_t) context->buffer[j * 4 + 0] << 24) |
                    ((uint32_t) context->buffer[j * 4 + 1] << 16) |
                    ((uint32_t) context->buffer[j * 4 + 2] << 8) |
                    ((uint32_t) context->buffer[j * 4 + 3]);
            }
            uint32_t A = context->state[0];
            uint32_t B = context->state[1];
            uint32_t C = context->state[2];
            uint32_t D = context->state[3];
            uint32_t E = context->state[4];
            uint32_t F = context->state[5];
            uint32_t G = context->state[6];
            uint32_t H = context->state[7];
            uint32_t T1, T2;
            for (j = 0; j < 64; j++) {
                T1 = H + ROTR32(E, 6) + ((E & F) ^ (~E & G)) + 0x428a2f98 + words[j];
                T2 = ROTR32(A, 2) + ((A & B) ^ (A & C) ^ (B & C));
                H = G;
                G = F;
                F = E;
                E = D + T1;
                D = C;
                C = B;
                B = A;
                A = T1 + T2;
            }
            context->state[0] += A;
            context->state[1] += B;
            context->state[2] += C;
            context->state[3] += D;
            context->state[4] += E;
            context->state[5] += F;
            context->state[6] += G;
            context->state[7] += H;
            context->buffer_size = 0;
        } else {
            context->buffer[context->buffer_size++] = 0;
        }
    }
    context->buffer[56] = (bits == 256 ? 0x01 : 0x02);
    uint32_t words[16];
    for (j = 0; j < 16; j++) {
        words[j] = ((uint32_t) context->buffer[j * 4 + 0] << 24) |
            ((uint32_t) context->buffer[j * 4 + 1] << 16) |
            ((uint32_t) context->buffer[j * 4 + 2] << 8) |
            ((uint32_t) context->buffer[j * 4 + 3]);
    }
    uint32_t A = context->state[0];
    uint32_t B = context->state[1];
    uint32_t C = context->state[2];
    uint32_t D = context->state[3];
    uint32_t E = context->state[4];
    uint32_t F = context->state[5];
    uint32_t G = context->state[6];
    uint32_t H = context->state[7];
    uint32_t T1, T2;
    for (j = 0; j < 64; j++) {
        T1 = H + ROTR32(E, 6) + ((E & F) ^ (~E & G)) + 0x428a2f98 + words[j];
        T2 = ROTR32(A, 2) + ((A & B) ^ (A & C) ^ (B & C));
        H = G;
        G = F;
        F = E;
        E = D + T1;
        D = C;
        C = B;
        B = A;
        A = T1 + T2;
    }
    context->state[0] += A;
    context->state[1] += B;
    context->state[2] += C;
    context->state[3] += D;
    context->state[4] += E;
    context->state[5] += F;
    context->state[6] += G;
    context->state[7] += H;
    if (bits == 256) {
        for (i = 0; i < 8; i++) {
            digest[i * 4 + 0] = (context->state[i] >> 24) & 0xff;
            digest[i * 4 + 1] = (context->state[i] >> 16) & 0xff;
            digest[i * 4 + 2] = (context->state[i] >> 8) & 0xff;
            digest[i * 4 + 3] = context->state[i] & 0xff;
        }
    } else if (bits == 512) {
        for (i = 0; i < 8; i++) {
            digest[i * 8 + 0] = (context->state[i] >> 56) & 0xff;
            digest[i * 8 + 1] = (context->state[i] >> 48) & 0xff;
            digest[i * 8 + 2] = (context->state[i] >> 40) & 0xff;
            digest[i * 8 + 3] = (context->state[i] >> 32) & 0xff;
            digest[i * 8 + 4] = (context->state[i] >> 24) & 0xff;
            digest[i * 8 + 5] = (context->state[i] >> 16) & 0xff;
            digest[i * 8 + 6] = (context->state[i] >> 8) & 0xff;
            digest[i * 8 + 7] = context->state[i] & 0xff;
        }
    }
}

int main()
{
    sha3_ctx_t context;
    uint8_t digest[64];
    char *input_string = "Hello, world!";
    sha3_init(&context, 256);
    sha3_update(&context, (const uint8_t *) input_string, strlen(input_string));
    sha3_final(&context, digest, 256);

    printf("SHA3-256 hash of \"%s\" is: ", input_string);
    for (int i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}