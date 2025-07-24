//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t s[256];
    uint8_t i;
    uint8_t j;
} RC4Context;

void RC4Init(RC4Context *ctx, const uint8_t *key, uint32_t keylen) {
    uint8_t t, u;
    for (int i = 0; i < 256; i++) {
        ctx->s[i] = i;
    }
    for (int i = 0, j = 0; i < 256; i++) {
        j = (j + ctx->s[i] + key[i % keylen]) % 256;
        t = ctx->s[i];
        ctx->s[i] = ctx->s[j];
        ctx->s[j] = t;
    }
    ctx->i = ctx->j = 0;
}

void RC4Crypt(RC4Context *ctx, const uint8_t *inbuf, uint8_t *outbuf, uint32_t buflen) {
    uint8_t t;
    for (int i = 0; i < buflen; i++) {
        ctx->i = (ctx->i + 1) % 256;
        ctx->j = (ctx->j + ctx->s[ctx->i]) % 256;
        t = ctx->s[ctx->i];
        ctx->s[ctx->i] = ctx->s[ctx->j];
        ctx->s[ctx->j] = t;
        outbuf[i] = inbuf[i] ^ ctx->s[(ctx->s[ctx->i] + ctx->s[ctx->j]) % 256];
    }
}

int main(int argc, char** argv) {
    RC4Context ctx;
    uint8_t key[] = "my-secret-key";
    uint8_t inbuf[] = "This is a test message";
    uint8_t outbuf[1024];
    uint32_t buflen = strlen((const char *)inbuf);

    RC4Init(&ctx, key, sizeof(key) - 1);
    RC4Crypt(&ctx, inbuf, outbuf, buflen);

    printf("Ciphered message: ");
    for (int i = 0; i < buflen; i++) {
        printf("%02x", outbuf[i]);
    }
    printf("\n");

    RC4Init(&ctx, key, sizeof(key) - 1);
    RC4Crypt(&ctx, outbuf, inbuf, buflen);

    printf("Deciphered message: %s\n", inbuf);
    
    return 0;
}