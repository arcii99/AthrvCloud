//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// This program implements a custom cryptographic hash function
// that takes a string input and produces a 128-bit hash digest.

// Define constants
#define BLOCK_SIZE 64
#define HASH_SIZE 16

// Define data types
typedef uint8_t BYTE;
typedef uint32_t WORD;
typedef uint64_t LONGWORD;

// Define global variables
WORD H[4] = {
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476
};
BYTE message[BLOCK_SIZE];
WORD words[16];

// Define functions
void hash(BYTE *input) {
    int i, j;
    LONGWORD bit_len = strlen(input) * 8;
    BYTE padded_message[BLOCK_SIZE];
    BYTE a, b, c, d, f, g, temp;

    // Pad the input message
    memcpy(padded_message, input, strlen(input));
    padded_message[strlen(input)] = 0x80;
    for (i = strlen(input) + 1; i < BLOCK_SIZE; i++) {
        padded_message[i] = 0x00;
    }
    *(LONGWORD *)(padded_message + BLOCK_SIZE - 8) = bit_len;

    // Process each block
    for (i = 0; i < strlen(input) / BLOCK_SIZE + 1; i++) {
        memcpy(message, padded_message + i * BLOCK_SIZE, BLOCK_SIZE);

        // Prepare the message schedule
        for (j = 0; j < 16; j++) {
            words[j] = *(WORD *)(message + j * 4);
        }

        // Initialize the working variables
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];

        // Round 1: F(X,Y,Z) = (X AND Y) OR (NOT X AND Z)
        for (j = 0; j < 16; j++) {
            f = (b & c) | (~b & d);
            g = j;
            temp = d;
            d = c;
            c = b;
            b = b + ((a + f + words[g] + 0x5A827999) << 5);
            a = temp;
        }

        // Round 2: F(X,Y,Z) = X XOR Y XOR Z
        for (j = 16; j < 32; j++) {
            f = b ^ c ^ d;
            g = (5 * j + 1) % 16;
            temp = d;
            d = c;
            c = b;
            b = b + ((a + f + words[g] + 0x6ED9EBA1) << 5);
            a = temp;
        }

        // Round 3: F(X,Y,Z) = (X AND Y) OR (X AND Z) OR (Y AND Z)
        for (j = 32; j < 48; j++) {
            f = (b & c) | (b & d) | (c & d);
            g = (3 * j + 5) % 16;
            temp = d;
            d = c;
            c = b;
            b = b + ((a + f + words[g] + 0x8F1BBCDC) << 5);
            a = temp;
        }

        // Round 4: F(X,Y,Z) = X XOR Y XOR Z
        for (j = 48; j < 64; j++) {
            f = b ^ c ^ d;
            g = (7 * j) % 16;
            temp = d;
            d = c;
            c = b;
            b = b + ((a + f + words[g] + 0xCA62C1D6) << 5);
            a = temp;
        }

        // Update the hash values
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
    }
}

// Test the hash function
int main(void) {
    char *input = "hello, world!";
    hash(input);
    printf("Hash: %08X%08X%08X%08X\n", H[0], H[1], H[2], H[3]);
    return 0;
}