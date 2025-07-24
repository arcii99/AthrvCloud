//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define ROTL(x,n) ((x) << (n)) | ((x) >> (32 - (n)))
#define ROTR(x,n) ((x) >> (n)) | ((x) << (32 - (n)))
#define BLK_SIZE 64

// Data types
typedef unsigned char byte;
typedef unsigned int uint32;

// Hash state struct
typedef struct {
    uint32 h[8];
    uint32 v[16];
    byte buffer[BLK_SIZE];
    uint32 len;
} sha256_state;

// SHA256 functions
uint32 sha256_k[] = {
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

void sha256_transform(sha256_state *state) {
    uint32 s[8], t[2], maj, ch;
    int i;

    // Initialize working variables
    for(i=0; i<8; i++) s[i] = state->h[i];

    // Process message
    for(i=0; i<64; i++) {
        if(i < 16) {
            t[0] = ROTR(s[4], 6) ^ ROTR(s[4], 11) ^ ROTR(s[4], 25);
            t[1] = (s[4] & s[5]) ^ (~s[4] & s[6]);
            state->v[i] = state->v[i] + state->buffer[i] + sha256_k[i] + t[1] + ROTR(t[0], 7);
        } else {
            t[0] = ROTR(state->v[i-2], 17) ^ ROTR(state->v[i-2], 19) ^ (state->v[i-2] >> 10);
            t[1] = ROTR(state->v[i-15], 7) ^ ROTR(state->v[i-15], 18) ^ (state->v[i-15] >> 3);
            state->v[i] = state->v[i-16] + t[1] + state->v[i-7] + t[0];
        }

        t[0] = ROTR(s[0], 2) ^ ROTR(s[0], 13) ^ ROTR(s[0], 22);
        maj = (s[0] & s[1]) ^ (s[0] & s[2]) ^ (s[1] & s[2]);
        t[1] = ROTR(s[7], 11) ^ ROTR(s[7], 13) ^ ROTR(s[7], 16);
        ch = (s[4] & s[5]) ^ (~s[4] & s[6]);

        s[7] = s[6];
        s[6] = s[5];
        s[5] = s[4];
        s[4] = s[3] + state->v[i];
        s[3] = s[2];
        s[2] = s[1];
        s[1] = s[0];
        s[0] = state->v[i] + t[1] + ch + sha256_k[i] + t[0];
    }

    // Update hash values
    for(i=0; i<8; i++) state->h[i] += s[i];
}

void sha256_init(sha256_state *state) {
    state->h[0] = 0x6a09e667;
    state->h[1] = 0xbb67ae85;
    state->h[2] = 0x3c6ef372;
    state->h[3] = 0xa54ff53a;
    state->h[4] = 0x510e527f;
    state->h[5] = 0x9b05688c;
    state->h[6] = 0x1f83d9ab;
    state->h[7] = 0x5be0cd19;

    memset(state->v, 0, sizeof(state->v));
    state->len = 0;
}

void sha256_update(sha256_state *state, byte *data, uint32 len) {
    uint32 idx, blk_len;

    for(idx=0; idx<len; idx++) {
        state->buffer[state->len++] = *data++;

        if(state->len == BLK_SIZE) {
            sha256_transform(state);
            state->len = 0;
        }
    }
}

void sha256_final(byte *hash, sha256_state *state) {
    uint32 idx, pad_len;
    byte *len_arr = (byte*)&state->len;

    // Pad message
    if(state->len < 56) pad_len = 56 - state->len;
    else pad_len = 120 - state->len;

    state->buffer[state->len++] = 0x80;
    while(state->len < BLK_SIZE - 8) {
        state->buffer[state->len++] = 0x00;
    }

    for(idx=0; idx<8; idx++) {
        state->buffer[state->len++] = len_arr[idx];
    }

    // Transform last block
    sha256_transform(state);

    // Copy hash value to output buffer
    for(idx=0; idx<32; idx++) {
        hash[idx] = (byte)((state->h[idx/4] >> (8*(3-idx%4))) & 0xff);
    }
}

int main() {
    byte data[] = "Hello, world!";
    byte hash[32];
    sha256_state state;

    sha256_init(&state);
    sha256_update(&state, data, strlen(data));
    sha256_final(hash, &state);

    printf("Hash value: ");
    for(int i=0; i<32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}