//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTL(a,b) (((a) << (b)) | ((a) >> (32 - (b))))

uint32_t digest[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

uint32_t k[64] = {
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

uint32_t str_len;
uint32_t bit_len;
uint8_t  msg_block[64];
uint32_t msg_schedule[64];
uint32_t a, b, c, d, e, f, g, h;
uint32_t t1, t2;

void sha256_init() {
    str_len = 0;
    bit_len = 0;

    a = digest[0];
    b = digest[1];
    c = digest[2];
    d = digest[3];
    e = digest[4];
    f = digest[5];
    g = digest[6];
    h = digest[7];
}

void sha256_transform() {
    uint32_t i;

    for (i = 0; i < 64; i++) {
        if (i < 16) {
            msg_schedule[i] = ((uint32_t)msg_block[i*4 + 0] << 24) |
                              ((uint32_t)msg_block[i*4 + 1] << 16) |
                              ((uint32_t)msg_block[i*4 + 2] << 8) |
                              ((uint32_t)msg_block[i*4 + 3] << 0);
        } else {
            uint32_t s0 = ROTL(msg_schedule[i-15], 7) ^
                          ROTL(msg_schedule[i-15], 18) ^
                          (msg_schedule[i-15] >> 3);
            uint32_t s1 = ROTL(msg_schedule[i-2], 17) ^
                          ROTL(msg_schedule[i-2], 19) ^
                          (msg_schedule[i-2] >> 10);

            msg_schedule[i] = msg_schedule[i-16] + s0 + msg_schedule[i-7] + s1;
        }

        uint32_t s1 = ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25);
        t1 = h + s1 + ((e & f) ^ (~e & g)) + k[i] + msg_schedule[i];

        uint32_t s0 = ROTL(a, 2) ^ ROTL(a, 13) ^ ROTL(a, 22);
        t2 = s0 + ((a & b) ^ (a & c) ^ (b & c));

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    digest[0] += a;
    digest[1] += b;
    digest[2] += c;
    digest[3] += d;
    digest[4] += e;
    digest[5] += f;
    digest[6] += g;
    digest[7] += h;
}

void sha256_update(const uint8_t *message, size_t len) {
    for (size_t i = 0; i < len; i++) {
        msg_block[str_len++] = message[i];
        bit_len += 8;

        if (str_len == 64) {
            sha256_transform();
            str_len = 0;
        }
    }
}

void sha256_final(uint8_t *hash) {
    uint32_t i;

    i = str_len;

    if (str_len < 56) {
        msg_block[i++] = 0x80;

        while (i < 56) {
            msg_block[i++] = 0x00;
        }
    } else {
        msg_block[i++] = 0x80;

        while (i < 64) {
            msg_block[i++] = 0x00;
        }

        sha256_transform();

        memset(msg_block, 0, 56);
    }

    msg_block[56] = (bit_len >> 56) & 0xff;
    msg_block[57] = (bit_len >> 48) & 0xff;
    msg_block[58] = (bit_len >> 40) & 0xff;
    msg_block[59] = (bit_len >> 32) & 0xff;
    msg_block[60] = (bit_len >> 24) & 0xff;
    msg_block[61] = (bit_len >> 16) & 0xff;
    msg_block[62] = (bit_len >> 8) & 0xff;
    msg_block[63] = (bit_len >> 0) & 0xff;

    sha256_transform();

    for (i = 0; i < 4; i++) {
        hash[i]      = (digest[0] >> (24 - i * 8)) & 0xff;
        hash[i+4]    = (digest[1] >> (24 - i * 8)) & 0xff;
        hash[i+8]    = (digest[2] >> (24 - i * 8)) & 0xff;
        hash[i+12]   = (digest[3] >> (24 - i * 8)) & 0xff;
        hash[i+16]   = (digest[4] >> (24 - i * 8)) & 0xff;
        hash[i+20]   = (digest[5] >> (24 - i * 8)) & 0xff;
        hash[i+24]   = (digest[6] >> (24 - i * 8)) & 0xff;
        hash[i+28]   = (digest[7] >> (24 - i * 8)) & 0xff;
    }
}

int main() {
    char message[] = "This is a test message";
    uint8_t hash[32];

    sha256_init();
    sha256_update((uint8_t*)message, strlen(message));
    sha256_final(hash);

    printf("Hash: ");

    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }

    printf("\n");

    return 0;
}