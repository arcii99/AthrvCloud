//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SHA256_BLOCK_SIZE 32
#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))
#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define SIGMA0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define SIGMA1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define DELTA0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define DELTA1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
    0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
    0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
    0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
    0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
    0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
    0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
    0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
    0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
    0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256_transform(uint32_t *state, const unsigned char data[]) {
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, W[64];

    for (i=0, j=0; i < 16; ++i, j += 4) {
         W[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
    }

    for ( ; i < 64; ++i) {
         W[i] = DELTA1(W[i-2]) + W[i-7] + DELTA0(W[i-15]) + W[i-16];
    }

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    for (i = 0; i < 64; ++i) {
         t1 = h + SIGMA1(e) + CH(e, f, g) + K[i] + W[i];
         t2 = SIGMA0(a) + MAJ(a, b, c);
         h = g;
         g = f;
         f = e;
         e = d + t1;
         d = c;
         c = b;
         b = a;
         a = t1 + t2;
    }
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

void sha256(const unsigned char *message, unsigned int len, unsigned char *digest) {
    uint32_t state[8], i, new_len, bit_len;
    unsigned char *msg, *p;

    state[0] = 0x6a09e667;
    state[1] = 0xbb67ae85;
    state[2] = 0x3c6ef372;
    state[3] = 0xa54ff53a;
    state[4] = 0x510e527f;
    state[5] = 0x9b05688c;
    state[6] = 0x1f83d9ab;
    state[7] = 0x5be0cd19;

    new_len = ((((len + 8) / 64) + 1) * 64) - 8;

    msg = (unsigned char*)malloc(new_len + 64);
    memcpy(msg, message, len);
    msg[len] = 0x80;
    for (i = len + 1; i < new_len; ++i) {
        msg[i] = 0;
    }

    bit_len = len * 8;
    p = msg + new_len;
    *p++ = (bit_len >> 56) & 0xff;
    *p++ = (bit_len >> 48) & 0xff;
    *p++ = (bit_len >> 40) & 0xff;
    *p++ = (bit_len >> 32) & 0xff;
    *p++ = (bit_len >> 24) & 0xff;
    *p++ = (bit_len >> 16) & 0xff;
    *p++ = (bit_len >> 8) & 0xff;
    *p++ = bit_len & 0xff;

    for (i=0; i < new_len; i += 64) {
        sha256_transform(state, msg + i);
    }
    memcpy(digest, state, SHA256_BLOCK_SIZE);
    
    free(msg);
}

int main(int argc, char *argv[]) {
    unsigned char text[] = "This is a test message";
    unsigned char hash[SHA256_BLOCK_SIZE];
    int i;

    sha256(text, strlen((char*)text), hash);
    printf("SHA256 Hash: ");
    for (i=0; i < SHA256_BLOCK_SIZE; ++i) {
        printf("%02x ", hash[i]);
    }
    printf("\n");

    return 0;
}