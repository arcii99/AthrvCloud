//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: satisfied
#include <stdio.h>
#include <stdint.h>

typedef struct hashlib_sha256_state_s hashlib_sha256_state_t;

/**
 * This file implements the Secure Hash Algorithms SHA-256 as defined in
 * FIPS PUB 180-2 published by NIST.
 **/

struct hashlib_sha256_state_s {
    uint32_t state[8];
    uint64_t bitcount;
    uint8_t  buffer[64];
    uint32_t buflen;
};

static inline void memcpy_swap(uint8_t *restrict dst, const uint8_t *restrict src, size_t n) {
    while (n --> 0) {
        *dst++ = src[n];
    }
}

static inline uint32_t rol(uint32_t value, uint8_t bits) {
    return ((value) << (bits)) | ((value) >> (32 - (bits)));
}

static inline uint32_t sha_ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

static inline uint32_t sha_maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

static inline uint32_t sha_bsig0(uint32_t x) {
    return rol(x, 2) ^ rol(x, 13) ^ rol(x, 22);
}

static inline uint32_t sha_bsig1(uint32_t x) {
    return rol(x, 6) ^ rol(x, 11) ^ rol(x, 25);
}

static inline uint32_t sha_ssig0(uint32_t x) {
    return rol(x, 7) ^ rol(x, 18) ^ (x >> 3);
}

static inline uint32_t sha_ssig1(uint32_t x) {
    return rol(x, 17) ^ rol(x, 19) ^ (x >> 10);
}

/* SHA-256 functions */

void hashlib_sha256_init(hashlib_sha256_state_t *s);
void hashlib_sha256_update(hashlib_sha256_state_t *s, const uint8_t *data, size_t len);
void hashlib_sha256_final(hashlib_sha256_state_t *s, uint8_t *digest);

void hashlib_sha256_init(hashlib_sha256_state_t *s) {
    static const uint32_t sha256_inits[8] = {
        0x6a09e667, 0xbb67ae85,
        0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c,
        0x1f83d9ab, 0x5be0cd19
    };
    int i;

    s->bitcount = 0;
    s->buflen = 0;
    for (i = 0; i < 8; i ++) {
        s->state[i] = sha256_inits[i];
    }
}

void hashlib_sha256_update(hashlib_sha256_state_t *s, const uint8_t *data, size_t len) {
    uint64_t i, j, k;

    for (i = 0; i < len; i ++) {
        s->buffer[s->buflen ++] = data[i];
        if (s->buflen == 64) {
            uint32_t W[64];
            uint32_t a, b, c, d, e, f, g, h;

            /* Initialize registers */
            memcpy_swap((uint8_t *) W, s->buffer, sizeof W);
            for (j = 16; j < 64; j ++) {
                W[j] = sha_ssig1(W[j - 2]) + W[j - 7] + sha_ssig0(W[j - 15]) + W[j - 16];
            }
            a = s->state[0];
            b = s->state[1];
            c = s->state[2];
            d = s->state[3];
            e = s->state[4];
            f = s->state[5];
            g = s->state[6];
            h = s->state[7];

            /* Computation */
            for (j = 0; j < 64; j ++) {
                uint32_t T1 = h + sha_bsig1(e) + sha_ch(e, f, g) + h;
                uint32_t T2 = sha_bsig0(a) + sha_maj(a, b, c);
                h = g;
                g = f;
                f = e;
                e = d + T1;
                d = c;
                c = b;
                b = a;
                a = T1 + T2 + W[j];
            }

            s->state[0] += a;
            s->state[1] += b;
            s->state[2] += c;
            s->state[3] += d;
            s->state[4] += e;
            s->state[5] += f;
            s->state[6] += g;
            s->state[7] += h;

            s->buflen = 0;
        }
        s->bitcount += 8;
    }
}

void hashlib_sha256_final(hashlib_sha256_state_t *s, uint8_t *digest) {
    uint32_t i, j;
    uint8_t *p;

    /* Add padding */
    i = s->buflen;
    if (i < 56) {
        s->buffer[i ++] = 0x80;
        while (i < 56) {
            s->buffer[i ++] = 0;
        }
    } else {
        s->buffer[i ++] = 0x80;
        while (i < 64) {
            s->buffer[i ++] = 0;
        }
        hashlib_sha256_update(s, s->buffer, 64);
        memset(s->buffer, 0, sizeof s->buffer);
    }

    /* Append length */
    p = s->buffer;
    for (i = 56; i < 64; i ++) {
        *p ++ = (uint8_t) (s->bitcount >> 56);
        s->bitcount <<= 8;
    }
    hashlib_sha256_update(s, s->buffer, 64);

    /* Output digest */
    p = digest;
    for (i = 0; i < 8; i ++) {
        uint32_t h = s->state[i];
        for (j = 0; j < 4; j ++) {
            *p ++ = (uint8_t) (h >> 24);
            h <<= 8;
        }
    }
}

int main() {
    hashlib_sha256_state_t state;
    char buffer[] = "The Quick Brown Fox Jumps Over The Lazy Dog";
    uint8_t digest[32];
    size_t i;

    hashlib_sha256_init(&state);
    hashlib_sha256_update(&state, (uint8_t *) buffer, sizeof buffer - 1);
    hashlib_sha256_final(&state, digest);

    for (i = 0; i < 32; i ++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}