//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
#define ROTR(a, b) (((a) >> (b)) | ((a) << (32 - (b))))
#define XOR(a, b) (a ^ b)

typedef struct {
    unsigned int h[8]; // 256 bit hash result
    unsigned int buffer[16]; // Chunk buffer (512-bit)
    unsigned int num_buffered_bytes; // Number of bytes currently in buffer
    unsigned int total_length; // Total length of data hashed so far
} hash_state;

// Block size is 64 byte (512-bit) chunk
#define CHUNK_SIZE_BYTES 64

// SHA 256 uses these as initial values of the hash
static const unsigned int SHA256_H[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// SHA 256 uses these as round constants
static const unsigned int SHA256_K[64] = {
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

void sha256_transform(hash_state *state) {
    unsigned int i, t1, t2;
    unsigned int m[64];
    
    // Copy chunk into message schedule
    for (i = 0; i < 16; i++) {
        m[i] = (state->buffer[i] & 0xff000000) >> 24 |
               (state->buffer[i] & 0x00ff0000) >> 8 |
               (state->buffer[i] & 0x0000ff00) << 8 |
               (state->buffer[i] & 0x000000ff) << 24;
    }

    for (i = 16; i < 64; i++) {
        m[i] = ROTR(m[i-2], 17) ^ ROTR(m[i-2], 19) ^ (m[i-2] >> 10);
        m[i] += m[i-7];
        m[i] += ROTR(m[i-15], 7) ^ ROTR(m[i-15], 18) ^ (m[i-15] >> 3);
        m[i] += m[i-16];
    }

    // Initialize working variables
    unsigned int a = state->h[0];
    unsigned int b = state->h[1];
    unsigned int c = state->h[2];
    unsigned int d = state->h[3];
    unsigned int e = state->h[4];
    unsigned int f = state->h[5];
    unsigned int g = state->h[6];
    unsigned int h = state->h[7];

    // Compression algorithm
    for (i = 0; i < 64; i++) {
        t1 = h + (ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25)) + XOR((e & f), XOR(~e, g)) + SHA256_K[i] + m[i];
        t2 = (ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22)) + XOR((a & b), XOR((a & c), (b & c)));

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Update hash state
    state->h[0] += a;
    state->h[1] += b;
    state->h[2] += c;
    state->h[3] += d;
    state->h[4] += e;
    state->h[5] += f;
    state->h[6] += g;
    state->h[7] += h;
}

// Initialize hash state to SHA-256 initial values
void sha256_init(hash_state *state) {
    memcpy(state->h, SHA256_H, sizeof(SHA256_H));
    state->num_buffered_bytes = 0;
    state->total_length = 0;
}

// Update hash state with new data
void sha256_update(hash_state *state, const unsigned char *data, unsigned int length) {
    while (length) {
        unsigned int num_to_copy = CHUNK_SIZE_BYTES - state->num_buffered_bytes;
        if (num_to_copy > length) {
            num_to_copy = length;
        }

        memcpy(((unsigned char *)state->buffer) + state->num_buffered_bytes, data, num_to_copy);
        state->num_buffered_bytes += num_to_copy;
        state->total_length += num_to_copy * 8;
        
        if (state->num_buffered_bytes == CHUNK_SIZE_BYTES) {
            sha256_transform(state);
            state->num_buffered_bytes = 0;
        }

        data += num_to_copy;
        length -= num_to_copy;
    }
}

// Finalize hash and return result
void sha256_final(hash_state *state, unsigned char *digest) {
    unsigned int i;
    unsigned char *p_digest;

    // Pad the message
    unsigned int num_pad_bytes =
        (state->num_buffered_bytes < 56) ? (56 - state->num_buffered_bytes) : (120 - state->num_buffered_bytes);
    unsigned char pad[120];
    pad[0] = 0x80;
    memset(pad + 1, 0, num_pad_bytes - 1);
    state->total_length += state->num_buffered_bytes * 8;
    for (i = 0; i < 8; i++) {
        pad[num_pad_bytes++] = (state->total_length >> ((7 - i) * 8)) & 0xff;
    }

    // Hash padded message
    sha256_update(state, pad, num_pad_bytes);
    for (i = 0, p_digest = digest; i < 8; i++, p_digest += 4) {
        p_digest[0] = (state->h[i] & 0xff000000) >> 24;
        p_digest[1] = (state->h[i] & 0x00ff0000) >> 16;
        p_digest[2] = (state->h[i] & 0x0000ff00) >> 8;
        p_digest[3] = (state->h[i] & 0x000000ff);
    }
}

int main(int argc, char* argv[]) {
    hash_state state;
    unsigned char digest[32];
    unsigned char *string = "hello world";

    sha256_init(&state);
    sha256_update(&state, string, strlen((char *)string));
    sha256_final(&state, digest);

    int i;
    for (i=0; i<32; i++)
    {
        printf("%02x", digest[i]);
    }
    
    return 0;
}