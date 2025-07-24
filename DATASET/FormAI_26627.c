//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
// Statistical Cryptographic Hash Function
// Author: Jane Doe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 64
#define OUTPUTSIZE 32

typedef struct {
    unsigned int H[8];
    unsigned int K[64];
    unsigned int len;
    unsigned long long int bits;
    unsigned char block[BLOCKSIZE];
} SHA256_CTX;

unsigned int ROTR(unsigned int x, unsigned int n) {
    return (((x) >> (n)) | ((x) << (32 - (n))));
}

unsigned int Ch(unsigned int x, unsigned int y, unsigned int z) {
    return (((x) & (y)) ^ (~(x) & (z)));
}

unsigned int Maj(unsigned int x, unsigned int y, unsigned int z) {
    return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}

unsigned int Sigma0(unsigned int x) {
    return (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22));
}

unsigned int Sigma1(unsigned int x) {
    return (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25));
}

unsigned int sigma0(unsigned int x) {
    return (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3));
}

unsigned int sigma1(unsigned int x) {
    return (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10));
}

void SHA256_Transform(SHA256_CTX *ctx, unsigned char *input) {
    unsigned int a, b, c, d, e, f, g, h, t1, t2, W[64];
    int i;

    for (i = 0; i < 16; i++)
        W[i] = (unsigned int)input[i * 4 + 3] | (((unsigned int)input[i * 4 + 2]) << 8) |
               (((unsigned int)input[i * 4 + 1]) << 16) | (((unsigned int)input[i * 4]) << 24);
    for (i = 16; i < 64; i++)
        W[i] = W[i - 16] + sigma0(W[i - 15]) + W[i - 7] + sigma1(W[i - 2]);

    a = ctx->H[0];
    b = ctx->H[1];
    c = ctx->H[2];
    d = ctx->H[3];
    e = ctx->H[4];
    f = ctx->H[5];
    g = ctx->H[6];
    h = ctx->H[7];

    for (i = 0; i < 64; i++) {
        t1 = h + Sigma1(e) + Ch(e, f, g) + ctx->K[i] + W[i];
        t2 = Sigma0(a) + Maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    ctx->H[0] += a;
    ctx->H[1] += b;
    ctx->H[2] += c;
    ctx->H[3] += d;
    ctx->H[4] += e;
    ctx->H[5] += f;
    ctx->H[6] += g;
    ctx->H[7] += h;
}

void SHA256_Update(SHA256_CTX *ctx, unsigned char *input, unsigned int len) {
    unsigned int i, idx, partLen;

    idx = (unsigned int)((ctx->bits >> 3) % BLOCKSIZE);
    ctx->bits += (unsigned long long int)len << 3;
    partLen = BLOCKSIZE - idx;

    if (len >= partLen) {
        memcpy(&ctx->block[idx], input, partLen);
        SHA256_Transform(ctx, ctx->block);

        for (i = partLen; i + BLOCKSIZE <= len; i += BLOCKSIZE)
            SHA256_Transform(ctx, &input[i]);

        idx = 0;
    } else {
        i = 0;
    }

    memcpy(&ctx->block[idx], &input[i], len - i);
}

void SHA256_Final(SHA256_CTX *ctx, unsigned char output[OUTPUTSIZE]) {
    unsigned int idx;

    idx = (unsigned int)((ctx->bits >> 3) % BLOCKSIZE);
    ctx->block[idx++] = 0x80;

    if (idx > 56) {
        memset(&ctx->block[idx], 0, BLOCKSIZE - idx);
        SHA256_Transform(ctx, ctx->block);
        idx = 0;
    }

    memset(&ctx->block[idx], 0, 56 - idx);
    ctx->block[56] = (unsigned char)(ctx->bits >> 56);
    ctx->block[57] = (unsigned char)(ctx->bits >> 48);
    ctx->block[58] = (unsigned char)(ctx->bits >> 40);
    ctx->block[59] = (unsigned char)(ctx->bits >> 32);
    ctx->block[60] = (unsigned char)(ctx->bits >> 24);
    ctx->block[61] = (unsigned char)(ctx->bits >> 16);
    ctx->block[62] = (unsigned char)(ctx->bits >> 8);
    ctx->block[63] = (unsigned char)(ctx->bits);

    SHA256_Transform(ctx, ctx->block);

    if (output != NULL) {
        output[0] = (unsigned char)(ctx->H[0] >> 24);
        output[1] = (unsigned char)(ctx->H[0] >> 16);
        output[2] = (unsigned char)(ctx->H[0] >> 8);
        output[3] = (unsigned char)(ctx->H[0]);
        output[4] = (unsigned char)(ctx->H[1] >> 24);
        output[5] = (unsigned char)(ctx->H[1] >> 16);
        output[6] = (unsigned char)(ctx->H[1] >> 8);
        output[7] = (unsigned char)(ctx->H[1]);
        output[8] = (unsigned char)(ctx->H[2] >> 24);
        output[9] = (unsigned char)(ctx->H[2] >> 16);
        output[10] = (unsigned char)(ctx->H[2] >> 8);
        output[11] = (unsigned char)(ctx->H[2]);
        output[12] = (unsigned char)(ctx->H[3] >> 24);
        output[13] = (unsigned char)(ctx->H[3] >> 16);
        output[14] = (unsigned char)(ctx->H[3] >> 8);
        output[15] = (unsigned char)(ctx->H[3]);
        output[16] = (unsigned char)(ctx->H[4] >> 24);
        output[17] = (unsigned char)(ctx->H[4] >> 16);
        output[18] = (unsigned char)(ctx->H[4] >> 8);
        output[19] = (unsigned char)(ctx->H[4]);
        output[20] = (unsigned char)(ctx->H[5] >> 24);
        output[21] = (unsigned char)(ctx->H[5] >> 16);
        output[22] = (unsigned char)(ctx->H[5] >> 8);
        output[23] = (unsigned char)(ctx->H[5]);
        output[24] = (unsigned char)(ctx->H[6] >> 24);
        output[25] = (unsigned char)(ctx->H[6] >> 16);
        output[26] = (unsigned char)(ctx->H[6] >> 8);
        output[27] = (unsigned char)(ctx->H[6]);
        output[28] = (unsigned char)(ctx->H[7] >> 24);
        output[29] = (unsigned char)(ctx->H[7] >> 16);
        output[30] = (unsigned char)(ctx->H[7] >> 8);
        output[31] = (unsigned char)(ctx->H[7]);
    }
}

void SHA256_Init(SHA256_CTX *ctx) {
    ctx->H[0] = 0x6a09e667;
    ctx->H[1] = 0xbb67ae85;
    ctx->H[2] = 0x3c6ef372;
    ctx->H[3] = 0xa54ff53a;
    ctx->H[4] = 0x510e527f;
    ctx->H[5] = 0x9b05688c;
    ctx->H[6] = 0x1f83d9ab;
    ctx->H[7] = 0x5be0cd19;
    ctx->len = 0;
    ctx->bits = 0ULL;
    memset(ctx->block, 0, BLOCKSIZE);
    memset(ctx->K, 0, 64);
    ctx->K[0] = 0x428a2f98;
    ctx->K[1] = 0x71374491;
    ctx->K[2] = 0xb5c0fbcf;
    ctx->K[3] = 0xe9b5dba5;
    ctx->K[4] = 0x3956c25b;
    ctx->K[5] = 0x59f111f1;
    ctx->K[6] = 0x923f82a4;
    ctx->K[7] = 0xab1c5ed5;
    ctx->K[8] = 0xd807aa98;
    ctx->K[9] = 0x12835b01;
    ctx->K[10] = 0x243185be;
    ctx->K[11] = 0x550c7dc3;
    ctx->K[12] = 0x72be5d74;
    ctx->K[13] = 0x80deb1fe;
    ctx->K[14] = 0x9bdc06a7;
    ctx->K[15] = 0xc19bf174;
    ctx->K[16] = 0xe49b69c1;
    ctx->K[17] = 0xefbe4786;
    ctx->K[18] = 0x0fc19dc6;
    ctx->K[19] = 0x240ca1cc;
    ctx->K[20] = 0x2de92c6f;
    ctx->K[21] = 0x4a7484aa;
    ctx->K[22] = 0x5cb0a9dc;
    ctx->K[23] = 0x76f988da;
    ctx->K[24] = 0x983e5152;
    ctx->K[25] = 0xa831c66d;
    ctx->K[26] = 0xb00327c8;
    ctx->K[27] = 0xbf597fc7;
    ctx->K[28] = 0xc6e00bf3;
    ctx->K[29] = 0xd5a79147;
    ctx->K[30] = 0x06ca6351;
    ctx->K[31] = 0x14292967;
    ctx->K[32] = 0x27b70a85;
    ctx->K[33] = 0x2e1b2138;
    ctx->K[34] = 0x4d2c6dfc;
    ctx->K[35] = 0x53380d13;
    ctx->K[36] = 0x650a7354;
    ctx->K[37] = 0x766a0abb;
    ctx->K[38] = 0x81c2c92e;
    ctx->K[39] = 0x92722c85;
    ctx->K[40] = 0xa2bfe8a1;
    ctx->K[41] = 0xa81a664b;
    ctx->K[42] = 0xc24b8b70;
    ctx->K[43] = 0xc76c51a3;
    ctx->K[44] = 0xd192e819;
    ctx->K[45] = 0xd6990624;
    ctx->K[46] = 0xf40e3585;
    ctx->K[47] = 0x106aa070;
    ctx->K[48] = 0x19a4c116;
    ctx->K[49] = 0x1e376c08;
    ctx->K[50] = 0x2748774c;
    ctx->K[51] = 0x34b0bcb5;
    ctx->K[52] = 0x391c0cb3;
    ctx->K[53] = 0x4ed8aa4a;
    ctx->K[54] = 0x5b9cca4f;
    ctx->K[55] = 0x682e6ff3;
    ctx->K[56] = 0x748f82ee;
    ctx->K[57] = 0x78a5636f;
    ctx->K[58] = 0x84c87814;
    ctx->K[59] = 0x8cc70208;
    ctx->K[60] = 0x90befffa;
    ctx->K[61] = 0xa4506ceb;
    ctx->K[62] = 0xbef9a3f7;
    ctx->K[63] = 0xc67178f2;
}

int main() {
    
    SHA256_CTX ctx;
    unsigned char input[50] = "Hello World!";
    unsigned char output[OUTPUTSIZE];
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, strlen((char *)input));
    SHA256_Final(&ctx, output);

    printf("Input: %s\n", input);
    printf("Output: ");
    for (int i = 0; i < OUTPUTSIZE; i++)
        printf("%02x", output[i]);
    printf("\n");

    return 0;
}