//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32-(y))))

#define SHA256_BLOCK_SIZE 32           // SHA256 outputs in 256 bits (= 32 bytes)

// Hash structure
typedef struct {
    uint8_t data[64];
    uint32_t datalen;
    uint64_t bitlen;
    uint32_t state[8];
} sha256_ctx;

// SHA256 Constants
const uint32_t sha256_constants[] = {
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

// SHA256 Functions
void sha256_transform(sha256_ctx *ctx, const uint8_t *data);
void sha256_init(sha256_ctx *ctx);
void sha256_update(sha256_ctx *ctx, const uint8_t *data, uint32_t len);
void sha256_final(sha256_ctx *ctx, uint8_t *hash);

// Main function to calculate cryptographic hash
int main()
{
    // Data to perform hash on
    char* input = "Hello World!";
    sha256_ctx hash_ctx;
    uint8_t hash[SHA256_BLOCK_SIZE];
    
    // Hash initialization
    sha256_init(&hash_ctx);
    
    // Hash update
    sha256_update(&hash_ctx, (uint8_t*)input, strlen(input));
    
    // Hash finalization
    sha256_final(&hash_ctx, hash);
    
    // Print hash output
    for (int i=0; i<SHA256_BLOCK_SIZE; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    return 0;
}

// SHA256 Initialization
void sha256_init(sha256_ctx *ctx)
{
    ctx->datalen = 0;
    ctx->bitlen = 0;
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}

// SHA256 Update
void sha256_update(sha256_ctx *ctx, const uint8_t *data, uint32_t len) 
{
    uint32_t i;
    for (i=0; i<len; i++) 
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

// SHA256 Finalization
void sha256_final(sha256_ctx *ctx, uint8_t *hash) 
{
    uint32_t i;
    i = ctx->datalen;
  
    // Pad whatever data is left in the buffer
    if (ctx->datalen < 56) 
    {
        ctx->data[i++] = 0x80;
        while (i < 56)
            ctx->data[i++] = 0x00;
    } 
    else 
    {
        ctx->data[i++] = 0x80;
        while (i < 64)
            ctx->data[i++] = 0x00;
        sha256_transform(ctx, ctx->data);
        memset(ctx->data, 0, 56);
    }
    ctx->bitlen += ctx->datalen * 8;
    ctx->data[63] = ctx->bitlen;
    ctx->data[62] = ctx->bitlen >> 8;
    ctx->data[61] = ctx->bitlen >> 16;
    ctx->data[60] = ctx->bitlen >> 24;
    ctx->data[59] = ctx->bitlen >> 32;
    ctx->data[58] = ctx->bitlen >> 40;
    ctx->data[57] = ctx->bitlen >> 48;
    ctx->data[56] = ctx->bitlen >> 56;
    sha256_transform(ctx, ctx->data);
  
    // Since this implementation uses little endian byte ordering and SHA uses big endian, 
    // reverse all the bytes when copying the final hash to the output hash.
    for (i=0; i<4; i++) {
        hash[i]    = (ctx->state[0] >> (24-i*8)) & 0x000000ff;
        hash[i+4]  = (ctx->state[1] >> (24-i*8)) & 0x000000ff;
        hash[i+8]  = (ctx->state[2] >> (24-i*8)) & 0x000000ff;
        hash[i+12] = (ctx->state[3] >> (24-i*8)) & 0x000000ff;
        hash[i+16] = (ctx->state[4] >> (24-i*8)) & 0x000000ff;
        hash[i+20] = (ctx->state[5] >> (24-i*8)) & 0x000000ff;
        hash[i+24] = (ctx->state[6] >> (24-i*8)) & 0x000000ff;
        hash[i+28] = (ctx->state[7] >> (24-i*8)) & 0x000000ff;
    }
}

// SHA256 Transform
void sha256_transform(sha256_ctx *ctx, const uint8_t *data) 
{
    uint32_t i, j;
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h;
  
    // Copy data into w array
    for (i=0,j=0; i<16; i++,j+=4)
        w[i] = (data[j] << 24) | (data[j+1] << 16) | (data[j+2] << 8) | (data[j+3]);
    for ( ; i<64; i++) 
        w[i] = (ROTL(w[i-2], 17) ^ ROTL(w[i-2], 19) ^ (w[i-2] >> 10)) + w[i-7] + 
               (ROTL(w[i-15], 7) ^ ROTL(w[i-15], 18) ^ (w[i-15] >> 3)) + w[i-16];

    // Initialize working variables
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    // Compression loop
    for (i=0; i<64; i++) 
    {
        uint32_t t1 = h + (ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25)) + ((e & f) ^ ((~e) & g)) + 
                      sha256_constants[i] + w[i];
        uint32_t t2 = (ROTL(a, 2) ^ ROTL(a, 13) ^ ROTL(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
    
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Update hash state
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}