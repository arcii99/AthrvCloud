//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

/* SHA-256 constants */
static const uint32_t K[64] = {
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

/* SHA-256 functions */
inline static uint32_t ROTR(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

inline static uint32_t ROTL(uint32_t x, uint32_t n) {
    return (x << n) | (x >> (32 - n));
}

inline static uint32_t CH(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

inline static uint32_t MAJ(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

inline static uint32_t EP0(uint32_t x) {
    return ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22);
}

inline static uint32_t EP1(uint32_t x) {
    return ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25);
}

inline static uint32_t SIG0(uint32_t x) {
    return ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3);
}

inline static uint32_t SIG1(uint32_t x) {
    return ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10);
}

/* SHA-256 hash function */
void sha256(const uint8_t *message, size_t len, uint8_t digest[32]) {
    uint32_t H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    /* Padding */
    uint64_t bitlen = len * 8;
    size_t padding_len = (len < 56) ? (56 - len) : (120 - len);
    uint8_t padding[padding_len];
    padding[0] = 0x80;
    for (size_t i = 1; i < padding_len; i++) {
        padding[i] = 0x00;
    }

    /* Length */
    uint8_t length[8];
    for (size_t i = 0; i < 8; i++) {
        length[i] = (bitlen >> (56 - i * 8)) & 0xff;
    }

    /* Process message in blocks of 512 bits */
    size_t blocks = (len + padding_len + 8) / 64;
    uint32_t W[64];
    uint32_t a, b, c, d, e, f, g, h, T1, T2;
    for (size_t i = 0; i < blocks; i++) {
        /* Initialize message schedule */
        for (size_t t = 0; t < 16; t++) {
            W[t] = (message[i * 64 + t * 4 + 0] << 24)
                 | (message[i * 64 + t * 4 + 1] << 16)
                 | (message[i * 64 + t * 4 + 2] << 8)
                 | (message[i * 64 + t * 4 + 3]);
        }
        for (size_t t = 16; t < 64; t++) {
            W[t] = SIG1(W[t-2]) + W[t-7] + SIG0(W[t-15]) + W[t-16];
        }

        /* Initialize working variables */
        a = H[0]; b = H[1]; c = H[2]; d = H[3];
        e = H[4]; f = H[5]; g = H[6]; h = H[7];

        /* Compression function */
        for (size_t t = 0; t < 64; t++) {
            T1 = h + EP1(e) + CH(e, f, g) + K[t] + W[t];
            T2 = EP0(a) + MAJ(a, b, c);
            h = g; g = f; f = e; e = d + T1;
            d = c; c = b; b = a; a = T1 + T2;
        }

        /* Update hash values */
        H[0] += a; H[1] += b; H[2] += c; H[3] += d;
        H[4] += e; H[5] += f; H[6] += g; H[7] += h;
    }

    /* Compute final digest */
    for (size_t i = 0; i < 8; i++) {
        digest[i * 4 + 0] = (H[i] >> 24) & 0xff;
        digest[i * 4 + 1] = (H[i] >> 16) & 0xff;
        digest[i * 4 + 2] = (H[i] >> 8) & 0xff;
        digest[i * 4 + 3] = H[i] & 0xff;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: sha256 <message>\n");
        return EXIT_FAILURE;
    }

    uint8_t message[80];
    size_t message_len = strlen(argv[1]);
    if (message_len > 80) {
        printf("Error: message too long\n");
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < message_len; i++) {
        message[i] = (uint8_t) argv[1][i];
    }

    uint8_t digest[32];
    sha256(message, message_len, digest);

    printf("Message: ");
    for (size_t i = 0; i < message_len; i++) {
        printf("%c", message[i]);
    }
    printf("\n");

    printf("Digest: ");
    for (size_t i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}