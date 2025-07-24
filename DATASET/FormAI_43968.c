//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: introspective
#include <stdio.h>
#include <stdint.h>

typedef struct HashState_t {
    uint32_t state[8]; // State of the hash
    unsigned char buffer[64]; // Buffer to hold input
    unsigned char bufferIndex;
    uint64_t messageSize; // Number of bytes hashed
} HashState;

// Rotate left function
static inline uint32_t rol(uint32_t num, uint32_t count) {
    return (num << count) | (num >> (32 - count));
}

// Round function for the hash algorithm
static inline void sha256Round(HashState* state, uint32_t* chunk) {
    uint32_t a = state->state[0];
    uint32_t b = state->state[1];
    uint32_t c = state->state[2];
    uint32_t d = state->state[3];
    uint32_t e = state->state[4];
    uint32_t f = state->state[5];
    uint32_t g = state->state[6];
    uint32_t h = state->state[7];

    // Perform sha256 operations
    for (int i = 0; i < 64; i++) {
        uint32_t t1 = h + (rol(e, 6) ^ rol(e, 11) ^ rol(e, 25)) + ((e & f) ^ (~e & g)) + chunk[i] + i;
        uint32_t t2 = (rol(a, 2) ^ rol(a, 13) ^ rol(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Update the hash state
    state->state[0] += a;
    state->state[1] += b;
    state->state[2] += c;
    state->state[3] += d;
    state->state[4] += e;
    state->state[5] += f;
    state->state[6] += g;
    state->state[7] += h;
}

// Initialize the hash buffer
void sha256Init(HashState* state) {
    state->state[0] = 0x6a09e667;
    state->state[1] = 0xbb67ae85;
    state->state[2] = 0x3c6ef372;
    state->state[3] = 0xa54ff53a;
    state->state[4] = 0x510e527f;
    state->state[5] = 0x9b05688c;
    state->state[6] = 0x1f83d9ab;
    state->state[7] = 0x5be0cd19;

    state->bufferIndex = 0;
    state->messageSize = 0;
}

// Add a chunk of data to the hash
void sha256Update(HashState* state, const void* data, size_t size) {
    const unsigned char* input = (const unsigned char*)data;

    while (size--) {
        state->buffer[state->bufferIndex++] = *input++;
        state->messageSize++;

        if (state->bufferIndex == 64) {
            uint32_t chunk[16];

            // Convert the input into 32-bit integers
            for (int i = 0; i < 16; i++) {
                uint32_t b0 = state->buffer[i * 4 + 0];
                uint32_t b1 = state->buffer[i * 4 + 1];
                uint32_t b2 = state->buffer[i * 4 + 2];
                uint32_t b3 = state->buffer[i * 4 + 3];

                chunk[i] = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
            }

            sha256Round(state, chunk);
            state->bufferIndex = 0;
        }
    }
}

// Finalize the hash and output the result
void sha256Finalize(HashState* state, uint32_t hash[8]) {
    // Pad the message with a single bit followed by zeros
    state->buffer[state->bufferIndex++] = 0x80;
    while (state->bufferIndex != 56) {
        if (state->bufferIndex == 64) {
            uint32_t chunk[16];

            // Convert the input into 32-bit integers
            for (int i = 0; i < 16; i++) {
                uint32_t b0 = state->buffer[i * 4 + 0];
                uint32_t b1 = state->buffer[i * 4 + 1];
                uint32_t b2 = state->buffer[i * 4 + 2];
                uint32_t b3 = state->buffer[i * 4 + 3];

                chunk[i] = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
            }

            sha256Round(state, chunk);
            state->bufferIndex = 0;
        }

        state->buffer[state->bufferIndex++] = 0x00;
    }

    // Append the message size in bits
    uint64_t messageSizeBits = state->messageSize * 8;
    for (int i = 56; i < 64; i++) {
        state->buffer[state->bufferIndex++] = (messageSizeBits >> ((63 - i) * 8)) & 0xff;
    }

    // Process the final chunk
    uint32_t chunk[16];
    for (int i = 0; i < 16; i++) {
        uint32_t b0 = state->buffer[i * 4 + 0];
        uint32_t b1 = state->buffer[i * 4 + 1];
        uint32_t b2 = state->buffer[i * 4 + 2];
        uint32_t b3 = state->buffer[i * 4 + 3];

        chunk[i] = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
    }

    sha256Round(state, chunk);

    // Output the final hash
    for (int i = 0; i < 8; i++) {
        hash[i] = state->state[i];
    }
}

int main()
{
    // Test case
    HashState state;
    sha256Init(&state);
    sha256Update(&state, "Hello, world!", 13);
    uint32_t hash[8];
    sha256Finalize(&state, hash);

    printf("Hash: ");
    for (int i = 0; i < 8; i++) {
        printf("%08x ", hash[i]);
    }
    return 0;
}