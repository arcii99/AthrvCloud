//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scalable
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * The hash function takes a message of arbitrary length and returns a fixed-size
 * cryptographic hash value.
 * 
 * The input message is first padded to a multiple of 64 bytes, where each 64-byte
 * block is processed sequentially using the SHA-256 algorithm.
 * 
 * The SHA-256 algorithm uses a series of bitwise operations to transform each block
 * of 64 bytes into a 32-byte hash value, resulting in a fixed-size 256-bit output.
 * 
 * The final output hash value is returned as a hexadecimal string.
 */

#define ROTRIGHT(word, shift) ((word >> shift) | (word << (32 - shift)))

// SHA-256 constants
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

// SHA-256 initial hash value
const uint32_t H[] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// helper function to read a block of 512 bits (64 bytes) from input
void read_block(FILE *file, uint32_t *M) {
    uint8_t bytes[64];
    if (fread(bytes, 1, 64, file)) {
        for (int i = 0, j = 0; i < 64; i += 4, j++) {
            M[j]  = (uint32_t) bytes[i] << 24;
            M[j] |= (uint32_t) bytes[i+1] << 16;
            M[j] |= (uint32_t) bytes[i+2] << 8;
            M[j] |= (uint32_t) bytes[i+3];
        }
    }
}

// SHA-256 message schedule
void compute_message_schedule(uint32_t *W) {
    for (int i = 16; i < 64; i++) {
        uint32_t s0 = ROTRIGHT(W[i-15], 7) ^ ROTRIGHT(W[i-15], 18) ^ (W[i-15] >> 3);
        uint32_t s1 = ROTRIGHT(W[i-2], 17) ^ ROTRIGHT(W[i-2], 19) ^ (W[i-2] >> 10);
        W[i] = W[i-16] + s0 + W[i-7] + s1;
    }
}

// SHA-256 compression function
void compute_hash(uint32_t *M, uint32_t *H) {
    uint32_t a, b, c, d, e, f, g, h, T1, T2, W[64];
    memcpy(W, M, 16*sizeof(uint32_t));
    compute_message_schedule(W);

    a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5], g = H[6], h = H[7];

    for (int i = 0; i < 64; i++) {
        T1 = h + (ROTRIGHT(e, 6) ^ ROTRIGHT(e, 11) ^ ROTRIGHT(e, 25)) + ((e & f) ^ (~e & g)) + K[i] + W[i];
        T2 = (ROTRIGHT(a, 2) ^ ROTRIGHT(a, 13) ^ ROTRIGHT(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    H[0] += a, H[1] += b, H[2] += c, H[3] += d, H[4] += e, H[5] += f, H[6] += g, H[7] += h;
}

// main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return EXIT_FAILURE;
    }

    uint32_t M[16], H[8];
    memcpy(H, K, 8*sizeof(uint32_t));

    while (!feof(file)) {
        read_block(file, M);
        compute_hash(M, H);
    }

    fclose(file);

    char hash_string[65];
    sprintf(hash_string, "%08x%08x%08x%08x%08x%08x%08x%08x", H[0], H[1], H[2], H[3], H[4], H[5], H[6], H[7]);
    printf("%s  %s\n", hash_string, filename);

    return EXIT_SUCCESS;
}