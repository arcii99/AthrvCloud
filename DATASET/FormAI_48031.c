//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,y) ((x << y) | (x >> (32 - y)))

// Converts a 32-bit full word into 4 separate bytes.
#define B2B(b,x) { (x)[0] = (b) & 0xff; (x)[1] = ((b) >> 8) & 0xff; (x)[2] = ((b) >> 16) & 0xff; (x)[3] = ((b) >> 24) & 0xff; }

// Converts 4 separate bytes into a 32-bit full word.
#define B2U32(x) ((x)[0] | ((x)[1] << 8) | ((x)[2] << 16) | ((x)[3] << 24))

// Hash function main variables
uint32_t state[8];
uint8_t buffer[64];
uint32_t count[2];
uint8_t digest[32];

// Hash function helper functions
void md5_transform(uint32_t *state, const uint8_t *block);
void md5_update(const uint8_t *input, uint32_t len);
void md5_final();

// Main program logic
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    // Set initial hash values
    state[0] = 0x67452301;
    state[1] = 0xEFCDAB89;
    state[2] = 0x98BADCFE;
    state[3] = 0x10325476;
    state[4] = 0xC3D2E1F0;
    state[5] = 0x76543210;
    state[6] = 0xFEDCBA98;
    state[7] = 0x89ABCDEF;
    
    // Compute hash
    md5_update((const uint8_t *)argv[1], strlen(argv[1]));
    md5_final();
    
    // Print hash
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    
    return 0;
}

// Constants for MD5 algorithm
const uint32_t K[] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

const uint32_t S[] = {
    7, 12, 17, 22,
    7, 12, 17, 22,
    7, 12, 17, 22,
    7, 12, 17, 22,
    5,  9, 14, 20,
    5,  9, 14, 20,
    5,  9, 14, 20,
    5,  9, 14, 20,
    4, 11, 16, 23,
    4, 11, 16, 23,
    4, 11, 16, 23,
    4, 11, 16, 23,
    6, 10, 15, 21,
    6, 10, 15, 21,
    6, 10, 15, 21,
    6, 10, 15, 21
};

// Main MD5 transformation function
void md5_transform(uint32_t *state, const uint8_t *block) {
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t f = state[5];
    uint32_t g = state[6];
    uint32_t h = state[7];
    uint32_t x[16];
    
    // Convert block to 32-bit numbers
    for (int i = 0; i < 16; i++) {
        x[i] = B2U32(&block[i * 4]);
    }
    
    // MD5 round 1
    for (int i = 0; i < 16; i++) {
        uint32_t t = ROTL(a + ((b & c) | (~b & d)) + x[i] + K[i], S[i]);
        a = d;
        d = c;
        c = b;
        b += t;
    }
    
    // MD5 round 2
    for (int i = 0; i < 16; i++) {
        int j = (5 * i + 1) % 16;
        uint32_t t = ROTL(a + ((b & d) | (c & ~d)) + x[j] + K[i + 16], S[i + 16]);
        a = d;
        d = c;
        c = b;
        b += t;
    }
    
    // MD5 round 3
    for (int i = 0; i < 16; i++) {
        int j = (3 * i + 5) % 16;
        uint32_t t = ROTL(a + (b ^ c ^ d) + x[j] + K[i + 32], S[i + 32]);
        a = d;
        d = c;
        c = b;
        b += t;
    }
    
    // MD5 round 4
    for (int i = 0; i < 16; i++) {
        int j = 7 * i % 16;
        uint32_t t = ROTL(a + (c ^ (b | ~d)) + x[j] + K[i + 48], S[i + 48]);
        a = d;
        d = c;
        c = b;
        b += t;
    }
    
    // Update state variables
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

// Helper function to update the hash buffer
void md5_update(const uint8_t *input, uint32_t len) {
    uint32_t i, block_idx;
    uint32_t buffer_idx = (count[0] >> 3) & 0x3F;
    count[0] += (len << 3);
    if (count[0] < (len << 3)) count[1]++;
    count[1] += (len >> 29);
    for (i = 0; i < len; i++) {
        buffer[buffer_idx++] = input[i];
        if (buffer_idx == 64) {
            md5_transform(state, buffer);
            buffer_idx = 0;
        }
    }
}

// Helper function to finalize hash
void md5_final() {
    uint8_t bits[8];
    uint32_t padding_idx;
    
    // Save length in bits
    B2B(count[0], &bits[0]);
    B2B(count[1], &bits[4]);
    
    // Compute padding
    padding_idx = (count[0] >> 3) & 0x3F;
    buffer[padding_idx++] = 0x80;
    if (padding_idx < 56) {
        memset(&buffer[padding_idx], 0x00, 56 - padding_idx);
    } else {
        memset(&buffer[padding_idx], 0x00, 64 - padding_idx);
        md5_transform(state, buffer);
        memset(buffer, 0x00, 56);
    }
    
    // Append length in bits
    memcpy(&buffer[56], bits, 8);
    md5_transform(state, buffer);
    
    // Convert state to output buffer
    for (int i = 0; i < 4; i++) {
        B2B(state[i], &digest[i * 4]);
    }
}