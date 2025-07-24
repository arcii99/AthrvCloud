//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: accurate
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define SHR(x, n) ((x) >> (n))

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

void sha256_transform(const unsigned char *message, uint32_t *h) {
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h2, i, j, t1, t2;

    for (i = 0, j = 0; i < 16; ++i, j += 4)
        w[i] = (message[j] << 24) | (message[j + 1] << 16) | (message[j + 2] << 8) | (message[j + 3]);
    for (; i < 64; ++i)
        w[i] = w[i - 16] + ROTR(w[i - 15], 7) + w[i - 7] + ROTR(w[i - 2], 17);

    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];
    f = h[5];
    g = h[6];
    h2 = h[7];

    for (i = 0; i < 64; ++i) {
        t1 = h2 + SHR(e, 6) ^ SHR(e, 11) ^ SHR(e, 25);
        t2 = (e & f) ^ ((~e) & g);
        t1 += t2 + k[i] + w[i];
        t2 = SHR(a, 2) ^ SHR(a, 13) ^ SHR(a, 22);
        t2 += (a & b) ^ (a & c) ^ (b & c);
        h2 = g;
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
    h[7] += h2;
}

void sha256(const unsigned char *message, size_t len, unsigned char *digest) {
    uint32_t i, j;
    uint64_t bitlen = len * 8;
    unsigned char data[128];

    h[0] = 0x6a09e667;
    h[1] = 0xbb67ae85;
    h[2] = 0x3c6ef372;
    h[3] = 0xa54ff53a;
    h[4] = 0x510e527f;
    h[5] = 0x9b05688c;
    h[6] = 0x1f83d9ab;
    h[7] = 0x5be0cd19;

    memset(data, 0, sizeof(data));
    memcpy(data, message, len);

    data[len] = 0x80;

    if (len % 64 < 56) {
        for (i = len + 1; i < 128 - 8; ++i)
            data[i] = 0;
    } else {
        for (i = len + 1; i < 64; ++i)
            data[i] = 0;
        for (; i < 128 - 8; ++i)
            data[i] = 0;
    }

    data[120] = (bitlen >> 56) & 0xff;
    data[121] = (bitlen >> 48) & 0xff;
    data[122] = (bitlen >> 40) & 0xff;
    data[123] = (bitlen >> 32) & 0xff;
    data[124] = (bitlen >> 24) & 0xff;
    data[125] = (bitlen >> 16) & 0xff;
    data[126] = (bitlen >> 8) & 0xff;
    data[127] = bitlen & 0xff;

    for (i = 0; i < 128; i += 64)
        sha256_transform(data + i, h);

    for (i = 0, j = 0; i < 8; ++i, j += 4) {
        digest[j] = (h[i] >> 24) & 0xff;
        digest[j + 1] = (h[i] >> 16) & 0xff;
        digest[j + 2] = (h[i] >> 8) & 0xff;
        digest[j + 3] = h[i] & 0xff;
    }
}

int main() {
    unsigned char message[] = "Hello, world!";
    unsigned char digest[32];

    sha256(message, strlen(message), digest);

    printf("Hash value: ");
    for (int i = 0; i < 32; ++i)
        printf("%02x", digest[i]);
    printf("\n");

    return 0;
}