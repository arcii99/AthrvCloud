//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: satisfied
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x, y) ((x >> y) | (x << (32 - y)))
#define Ch(x, y, z) ((x & y) ^ (~x & z))
#define Maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define Sigma0(x) (ROTR32(x, 2) ^ ROTR32(x, 13) ^ ROTR32(x, 22))
#define Sigma1(x) (ROTR32(x, 6) ^ ROTR32(x, 11) ^ ROTR32(x, 25))
#define sigma0(x) (ROTR32(x, 7) ^ ROTR32(x, 18) ^ (x >> 3))
#define sigma1(x) (ROTR32(x, 17) ^ ROTR32(x, 19) ^ (x >> 10))

/* Constants used to generate the hash */
static const uint32_t constants[] = {
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

/* Function to perform SHA-256 hash computation */
void sha256(const char *msg, size_t len, uint32_t hash[]) {
    uint32_t w[64], a, b, c, d, e, f, g, h, t1, t2;
    uint32_t H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    for (size_t i = 0; i < len; i += 64) {
        /* Copy message block into w */
        for (size_t j = 0; j < 16; j++) {
            w[j] = (uint32_t)msg[i + j * 4] << 24;
            w[j] |= (uint32_t)msg[i + j * 4 + 1] << 16;
            w[j] |= (uint32_t)msg[i + j * 4 + 2] << 8;
            w[j] |= (uint32_t)msg[i + j * 4 + 3];
        }

        /* Extend the first 16 words into the remaining 48 words w[16..63] */
        for (size_t j = 16; j < 64; j++)
            w[j] = sigma1(w[j - 2]) + w[j - 7] + sigma0(w[j - 15]) + w[j - 16];

        /* Initialize working variables to the current hash value */
        a = H[0], b = H[1], c = H[2], d = H[3];
        e = H[4], f = H[5], g = H[6], h = H[7];

        /* Compression function main loop */
        for (size_t j = 0; j < 64; j++) {
            t1 = h + Sigma1(e) + Ch(e, f, g) + constants[j] + w[j];
            t2 = Sigma0(a) + Maj(a, b, c);
            h = g, g = f, f = e, e = d + t1, d = c, c = b, b = a, a = t1 + t2;
        }

        /* Add the compressed chunk to the current hash value */
        H[0] += a, H[1] += b, H[2] += c, H[3] += d;
        H[4] += e, H[5] += f, H[6] += g, H[7] += h;
    }

    memcpy(hash, H, 8 * sizeof(uint32_t));
}

int main(void) {
    char *msg = "Hello, World!";
    uint32_t hash[8];

    sha256(msg, strlen(msg), hash);

    printf("Hash: ");
    for (size_t i = 0; i < 8; i++)
        printf("%08x", hash[i]);
    putchar('\n');

    return 0;
}