//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Block size in bytes */
#define BLOCK_SIZE 64

/* Digest size in bytes */
#define DIGEST_SIZE 20

/* SHA1 constants */
#define K1 0x5a827999
#define K2 0x6ed9eba1
#define K3 0x8f1bbcdc
#define K4 0xca62c1d6

/* Rotate left function */
#define S(x,n) (((x) << (n)) | ((x) >> (32 - (n))))

/* SHA1 context structure */
typedef struct {
    uint32_t digest[DIGEST_SIZE / 4];
    uint32_t w[80];
    uint32_t buffer_len;
    unsigned char buffer[BLOCK_SIZE];
    uint64_t message_len;
} SHA1_CTX;

/* Initialize SHA1 context */
void SHA1_Init(SHA1_CTX *ctx) {
    ctx->digest[0] = 0x67452301;
    ctx->digest[1] = 0xefcdab89;
    ctx->digest[2] = 0x98badcfe;
    ctx->digest[3] = 0x10325476;
    ctx->digest[4] = 0xc3d2e1f0;
    ctx->buffer_len = 0;
    ctx->message_len = 0;
}

/* SHA1 message schedule */
void SHA1_Message_Schedule(uint32_t *w) {
    for (int i = 16; i < 80; i++) {
        w[i] = S((w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]), 1);
    }
}

/* SHA1 compression function */
void SHA1_Compress(SHA1_CTX *ctx) {
    /* Copy the buffer into the message schedule */
    for (int i = 0; i < 16; i++) {
        ctx->w[i] = (ctx->buffer[i*4] << 24) |
                    (ctx->buffer[i*4+1] << 16) |
                    (ctx->buffer[i*4+2] << 8) |
                    (ctx->buffer[i*4+3]);
    }
    
    /* Initialize the rest of the message schedule */
    SHA1_Message_Schedule(ctx->w);
    
    /* Initialize working variables */
    uint32_t a = ctx->digest[0];
    uint32_t b = ctx->digest[1];
    uint32_t c = ctx->digest[2];
    uint32_t d = ctx->digest[3];
    uint32_t e = ctx->digest[4];
    
    /* Main loop */
    for (int i = 0; i < 80; i++) {
        uint32_t f, k;
        if (i < 20) {
            f = (b & c) | ((~b) & d);
            k = K1;
        } else if (i < 40) {
            f = b ^ c ^ d;
            k = K2;
        } else if (i < 60) {
            f = (b & c) | (b & d) | (c & d);
            k = K3;
        } else {
            f = b ^ c ^ d;
            k = K4;
        }
        uint32_t temp = S(a, 5) + f + e + k + ctx->w[i];
        e = d;
        d = c;
        c = S(b, 30);
        b = a;
        a = temp;
    }
    
    /* Update the digest */
    ctx->digest[0] += a;
    ctx->digest[1] += b;
    ctx->digest[2] += c;
    ctx->digest[3] += d;
    ctx->digest[4] += e;
}

/* Update SHA1 context with more input data */
void SHA1_Update(SHA1_CTX *ctx, const void *data, size_t len) {
    const unsigned char *p = data;
    while (len--) {
        ctx->buffer[ctx->buffer_len++] = *p++;
        if (ctx->buffer_len == BLOCK_SIZE) {
            SHA1_Compress(ctx);
            ctx->buffer_len = 0;
        }
        ctx->message_len++;
    }
}

/* Finalize SHA1 context and produce hash */
void SHA1_Final(unsigned char digest[DIGEST_SIZE], SHA1_CTX *ctx) {
    /* Pad the message */
    ctx->buffer[ctx->buffer_len++] = 0x80;
    if (ctx->buffer_len > 56) {
        memset(ctx->buffer + ctx->buffer_len, 0, BLOCK_SIZE - ctx->buffer_len);
        SHA1_Compress(ctx);
        ctx->buffer_len = 0;
    }
    memset(ctx->buffer + ctx->buffer_len, 0, 56 - ctx->buffer_len);
    ctx->buffer_len = 64 - 8;
    
    /* Append message length */
    for (int i = 0; i < 8; i++) {
        ctx->buffer[ctx->buffer_len + i] = (unsigned char)(ctx->message_len >> ((7 - i) * 8));
    }
    
    /* Final compress and produce digest */
    SHA1_Compress(ctx);
    for (int i = 0; i < DIGEST_SIZE / 4; i++) {
        digest[i*4] = (unsigned char)(ctx->digest[i] >> 24);
        digest[i*4+1] = (unsigned char)(ctx->digest[i] >> 16);
        digest[i*4+2] = (unsigned char)(ctx->digest[i] >> 8);
        digest[i*4+3] = (unsigned char)(ctx->digest[i]);
    }
}

/* Example usage */
int main(int argc, char **argv) {
    SHA1_CTX ctx;
    unsigned char digest[DIGEST_SIZE];
    
    /* User input */
    char *input = "Hello, world!";
    
    /* SHA1 hash the input */
    SHA1_Init(&ctx);
    SHA1_Update(&ctx, input, strlen(input));
    SHA1_Final(digest, &ctx);
    
    /* Output the digest */
    printf("The SHA1 hash of \"%s\" is:\n", input);
    for (int i = 0; i < DIGEST_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    
    return 0;
}