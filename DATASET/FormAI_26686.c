//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: minimalist
#include <stdio.h>
#include <stdint.h>

#define ROTL(x, n) ((x) << (n)) | ((x) >> (32-(n)))
#define ROTR(x, n) ((x) >> (n)) | ((x) << (32-(n)))
#define CH(x, y, z) ((x) & (y)) ^ (~(x) & (z))
#define MAJ(x, y, z) ((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z))

uint32_t K[64] = {
    0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
    0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
    0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
    0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
    0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
    0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
    0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
    0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
    0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
    0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
    0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
    0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
    0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
    0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
    0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
    0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

uint32_t H[8] = {
    0x6A09E667,
    0xBB67AE85,
    0x3C6EF372,
    0xA54FF53A,
    0x510E527F,
    0x9B05688C,
    0x1F83D9AB,
    0x5BE0CD19
};

uint32_t SHA256(uint8_t *msg, uint32_t len) {
    uint32_t W[64], a, b, c, d, e, f, g, h, i, j, T1, T2;

    for (i = 0; i < 16; i++) {
        W[i] = (msg[i*4] << 24) | (msg[i*4+1] << 16) | (msg[i*4+2] << 8) | (msg[i*4+3]);
    }

    for (i = 16; i < 64; i++) {
        W[i] = ROTR(W[i-2], 17) ^ ROTR(W[i-2], 19) ^ (W[i-2] >> 10);
        W[i] += W[i-7];
        W[i] += ROTR(W[i-15], 7) ^ ROTR(W[i-15],18) ^ (W[i-15] >> 3);
        W[i] += W[i-16];
    }

    a = H[0]; b = H[1]; c = H[2]; d = H[3]; e = H[4]; f = H[5]; g = H[6]; h = H[7];

    for (i = 0; i < 64; i++) {
        T1 = h + CH(e, f, g) + ROTR(e, 6) + W[i] + K[i];
        T2 = MAJ(a, b, c) + ROTR(a, 2);
        h = g; g = f; f = e; e = d + T1;
        d = c; c = b; b = a; a = T1 + T2;
    }

    H[0] += a; H[1] += b; H[2] += c; H[3] += d;
    H[4] += e; H[5] += f; H[6] += g; H[7] += h;

    return H[0];
}

int main(int argc, char const *argv[]) {
    uint8_t msg[64] = "Hash this message with SHA-256!";

    printf("%08x\n", SHA256(msg, 29));

    return 0;
}