//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTR(x,n) (((x)>>(n))|((x)<<(32-(n))))
#define Ch(x,y,z) (((x)&(y))^((~x)&(z)))
#define Maj(x,y,z) (((x)&(y))^((x)&(z))^((y)&(z)))
#define Sigma0(x) (ROTR(x,2)^ROTR(x,13)^ROTR(x,22))
#define Sigma1(x) (ROTR(x,6)^ROTR(x,11)^ROTR(x,25))
#define sigma0(x) (ROTR(x,7)^ROTR(x,18)^((x)>>3))
#define sigma1(x) (ROTR(x,17)^ROTR(x,19)^((x)>>10))

const uint32_t K[64] = {
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

void sha256(const char *msg, uint32_t hash[]) {
    uint32_t a, b, c, d, e, f, g, h, t1, t2, M[64], W[64];
    int i, j;
    size_t len = strlen(msg);

    a = 0x6a09e667;
    b = 0xbb67ae85;
    c = 0x3c6ef372;
    d = 0xa54ff53a;
    e = 0x510e527f;
    f = 0x9b05688c;
    g = 0x1f83d9ab;
    h = 0x5be0cd19;

    len <<= 3;

    memset(M, 0, sizeof(M));
    for (i = 0; i < len/512 + 1; i++) {
        memset(W, 0, sizeof(W));
        for (j = 0; j < 16; j++) {
            if (i*64 + j*4 < len) {
                W[j] = (msg[i*64 + j*4] << 24) | (msg[i*64 + j*4 + 1] << 16) |
                       (msg[i*64 + j*4 + 2] << 8) | msg[i*64 + j*4 + 3];
            }
        }
        for (j = 16; j < 64; j++) {
            W[j] = sigma1(W[j-2]) + W[j-7] + sigma0(W[j-15]) + W[j-16];
        }

        for (j = 0; j < 64; j++) {
            t1 = h + Sigma1(e) + Ch(e, f, g) + K[j] + W[j];
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

        hash[0] = a + hash[0];
        hash[1] = b + hash[1];
        hash[2] = c + hash[2];
        hash[3] = d + hash[3];
        hash[4] = e + hash[4];
        hash[5] = f + hash[5];
        hash[6] = g + hash[6];
        hash[7] = h + hash[7];
    }
}

int main() {
    char msg[] = "Hello, World!";
    uint32_t hash[8] = {0};

    sha256(msg, hash);

    printf("Message: Hello, World!\n");
    printf("Hash: %08x%08x%08x%08x%08x%08x%08x%08x\n",
            hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);

    return 0;
}