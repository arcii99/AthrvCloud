//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROTL(x, n) ((x << n) | (x >> (64 - n)))

uint8_t PAD[256] = {0};
uint8_t RESULT[64] = {0};

uint64_t K[80] = {
    0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
    0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
    0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
    0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
    0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
    0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
    0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
    0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
    0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
    0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
    0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
    0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
    0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
    0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
    0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
    0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
    0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
    0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
    0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

void sha512_transform(uint64_t* state, uint8_t* data) {
    uint64_t a, b, c, d, e, f, g, h, t1, t2, m[80];
    int i, j;

    for (i = 0, j = 0; i < 16; ++i, j += 8) {
        m[i] = ((uint64_t)data[j] << 56) |
               ((uint64_t)data[j+1] << 48) |
               ((uint64_t)data[j+2] << 40) |
               ((uint64_t)data[j+3] << 32) |
               ((uint64_t)data[j+4] << 24) |
               ((uint64_t)data[j+5] << 16) |
               ((uint64_t)data[j+6] << 8) |
               ((uint64_t)data[j+7]);
    }
    for (; i < 80; ++i) {
        m[i] = ROTL(m[i-2], 19) ^ ROTL(m[i-2], 61) ^ (m[i-2] >> 6);
        m[i] += m[i-7];
        m[i] += ROTL(m[i-15], 1) ^ ROTL(m[i-15], 8) ^ (m[i-15] >> 7);
        m[i] += m[i-16];
    }

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    for (i = 0; i < 80; ++i) {
        t1 = h + (ROTL(e, 14) ^ ROTL(e, 18) ^ ROTL(e, 41));
        t1 += ((e & f) ^ (~e & g)) + K[i] + m[i];
        t2 = (ROTL(a, 28) ^ ROTL(a, 34) ^ ROTL(a, 39));
        t2 += ((a & b) ^ (a & c) ^ (b & c));

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

void sha512_padding(uint8_t* data, uint64_t data_len, uint8_t* pad) {
    int pad_len = 0;
    uint64_t i, j;

    pad_len = (data_len % 128 < 112) ? (128 - data_len % 128) : (256 - data_len % 128);
    pad[0] = 0x80;
    for (i = 0; i < pad_len - 16; ++i) {
        pad[i+1] = 0x00;
    }
    pad[i+1] = (data_len >> 123);
    pad[i+2] = (data_len >> 115) & 0xff;
    pad[i+3] = (data_len >> 107) & 0xff;
    pad[i+4] = (data_len >> 99) & 0xff;
    pad[i+5] = (data_len >> 91) & 0xff;
    pad[i+6] = (data_len >> 83) & 0xff;
    pad[i+7] = (data_len >> 75) & 0xff;
    pad[i+8] = (data_len >> 67) & 0xff;
    pad[i+9] = (data_len >> 59) & 0xff;
    pad[i+10] = (data_len >> 51) & 0xff;
    pad[i+11] = (data_len >> 43) & 0xff;
    pad[i+12] = (data_len >> 35) & 0xff;
    pad[i+13] = (data_len >> 27) & 0xff;
    pad[i+14] = (data_len >> 19) & 0xff;
    pad[i+15] = (data_len >> 11) & 0xff;

    for (i = 0, j = 0; i < pad_len - 16; ++i, ++j) {
        if (i < data_len % 128) {
            pad[i] = data[j];
        } else {
            pad[i] = 0x00;
        }
    }
}

void sha512(uint8_t* data, uint64_t data_len) {
    uint64_t state[8] = {
        0x6a09e667f3bcc908, 0xbb67ae8584caa73b,
        0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
        0x510e527fade682d1, 0x9b05688c2b3e6c1f,
        0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
    };
    int i;

    sha512_padding(data, data_len, PAD);

    for (i = 0; i < data_len; i += 128) {
        sha512_transform(state, PAD+i);
    }

    for (i = 0; i < 8; ++i) {
        RESULT[i*8 + 0] = (state[i] >> 56) & 0xff;
        RESULT[i*8 + 1] = (state[i] >> 48) & 0xff;
        RESULT[i*8 + 2] = (state[i] >> 40) & 0xff;
        RESULT[i*8 + 3] = (state[i] >> 32) & 0xff;
        RESULT[i*8 + 4] = (state[i] >> 24) & 0xff;
        RESULT[i*8 + 5] = (state[i] >> 16) & 0xff;
        RESULT[i*8 + 6] = (state[i] >> 8) & 0xff;
        RESULT[i*8 + 7] = (state[i]) & 0xff;
    }
}

int main() {
    uint8_t data[] = "Hello, World!";
    uint64_t data_len = strlen((char*)data);

    sha512(data, data_len);

    printf("Hash of \"Hello, World!\" is: ");
    for (int i = 0; i < 64; ++i) {
        printf("%02x", RESULT[i]);
    }

    return 0;
}