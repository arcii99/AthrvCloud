//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE; // Define BYTE as an unsigned char data type

// Define ROTATE_LEFT shift macro for 32-bit values
#define ROTATE_LEFT(num, n) (((num) << (n)) | ((num) >> (32 - (n))))

// Define F, G and H functions for SHA-256 algorithm
#define F(x, y, z) ((x & y) ^ (~x & z))
#define G(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define H(x, y, z) (x ^ y ^ z)

// Define Sigma MACROS for SHA-256 Algorithm
#define SIGMA0(x) (ROTATE_LEFT(x, 2) ^ ROTATE_LEFT(x, 13) ^ ROTATE_LEFT(x, 22))
#define SIGMA1(x) (ROTATE_LEFT(x, 6) ^ ROTATE_LEFT(x, 11) ^ ROTATE_LEFT(x, 25))
#define sigma0(x) (ROTATE_LEFT(x, 7) ^ ROTATE_LEFT(x, 18) ^ ((x) >> 3))
#define sigma1(x) (ROTATE_LEFT(x, 17) ^ ROTATE_LEFT(x, 19) ^ ((x) >> 10))

// Define SHA-256 constants
const BYTE SHA256_CONSTANTS[64] = {
    0x42, 0x8F, 0xCA, 0x9B, 0x7C, 0x3B, 0xC1, 0xB5, 0x51, 0x1F, 0x56, 0x58, 0x04, 0x9A, 0xFB, 0xDC,
    0x5A, 0x82, 0x79, 0x6F, 0x7F, 0x3E, 0x3B, 0xF1, 0xCF, 0xE5, 0x00, 0x7C, 0x9D, 0x65, 0x0F, 0x71,
    0x6D, 0x76, 0x89, 0x56, 0x1F, 0x35, 0x70, 0x00, 0x3A, 0x40, 0x62, 0x6A, 0x36, 0x00, 0xE3, 0x4E,
    0xA7, 0x6F, 0xA8, 0x7E, 0x51, 0x52, 0x39, 0x1A, 0x85, 0x0D, 0xB0, 0xED, 0x45, 0xBE, 0x68, 0x8C
};

// Define initial hash values for SHA-256
const BYTE SHA256_INITIAL_HASH_VALUES[8] = {
    0x6A, 0x09, 0xE6, 0x67, 0xBB, 0x67, 0xAE, 0x85
};

// Define hash buffer
BYTE SHA256_HASH_BUFFER[32] = { 0 };

// Define message schedule array for SHA-256
BYTE SHA256_MESSAGE_SCHEDULE[64] = { 0 };

// Define padding
BYTE SHA256_PADDING[64] = { 0x80 };

// Define length of message
unsigned long long SHA256_MESSAGE_LENGTH = 0;

// Implement SHA-256 hash function
void SHA256(BYTE* message, unsigned long long message_length) {
    // Initialize variables
    unsigned int a, b, c, d, e, f, g, h, i, j, t1, t2;
    BYTE chunk[64];
    unsigned int message_blocks = message_length / 64;

    // Set initial hash values
    a = SHA256_INITIAL_HASH_VALUES[0];
    b = SHA256_INITIAL_HASH_VALUES[1];
    c = SHA256_INITIAL_HASH_VALUES[2];
    d = SHA256_INITIAL_HASH_VALUES[3];
    e = SHA256_INITIAL_HASH_VALUES[4];
    f = SHA256_INITIAL_HASH_VALUES[5];
    g = SHA256_INITIAL_HASH_VALUES[6];
    h = SHA256_INITIAL_HASH_VALUES[7];

    // Process each 512-bit message block
    for (i = 0; i < message_blocks; i++) {
        // Copy message block into chunk
        memcpy(chunk, message + i * 64, 64);

        // Prepare message schedule
        for (j = 0; j < 16; j++) {
            SHA256_MESSAGE_SCHEDULE[j] = chunk[j * 4] << 24 | chunk[j * 4 + 1] << 16 | chunk[j * 4 + 2] << 8 | chunk[j * 4 + 3];
        }

        for(j = 16; j < 64; j++) {
            SHA256_MESSAGE_SCHEDULE[j] = sigma1(SHA256_MESSAGE_SCHEDULE[j - 2]) + SHA256_MESSAGE_SCHEDULE[j - 7] + sigma0(SHA256_MESSAGE_SCHEDULE[j - 15]) + SHA256_MESSAGE_SCHEDULE[j - 16];
        }

        // Perform main hash computation for current message block
        for (j = 0; j < 64; j++) {
            t1 = h + SIGMA1(e) + F(e, f, g) + SHA256_CONSTANTS[j] + SHA256_MESSAGE_SCHEDULE[j];
            t2 = SIGMA0(a) + H(a, b, c);

            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Update hash values after processing each message block
        SHA256_HASH_BUFFER[0] = a + SHA256_HASH_BUFFER[0];
        SHA256_HASH_BUFFER[1] = b + SHA256_HASH_BUFFER[1];
        SHA256_HASH_BUFFER[2] = c + SHA256_HASH_BUFFER[2];
        SHA256_HASH_BUFFER[3] = d + SHA256_HASH_BUFFER[3];
        SHA256_HASH_BUFFER[4] = e + SHA256_HASH_BUFFER[4];
        SHA256_HASH_BUFFER[5] = f + SHA256_HASH_BUFFER[5];
        SHA256_HASH_BUFFER[6] = g + SHA256_HASH_BUFFER[6];
        SHA256_HASH_BUFFER[7] = h + SHA256_HASH_BUFFER[7];
    }

    // Clear message schedule
    memset(SHA256_MESSAGE_SCHEDULE, 0, 64);

    // Clear padding
    memset(SHA256_PADDING, 0, 64);

    // Clear message length
    SHA256_MESSAGE_LENGTH = 0;
}

int main() {
    char message[] = "Hello, world! This is a test message for SHA-256 hash function.";
    unsigned long long message_length = strlen(message);

    // Process message
    SHA256((BYTE*)message, message_length);

    // Output hash value
    printf("Hash value: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", SHA256_HASH_BUFFER[i]);
    }
    printf("\n");

    return 0;
}