//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTR(x,n) ((x >> n) | (x << (32 - n)))

#define Ch(x,y,z) ((x & y) ^ (~x & z))
#define Maj(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define Sigma0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define Sigma1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define Delta0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3))
#define Delta1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10))

const uint32_t K[] __attribute__((aligned(16))) = {
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

void sha256_hash(const char* data, int len, uint8_t* out) {
    uint32_t h[8] __attribute__((aligned(16))) = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    int new_len = ((((len + 8) / 64) + 1) * 64) - 8;
    uint8_t* padded_data = calloc(new_len + 64, sizeof(*padded_data));
    if (padded_data == NULL) {
        return;
    }
    memcpy(padded_data, data, len);
    padded_data[len] = 0x80;
    *((uint64_t*)(padded_data + new_len)) = len * 8;
    uint32_t* blocks = (uint32_t*)padded_data;
    int num_blocks = (new_len + 64) / 4 / 16;
    for (int i = 0; i < num_blocks; ++i) {
        uint32_t w[64] __attribute__((aligned(16)));
        memcpy(w, blocks + i * 16, sizeof(*blocks) * 16);
        for (int j = 16; j < 64; ++j) {
            w[j] = Delta1(w[j - 2]) + w[j - 7] + Delta0(w[j - 15]) + w[j - 16];
        }
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], k = h[7];
        for (int j = 0; j < 64; ++j) {
            uint32_t t1 = k + Sigma1(e) + Ch(e, f, g) + w[j] + K[j];
            uint32_t t2 = Sigma0(a) + Maj(a, b, c);
            k = g;
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
        h[7] += k;
    }
    for (int i = 0; i < 8; ++i) {
        out[i * 4] = (h[i] >> 24) & 0xff;
        out[i * 4 + 1] = (h[i] >> 16) & 0xff;
        out[i * 4 + 2] = (h[i] >> 8) & 0xff;
        out[i * 4 + 3] = h[i] & 0xff;
    }
    free(padded_data);
}

int main() {
    char* data = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    uint8_t out[32] = {0};
    sha256_hash(data, strlen(data), out);
    printf("Hash: ");
    for (int i = 0; i < 32; ++i) {
        printf("%02x", out[i]);
    }
    printf("\n");
    return 0;
}