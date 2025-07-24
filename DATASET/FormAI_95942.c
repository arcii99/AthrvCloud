//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n)))

void sha256(const uint8_t *message, uint32_t message_len, uint32_t hash[8]) {
    uint32_t k[] = {
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
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t s0, s1, maj, ch;
    uint32_t t1, t2;
    uint32_t i;

    /* Initialize hash values */
    hash[0] = 0x6a09e667;
    hash[1] = 0xbb67ae85;
    hash[2] = 0x3c6ef372;
    hash[3] = 0xa54ff53a;
    hash[4] = 0x510e527f;
    hash[5] = 0x9b05688c;
    hash[6] = 0x1f83d9ab;
    hash[7] = 0x5be0cd19;

    /* Pad message */
    uint8_t *padded_message = NULL;
    uint32_t padded_length = message_len;
    while ((padded_length + 1 + 8) % 64 != 0) {
        padded_length++;
    }
    padded_length += 1 + 8;
    padded_message = calloc(padded_length, 1);
    if (!padded_message) {
        return;
    }
    memcpy(padded_message, message, message_len);
    padded_message[message_len] = 0x80;
    uint64_t bit_length = message_len * 8;
    memcpy(padded_message + padded_length - 8, &bit_length, sizeof(uint64_t));

    /* Process message in 512-bit chunks */
    for (i = 0; i < padded_length; i += 64) {
        /* Prepare message schedule */
        for (int j = 0; j < 16; j++) {
            w[j] = (padded_message[i + j * 4] << 24) |
                   (padded_message[i + j * 4 + 1] << 16) |
                   (padded_message[i + j * 4 + 2] << 8) |
                   (padded_message[i + j * 4 + 3]);
        }
        for (int j = 16; j < 64; j++) {
            s0 = ROTATE_LEFT(w[j - 15], 7) ^ ROTATE_LEFT(w[j - 15], 18) ^ (w[j - 15] >> 3);
            s1 = ROTATE_LEFT(w[j - 2], 17) ^ ROTATE_LEFT(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        /* Initialize working variables */
        a = hash[0];
        b = hash[1];
        c = hash[2];
        d = hash[3];
        e = hash[4];
        f = hash[5];
        g = hash[6];
        h = hash[7];

        /* Compression function */
        for (int j = 0; j < 64; j++) {
            s0 = ROTATE_LEFT(a, 2) ^ ROTATE_LEFT(a, 13) ^ ROTATE_LEFT(a, 22);
            maj = (a & b) ^ (a & c) ^ (b & c);
            t2 = s0 + maj;
            s1 = ROTATE_LEFT(e, 6) ^ ROTATE_LEFT(e, 11) ^ ROTATE_LEFT(e, 25);
            ch = (e & f) ^ ((~e) & g);
            t1 = h + s1 + ch + k[j] + w[j];

            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        /* Update hash values */
        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
        hash[5] += f;
        hash[6] += g;
        hash[7] += h;
    }

    free(padded_message);
}

int main() {
    const char *message = "Hello, world!";
    uint32_t hash[8];

    sha256((uint8_t *)message, strlen(message), hash);

    printf("Hash: ");
    for (int i = 0; i < 8; i++) {
        printf("%08x ", hash[i]);
    }
    printf("\n");

    return 0;
}