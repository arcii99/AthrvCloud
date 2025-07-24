//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
// Rotate left macro
#define ROTL(x,n) ((x << n) | (x >> (32-n)))
 
// Ch macro
#define CH(x,y,z) ((x & y)^(~x & z))
 
// Maj macro
#define MAJ(x,y,z) ((x & y)^(x & z)^(y & z))
 
// Sigma0 macro
#define SIGMA0(x) (ROTL(x,2)^ROTL(x,13)^ROTL(x,22))
 
// Sigma1 macro
#define SIGMA1(x) (ROTL(x,6)^ROTL(x,11)^ROTL(x,25))
 
// sigma0 macro
#define sigma0(x) (ROTL(x,7)^ROTL(x,18)^(x>>3))
 
// sigma1 macro
#define sigma1(x) (ROTL(x,17)^ROTL(x,19)^(x>>10))
 
// Buffer structure
typedef struct{
    uint8_t data[64];
    uint32_t datalen;
    uint32_t bitlen[2];
    uint32_t state[8];
} SHA256_CTX;
 
// Initializing constants
const uint32_t K[] = {
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
 
// Initialize SHA256
void sha256_init(SHA256_CTX *ctx){
    ctx->datalen = 0;
    ctx->bitlen[0] = 0;
    ctx->bitlen[1] = 0;
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}
 
// SHA256 Update function
void sha256_update(SHA256_CTX *ctx, const uint8_t data[], size_t len){
    uint32_t t;
    for(int i=0; i<len; i++){
        ctx->data[ctx->datalen] = data[i];
        ctx->datalen++;
        if(ctx->datalen == 64){
            // Do the hash
            for(int j=0;j<16;j++){
                t = data[j*4];
                t = (t << 8) | data[j*4+1];
                t = (t << 8) | data[j*4+2];
                t = (t << 8) | data[j*4+3];
            }
            for(int j=16;j<64;j++){
                t = sigma1(ctx->data[j-2]) + ctx->data[j-7] + sigma0(ctx->data[j-15]) + ctx->data[j-16];
                ctx->data[j] = t;
            }
 
            // Initialize variables
            uint32_t a = ctx->state[0];
            uint32_t b = ctx->state[1];
            uint32_t c = ctx->state[2];
            uint32_t d = ctx->state[3];
            uint32_t e = ctx->state[4];
            uint32_t f = ctx->state[5];
            uint32_t g = ctx->state[6];
            uint32_t h = ctx->state[7];
 
            // Run the compression function
            uint32_t t1, t2;
            for(int j=0; j<64; j++){
                t1 = h + SIGMA1(e) + CH(e,f,g) + K[j] + ctx->data[j];
                t2 = SIGMA0(a) + MAJ(a,b,c);
                h = g;
                g = f;
                f = e;
                e = d + t1;
                d = c;
                c = b;
                b = a;
                a = t1 + t2;
            }
 
            // Update state
            ctx->state[0] += a;
            ctx->state[1] += b;
            ctx->state[2] += c;
            ctx->state[3] += d;
            ctx->state[4] += e;
            ctx->state[5] += f;
            ctx->state[6] += g;
            ctx->state[7] += h;
 
            // Reset datalen
            ctx->datalen = 0;
        }
    }
}
 
// SHA256 Final function
void sha256_final(SHA256_CTX *ctx, uint8_t hash[]){
    uint32_t t;
    int i;
    i = ctx->datalen;
 
    // Pad whatever data is left in the buffer
    if(ctx->datalen < 56){
        ctx->data[i++] = 0x80;
        while(i < 56)
            ctx->data[i++] = 0x00;
    }
    else{
        ctx->data[i++] = 0x80;
        while(i < 64)
            ctx->data[i++] = 0x00;
        sha256_update(ctx, ctx->data, 64);
        memset(ctx->data, 0, 56);
    }
 
    // Add the total bits
    ctx->bitlen[0] = (ctx->bitlen[0] << 3) | (ctx->bitlen[1] >> 29);
    ctx->bitlen[1] = (ctx->bitlen[1] << 3);
    ctx->data[63] = ctx->bitlen[0];
    ctx->data[62] = ctx->bitlen[0] >> 8;
    ctx->data[61] = ctx->bitlen[0] >> 16;
    ctx->data[60] = ctx->bitlen[0] >> 24;
    ctx->data[59] = ctx->bitlen[1];
    ctx->data[58] = ctx->bitlen[1] >> 8;
    ctx->data[57] = ctx->bitlen[1] >> 16;
    ctx->data[56] = ctx->bitlen[1] >> 24;
    sha256_update(ctx, ctx->data, 64);
 
    // Get the hash
    for(i= 0; i<4; i++){
        t = ctx->state[0] >> (24-i*8);
        hash[i] = (uint8_t)(t & 0x000000ff);
        t = ctx->state[1] >> (24-i*8);
        hash[i+4] = (uint8_t)(t & 0x000000ff);
        t = ctx->state[2] >> (24-i*8);
        hash[i+8] = (uint8_t)(t & 0x000000ff);
        t = ctx->state[3] >> (24-i*8);
        hash[i+12] = (uint8_t)(t & 0x000000ff);
        t = ctx->state[4] >> (24-i*8);
        hash[i+16] = (uint8_t)(t & 0x000000ff);
        t = ctx->state[5] >> (24-i*8);
        hash[i+20] = (uint8_t)(t & 0x000000ff);
        t = ctx->state[6] >> (24-i*8);
        hash[i+24] = (uint8_t)(t & 0x000000ff);
        t = ctx->state[7] >> (24-i*8);
        hash[i+28] = (uint8_t)(t & 0x000000ff);
    }
}
 
int main(){
    // Initialize SHA256 Context and hash
    char *str = "Hello World";
    SHA256_CTX ctx;
    uint8_t hash[32];
 
    // Initialize context and update with string
    sha256_init(&ctx);
    sha256_update(&ctx, str, strlen(str));
 
    // Finalize the hash calculation
    sha256_final(&ctx, hash);
 
    // Print the hash
    printf("Hash: ");
    for(int i=0; i<32; i++)
        printf("%02x", hash[i]);
    printf("\n");
 
    return 0;
}