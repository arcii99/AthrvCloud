//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// Constants for SHA-256
#define SHA256_BLOCK_SIZE 32
#define SHA256_HASH_SIZE 32

// Structure for SHA-256 hash values
typedef struct sha256_hash_t {
    uint8_t bytes[SHA256_HASH_SIZE];
} sha256_hash;

// Structure for SHA-256 state values
typedef struct sha256_state_t {
    uint32_t state[8];
    uint32_t message_length;
    uint64_t total_length;
} sha256_state;

// Functions for SHA-256
void sha256_init(sha256_state *state);
void sha256_update(sha256_state *state, const uint8_t *data, uint32_t len);
void sha256_finalize(sha256_state *state, sha256_hash *hash);

void sha256_transform(sha256_state *state, const uint8_t *data);

// Initialize SHA-256 state values
void sha256_init(sha256_state *state) {
    state->state[0] = 0x6a09e667;
    state->state[1] = 0xbb67ae85;
    state->state[2] = 0x3c6ef372;
    state->state[3] = 0xa54ff53a;
    state->state[4] = 0x510e527f;
    state->state[5] = 0x9b05688c;
    state->state[6] = 0x1f83d9ab;
    state->state[7] = 0x5be0cd19;

    state->message_length = 0;
    state->total_length = 0;
}

// Update SHA-256 state values with new data
void sha256_update(sha256_state *state, const uint8_t *data, uint32_t len) {
    uint32_t i;
    for (i = 0; i < len; i++) {
        if (state->message_length == SHA256_BLOCK_SIZE) {
            sha256_transform(state, data+i-SHA256_BLOCK_SIZE);
            state->message_length = 0;
        }
        state->message_length++;
        state->total_length++;
    }
}

// Finalize SHA-256 state values and produce hash
void sha256_finalize(sha256_state *state, sha256_hash *hash) {
    uint32_t i;
    uint8_t padding[SHA256_BLOCK_SIZE];
    int padding_length;

    // Compute padding based on message length
    padding_length = SHA256_BLOCK_SIZE - (state->total_length % SHA256_BLOCK_SIZE);
    if (padding_length == 1) {
        padding[0] = 0x80;
    } else {
        padding[0] = 0x80;
        for (i = 1; i < padding_length-1; i++) {
            padding[i] = 0;
        }
    }

    // Compute final SHA-256 hash value
    sha256_update(state, padding, padding_length);
    sha256_update(state, (uint8_t *)&state->total_length, sizeof(uint64_t));
    for (i = 0; i < 8; i++) {
        hash->bytes[i*4] = (state->state[i] >> 24) & 0xff;
        hash->bytes[i*4+1] = (state->state[i] >> 16) & 0xff;
        hash->bytes[i*4+2] = (state->state[i] >> 8) & 0xff;
        hash->bytes[i*4+3] = state->state[i] & 0xff;
    }
}

// Transform function for SHA-256
void sha256_transform(sha256_state *state, const uint8_t *data) {
    uint32_t i;
    uint32_t a, b, c, d, e, f, g, h, t1, t2;
    uint32_t message_schedule[64];
    uint32_t word;

    // Prepare message schedule
    for (i = 0; i < 16; i++) {
        word = data[i*4] << 24;
        word |= data[i*4+1] << 16;
        word |= data[i*4+2] << 8;
        word |= data[i*4+3];
        message_schedule[i] = word;
    }
    for (; i < 64; i++) {
        message_schedule[i] = message_schedule[i-16] +
                    (message_schedule[i-15] << 7 ^ message_schedule[i-15] >> 25) +
                    (message_schedule[i-7] << 15 ^ message_schedule[i-7] >> 17) +
                    message_schedule[i-2];
    }

    // Initialize working variables
    a = state->state[0];
    b = state->state[1];
    c = state->state[2];
    d = state->state[3];
    e = state->state[4];
    f = state->state[5];
    g = state->state[6];
    h = state->state[7];

    // Perform main SHA-256 transformations
    for (i = 0; i < 64; i++) {
        t1 = h + (e >> 6 ^ e << 26) + (e & f ^ ~e & g) + 0x428a2f98 + message_schedule[i];
        t2 = (a >> 2 ^ a << 30) + (a & b ^ a & c ^ b & c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Update state values with new SHA-256 hash
    state->state[0] += a;
    state->state[1] += b;
    state->state[2] += c;
    state->state[3] += d;
    state->state[4] += e;
    state->state[5] += f;
    state->state[6] += g;
    state->state[7] += h;
}

int main(int argc, char *argv[]) {
    // Read input file and compute SHA-256 hash
    FILE *input_file;
    sha256_hash hash;
    uint8_t buffer[1024];
    size_t bytes_read;
    sha256_state state;

    // Initialize SHA-256 state values
    sha256_init(&state);

    // Open input file
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Could not open input file");
        exit(1);
    }

    // Read input file and compute SHA-256 hash
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        sha256_update(&state, buffer, bytes_read);
    }
    sha256_finalize(&state, &hash);

    // Print SHA-256 hash as hexadecimal string
    for (int i = 0; i < SHA256_HASH_SIZE; i++) {
        printf("%02x", hash.bytes[i]);
    }
    printf("\n");

    // Close input file
    fclose(input_file);

    return 0;
}