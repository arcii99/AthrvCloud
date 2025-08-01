//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) ((x << n) | (x >> (32 - n)))
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))
#define BIG_ENDIAN 0

// Ch function for SHA-256 algorithm
#define CH(x, y, z) ((x & y) ^ (~x & z))

// Maj function for SHA-256 algorithm
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

// Sigma 0 function for SHA-256 algorithm
#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))

// Sigma 1 function for SHA-256 algorithm
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))

// delta value for SHA-256 algorithm
#define DELTA 0x9B05688C

// SHA-256 Algorithm function
void sha256(uint8_t *msg, uint32_t len, uint8_t *hash) {

    uint32_t h[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    uint32_t k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    uint32_t *w, a, b, c, d, e, f, g, h0, t1, t2;
    uint32_t i, j, nl, nw;

    nl = len + 1 + 8;
    nw = nl / 4;
    w = calloc(nw, 4);

    memcpy(w, msg, len);
    w[(nl / 4) - 1] = ((uint32_t)len) * 8;

    for (i = 0; i < nw; ++i) {
        if (BIG_ENDIAN) {
            w[i] = (ROTL(w[i], 24) & 0xff00ff00) | (ROTL(w[i], 8) & 0x00ff00ff);
            w[i] = ROTL(w[i], 16);
        }
    }

    for (i = 16; i < 64; ++i) {
        w[i] = SIGMA1(w[i - 2]) + w[i - 7] + SIGMA0(w[i - 15]) + w[i - 16];
    }

    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];
    f = h[5];
    g = h[6];
    h0 = h[7];

    for (i = 0; i < 64; ++i) {
        t1 = h0 + SIGMA1(e) + CH(e, f, g) + k[i] + w[i];
        t2 = SIGMA0(a) + MAJ(a, b, c);
        h0 = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
    h[5] += f;
    h[6] += g;
    h[7] += h0;

    free(w);

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 4; ++j) {
            hash[i * 4 + j] = (h[i] >> ((3 - j) * 8)) & 0xff;
        }
    }

}

// Main driver function
int main() {

    uint8_t *msg = "Hello, world!";
    uint8_t hash[32];
    uint32_t i;

    sha256(msg, strlen((char *)msg), hash);

    printf("Message: %s\n", msg);
    printf("Hash: ");
    for (i = 0; i < 32; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}