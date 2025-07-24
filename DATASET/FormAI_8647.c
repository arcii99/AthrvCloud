//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*
 * A simple recursive implementation of SHA256 cryptographic
 * hash function in C language.
 * Written by [Your Name] on [Date]
 */

#define ROTRIGHT(word,bits) (((word) >> (bits)) | ((word) << (32-(bits))))
#define ROTLEFT(word,bits) (((word) << (bits)) | ((word) >> (32-(bits))))
#define SHR(word,bits) ((word) >> bits)

unsigned int k[64] = {
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

void sha256(char *message, unsigned int message_length, unsigned int hash[8]) {

    // Initialize working variables
    unsigned int a, b, c, d, e, f, g, h, i, j, t1, t2, m[64], w[64];

    // Initialize hash values
    hash[0] = 0x6a09e667;
    hash[1] = 0xbb67ae85;
    hash[2] = 0x3c6ef372;
    hash[3] = 0xa54ff53a;
    hash[4] = 0x510e527f;
    hash[5] = 0x9b05688c;
    hash[6] = 0x1f83d9ab;
    hash[7] = 0x5be0cd19;

    // Pre-processing
    unsigned int padding = 0;
    if (message_length % 64 < 56) {
        padding = 64 - (message_length % 64);
    } else {
        padding = 128 - (message_length % 64);
    }
    char new_message[message_length + padding + 8];
    memcpy(new_message, message, message_length);
    new_message[message_length] = 0x80;
    unsigned int k_bits = 8 * message_length;
    memcpy(new_message + message_length + padding, &k_bits, 4);

    // Process message in 512-bit chunks
    unsigned int num_chunks = (message_length + padding + 8) / 64;
    for (i = 0; i < num_chunks; i++) {

        // Prepare message schedule
        memcpy(m, new_message + i * 64, 64);
        for (j = 0; j < 16; j++) {
            w[j] = (m[j] << 24) | ((m[j] << 8) & 0xff0000) | ((m[j] >> 8) & 0xff00) | ((m[j] >> 24) & 0xff);
        }
        for (j = 16; j < 64; j++) {
            w[j] = w[j-16] + w[j-7] + (ROTRIGHT(w[j-15], 7) ^ ROTRIGHT(w[j-15], 18) ^ SHR(w[j-15], 3)) + (ROTRIGHT(w[j-2], 17) ^ ROTRIGHT(w[j-2], 19) ^ SHR(w[j-2], 10));
        }

        // Initialize working variables
        a = hash[0];
        b = hash[1];
        c = hash[2];
        d = hash[3];
        e = hash[4];
        f = hash[5];
        g = hash[6];
        h = hash[7];

        // Compression function
        for (j = 0; j < 64; j++) {
            t1 = h + (ROTRIGHT(e, 6) ^ ROTRIGHT(e, 11) ^ ROTRIGHT(e, 25)) + ((e & f) ^ ((~e) & g)) + k[j] + w[j];
            t2 = (ROTRIGHT(a, 2) ^ ROTRIGHT(a, 13) ^ ROTRIGHT(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Update hash values
        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
        hash[5] += f;
        hash[6] += g;
        hash[7] += h;

    }

}

int main() {

    char message[] = "The quick brown fox jumps over the lazy dog";
    unsigned int message_length = strlen(message);
    unsigned int hash[8];
    sha256(message, message_length, hash);
    printf("SHA256 hash of \"%s\" is:\n", message);
    printf("%08x%08x%08x%08x%08x%08x%08x%08x\n", hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);

    return 0;

}