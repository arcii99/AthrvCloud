//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Rotates the given 64-bit value to the left by the specified amount of bits
#define ROTL(x, y) ((x << y) | (x >> (64 - y)))

// Performs a round of the given cryptographic hash function using the provided input block
void processBlock(const uint64_t* block, uint64_t* h) {
    // Define some constants for the hash function
    const uint64_t k0 = 0x736f6d6570736575;
    const uint64_t k1 = 0x646f72616e646f6d;
    const uint64_t k2 = 0x6c7967656e657261;
    const uint64_t k3 = 0x7465646279746573;
    const uint64_t k4 = 0x637365642d657261;
    const uint64_t k5 = 0x61657276656c686f;
    const uint64_t k6 = 0x69706f7274656c65;
    const uint64_t k7 = 0x7465646279746573;

    uint64_t a = h[0];
    uint64_t b = h[1];
    uint64_t c = h[2];
    uint64_t d = h[3];
    uint64_t e = h[4];
    uint64_t f = h[5];
    uint64_t g = h[6];
    uint64_t h0 = h[7];

    uint64_t w[80];
    for (int i = 0; i < 16; ++i) {
        w[i] = block[i];
    }

    for (int i = 16; i < 80; ++i) {
        w[i] = ROTL(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
    }

    for (int i = 0; i < 80; ++i) {
        const uint64_t t1 = h0 + ROTL(e, 14) + ((e & f) ^ (~e & g)) + w[i] + k0;
        const uint64_t t2 = ROTL(a, 28) + ((a & b) ^ (a & c) ^ (b & c));
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
}

// Hashes the input data using the given cryptographic hash function
void hash(const uint8_t* data, const size_t size, uint64_t* output) {
    // Define the initial hash values
    const uint64_t h0 = 0x6a09e667f3bcc908;
    const uint64_t h1 = 0xbb67ae8584caa73b;
    const uint64_t h2 = 0x3c6ef372fe94f82b;
    const uint64_t h3 = 0xa54ff53a5f1d36f1;
    const uint64_t h4 = 0x510e527fade682d1;
    const uint64_t h5 = 0x9b05688c2b3e6c1f;
    const uint64_t h6 = 0x1f83d9abfb41bd6b;
    const uint64_t h7 = 0x5be0cd19137e2179;

    uint64_t h[8] = {h0, h1, h2, h3, h4, h5, h6, h7};

    // Split the input data into 64-byte blocks
    const size_t numBlocks = (size + 16) / 64;
    uint64_t block[16];

    for (int i = 0; i < numBlocks; ++i) {
        const uint8_t* blockData = data + (i * 64);

        if (i != numBlocks - 1 || size % 64 == 0) {
            // This block is a full 64-byte block
            memcpy(block, blockData, 64);
        } else {
            // This block is a partial block, so we need to pad it with zeros and add the data size at the end
            const size_t remainder = size % 64;
            memcpy(block, blockData, remainder);
            memset(block + (remainder / 8), 0, 8 - (remainder % 8));
            block[remainder / 8] |= ((uint64_t)size << 3);
        }

        processBlock(block, h);
    }

    memcpy(output, h, 8 * sizeof(uint64_t));
}

int main() {
    // Test data
    const char* testData = "The quick brown fox jumps over the lazy dog";
    const uint8_t* data = (const uint8_t*)testData;
    const size_t size = strlen(testData);
    uint64_t output[8];

    // Hash the test data
    hash(data, size, output);

    // Print out the hash result
    for (int i = 0; i < 8; ++i) {
        printf("%016lx", output[i]);
    }
    printf("\n");

    return 0;
}