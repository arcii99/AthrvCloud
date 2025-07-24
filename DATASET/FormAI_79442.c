//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

uint32_t F1(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

uint32_t F2(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | ((~x) & z);
}

uint32_t F3(uint32_t x, uint32_t y, uint32_t z) {
    return (x | (~y)) ^ z;
}

uint32_t F4(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & (~z));
}

typedef uint32_t (*hashFuncPtr_t)(uint32_t, uint32_t, uint32_t);

void transform(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d, uint32_t *e, uint32_t *f, uint32_t *g, uint32_t *h, hashFuncPtr_t hashFunc, uint32_t msg) {
    uint32_t t1 = *h + hashFunc(*e, *f, *g) + ROTL(*e, 5) + msg;
    uint32_t t2 = *d;
    *h = *g;
    *g = *f;
    *f = *e;
    *e = *d + t1;
    *d = *c;
    *c = *b;
    *b = *a;
    *a = t1 + t2;
}

void sha256(const unsigned char *msg, size_t len, uint32_t *hash) {
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t ah, bh, ch, dh, eh, fh, gh, hh;
    uint32_t *temp;
    int i;

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

    const unsigned int wLen = 16;
    const unsigned int tempLen = 64;

    // initialize the hash values
    ah = 0x6a09e667;
    bh = 0xbb67ae85;
    ch = 0x3c6ef372;
    dh = 0xa54ff53a;
    eh = 0x510e527f;
    fh = 0x9b05688c;
    gh = 0x1f83d9ab;
    hh = 0x5be0cd19;

    for (i = 0; i < len / 64; i++) {
        // break message into 512-bit chunks
        const unsigned char *subMsg = msg + (i * 64);

        // initialize the round constants
        uint32_t *temp = w;
        int j;
        for (j = 0; j < wLen; j++) {
            *temp++ = (subMsg[4*j] << 24) | (subMsg[4*j + 1] << 16) | (subMsg[4*j + 2] << 8) | subMsg[4*j + 3];
        }

        for (j = wLen; j < tempLen; j++) {
            uint32_t s0 = ROTL(w[j - 15], 7) ^ ROTL(w[j - 15], 18) ^ (w[j - 15] >> 3);
            uint32_t s1 = ROTL(w[j - 2], 17) ^ ROTL(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        // initialize working variables
        a = ah;
        b = bh;
        c = ch;
        d = dh;
        e = eh;
        f = fh;
        g = gh;
        h = hh;

        // iterate over the 64 rounds
        for (j = 0; j < tempLen; j++) {
            uint32_t s1 = ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = h + s1 + ch + K[j] + w[j];
            uint32_t s0 = ROTL(a, 2) ^ ROTL(a, 13) ^ ROTL(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = s0 + maj;

            transform(&a, &b, &c, &d, &e, &f, &g, &h, (j % 4 == 0) ? F1 : (j % 4 == 1) ? F2 : (j % 4 == 2) ? F3 : F4, temp1);
            transform(&a, &b, &c, &d, &e, &f, &g, &h, (j % 4 == 0) ? F4 : (j % 4 == 1) ? F3 : (j % 4 == 2) ? F2 : F1, temp2);
        }

        ah += a;
        bh += b;
        ch += c;
        dh += d;
        eh += e;
        fh += f;
        gh += g;
        hh += h;
    }

    hash[0] = ah;
    hash[1] = bh;
    hash[2] = ch;
    hash[3] = dh;
    hash[4] = eh;
    hash[5] = fh;
    hash[6] = gh;
    hash[7] = hh;
}

int main() {
    const unsigned char msg[] = "The quick brown fox jumps over the lazy dog";
    uint32_t hash[8];

    sha256(msg, strlen(msg), hash);

    printf("Hash: 0x%08x%08x%08x%08x%08x%08x%08x%08x\n",
           hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);

    return 0;
}