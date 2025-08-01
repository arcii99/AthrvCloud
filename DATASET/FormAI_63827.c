//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: paranoid
// Paranoid-style Cryptographic Hash Function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,n) ((x << n) | (x >> (32 - n)))

static const uint8_t s[] = {
    0x19, 0xBB, 0x5A, 0x16, 0xD0, 0x5F, 0xB4, 0x0F, 0x89, 0x68, 0x6A, 0x2A,
    0xA5, 0xBC, 0xD9, 0x36, 0x24, 0x82, 0x73, 0x38, 0x91, 0xDE, 0xFB, 0x41,
    0xCB, 0x3B, 0xB6, 0xC9, 0x12, 0x7F, 0x99, 0x64, 0x22, 0xFC, 0x4D, 0xE5,
    0xF3, 0x5B, 0x85, 0x2D, 0xE3, 0xD7, 0xEF, 0x33, 0x44, 0x51, 0xA8, 0x8B,
    0x70, 0x6B, 0x80, 0x1E, 0x8D, 0xA6, 0x30, 0x47, 0x59, 0x3C, 0xA4, 0x2F,
    0x77, 0xA1, 0xE2, 0x56, 0x9C, 0x3A, 0x8A, 0x81, 0xC4, 0x92, 0xD4, 0x69,
    0xD6, 0x23, 0x42, 0x96, 0x7E, 0xE4, 0x6F, 0xD3, 0x58, 0x02, 0x15, 0x25,
    0x62, 0x71, 0x6D, 0x10, 0x6E, 0x4C, 0x35, 0x78, 0xC0, 0xCD, 0x57, 0xA9,
    0x76, 0x26, 0x4A, 0x2C, 0xB7, 0xB0, 0x5D, 0x21, 0x50, 0x4E, 0x3E, 0xDD,
    0x17, 0x09, 0xC3, 0x1A, 0xE7, 0xE0, 0x1F, 0x06, 0x0C, 0xA0, 0xF5, 0xCF,
    0x90, 0x14, 0xC6, 0x07, 0xCE, 0x95, 0x4F, 0xBF, 0x94, 0x2B, 0xAC, 0x45,
    0x4B, 0x63, 0xD8, 0x79, 0xCA, 0x3D, 0xF2, 0x86, 0x54, 0x1C, 0x1B, 0xC2,
    0xD5, 0x1D, 0x97, 0xC5, 0x61, 0x0B, 0x28, 0xEC, 0xA2, 0xFD, 0x83, 0x6C,
    0xEE, 0xAA, 0xF9, 0xDA, 0x93, 0x4E, 0x7C, 0x52, 0x0A, 0xB5, 0x87, 0x01,
    0xDB, 0x2E, 0x60, 0x20
};

static const uint32_t k[16] = {
    0x79D3E9E6, 0x52A47E3F, 0xE5DBA281, 0x7BA3C542, 
    0x6E9CBC71, 0xC7D5BF2D, 0x733622C5, 0x12BC1CBA, 
    0x80CD51A1, 0xAEECCEE3, 0x3F4424FD, 0x94D833FA, 
    0xF0EFAE0B, 0xEF3387FA, 0xCDCD776A, 0x0450188C
};

typedef struct {
    uint32_t h[4];
    uint32_t data[16];
    uint32_t len;
    uint32_t t;
} hash_state;

static void mix(hash_state *state) {
    uint32_t a, b, c, d;
    a = state->h[0]; b = state->h[1]; c = state->h[2]; d = state->h[3];
    a += (b ^ c ^ d) + state->data[state->t] + k[state->t];
    a = ROTL(a, 5) + s[state->t];
    state->t++;
    state->h[0] = d; state->h[1] = a; state->h[2] = b; state->h[3] = c;
}

static void update(hash_state *state, const void *data, uint32_t len) {
    uint32_t i;
    const uint8_t * in = (const uint8_t *)data;
    for (i = 0; i < len; i++) {
        state->data[state->len % 16] = (state->data[state->len % 16] << 8) + in[i];
        if ((state->len % 16) == 15) { mix(state); }
        state->len++;
    }
}

static void finalize(hash_state *state, uint8_t *out) {
    uint32_t i, data_len;
    uint8_t * p = out;
    state->data[state->len % 16] |= 0x80 << ((state->len % 16) * 8);
    data_len = state->len * 8;
    state->data[14] = data_len >> 32;
    state->data[15] = data_len & 0xFFFFFFFF;
    state->t = 0;
    for (i = (state->len % 16) + 1; i < 16; i++) {
        state->data[i] = 0;
    }
    while (state->t < 16) { mix(state); }
    for (i = 0; i < 4; i++) {
        p[0] = state->h[i] >> 24;
        p[1] = state->h[i] >> 16;
        p[2] = state->h[i] >> 8;
        p[3] = state->h[i];
        p += 4;
    }
}

static void hash(const void *data, uint32_t len, uint8_t *out) {
    hash_state state;
    state.h[0] = 0x67452301; state.h[1] = 0xEFCDAB89;
    state.h[2] = 0x98BADCFE; state.h[3] = 0x10325476;
    state.len = 0;
    state.t = 0;
    memset(state.data, 0, sizeof(state.data));
    update(&state, data, len);
    finalize(&state, out);
}

int main(int argc, char **argv) {
    uint8_t *hash_output;
    uint8_t example[] = "This is an example string to hash with our paranoid hash function";
    hash_output = (uint8_t *)malloc(16 * sizeof(uint8_t));
    hash((const void *)example, strlen((const char *)example), hash_output);

    printf("Hash of \"%s\" is:\n", example);
    for (int i = 0; i < 16; i++) {
        printf("%02x", hash_output[i]);
    }
    printf("\n");
    
    free(hash_output);
    return 0;
}