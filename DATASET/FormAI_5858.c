//FormAI DATASET v1.0 Category: Cryptographic hash fucntionPassword management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// SHA-256 Constants
#define SHA256_BLOCK_SIZE 32
#define SHA256_DIGEST_SIZE 32

// Data types
typedef uint8_t byte;
typedef uint32_t word;
typedef uint64_t longword;

// SHA-256 working variables
word state[8];
word w[64];

// Constants
const word K[] = {
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

// ROTR and SHR operations
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define SHR(x, n) ((x) >> (n))

// Ch and Maj operations
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

// Sigma functions
#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define sigma0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define sigma1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))

// SHA-256 message processing
void sha256_transform(const byte *msg, byte *digest) {
    // Initialize working variables
    state[0] = 0x6a09e667;
    state[1] = 0xbb67ae85;
    state[2] = 0x3c6ef372;
    state[3] = 0xa54ff53a;
    state[4] = 0x510e527f;
    state[5] = 0x9b05688c;
    state[6] = 0x1f83d9ab;
    state[7] = 0x5be0cd19;

    longword msglen = strlen((char *)msg);
    longword bitlen = msglen * 8;

    // Pre-processing
    byte *padded = malloc(SHA256_BLOCK_SIZE);
    memcpy(padded, msg, msglen);
    padded[msglen] = 0x80;
    memset(padded + msglen + 1, 0, SHA256_BLOCK_SIZE - msglen - 9);
    for (int i = 0; i < 8; i++) {
        padded[SHA256_BLOCK_SIZE - 8 + i] = (bitlen >> (56 - i * 8)) & 0xff;
    }

    // Message processing
    for (int i = 0; i < SHA256_BLOCK_SIZE; i += 4) {
        w[i / 4] = (padded[i] << 24) | (padded[i + 1] << 16) | (padded[i + 2] << 8) | padded[i + 3];
    }

    for (int i = 16; i < 64; i++) {
        w[i] = sigma1(w[i - 2]) + w[i - 7] + sigma0(w[i - 15]) + w[i - 16];
    }

    word a, b, c, d, e, f, g, h, T1, T2;
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    for (int i = 0; i < 64; i++) {
        T1 = h + SIGMA1(e) + CH(e, f, g) + K[i] + w[i];
        T2 = SIGMA0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;

    free(padded);

    // Output hash value
    for (int i = 0; i < SHA256_DIGEST_SIZE; i += 4) {
        digest[i] = (state[i / 4] >> 24) & 0xff;
        digest[i + 1] = (state[i / 4] >> 16) & 0xff;
        digest[i + 2] = (state[i / 4] >> 8) & 0xff;
        digest[i + 3] = state[i / 4] & 0xff;
    }
}

int main() {
    byte msg[] = "hello world";
    byte digest[SHA256_DIGEST_SIZE];
    sha256_transform(msg, digest);

    printf("Message: %s\n", msg);
    printf("Hash: ");
    for (int i = 0; i < SHA256_DIGEST_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}