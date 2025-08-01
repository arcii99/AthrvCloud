//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROTL64(x, y) (((x) << (y)) | ((x) >> (64 - (y))))
#define ROTR64(x, y) (((x) >> (y)) | ((x) << (64 - (y))))

typedef unsigned char byte;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned long long uint64;

// Constants for SHA-512
const uint64 k[80] = {
    0x428a2f98d728ae22ull, 0x7137449123ef65cdull, 0xb5c0fbcfec4d3b2full, 0xe9b5dba58189dbbcull,
    0x3956c25bf348b538ull, 0x59f111f1b605d019ull, 0x923f82a4af194f9bull, 0xab1c5ed5da6d8118ull,
    0xd807aa98a3030242ull, 0x12835b0145706fbeull, 0x243185be4ee4b28cull, 0x550c7dc3d5ffb4e2ull,
    0x72be5d74f27b896full, 0x80deb1fe3b1696b1ull, 0x9bdc06a725c71235ull, 0xc19bf174cf692694ull,
    0xe49b69c19ef14ad2ull, 0xefbe4786384f25e3ull, 0x0fc19dc68b8cd5b5ull, 0x240ca1cc77ac9c65ull,
    0x2de92c6f592b0275ull, 0x4a7484aa6ea6e483ull, 0x5cb0a9dcbd41fbd4ull, 0x76f988da831153b5ull,
    0x983e5152ee66dfabull, 0xa831c66d2db43210ull, 0xb00327c898fb213full, 0xbf597fc7beef0ee4ull,
    0xc6e00bf33da88fc2ull, 0xd5a79147930aa725ull, 0x06ca6351e003826full, 0x142929670a0e6e70ull,
    0x27b70a8546d22ffcull, 0x2e1b21385c26c926ull, 0x4d2c6dfc5ac42aedull, 0x53380d139d95b3dfull,
    0x650a73548baf63deull, 0x766a0abb3c77b2a8ull, 0x81c2c92e47edaee6ull, 0x92722c851482353bull,
    0xa2bfe8a14cf10364ull, 0xa81a664bbc423001ull, 0xc24b8b70d0f89791ull, 0xc76c51a30654be30ull,
    0xd192e819d6ef5218ull, 0xd69906245565a910ull, 0xf40e35855771202aull, 0x106aa07032bbd1b8ull,
    0x19a4c116b8d2d0c8ull, 0x1e376c085141ab53ull, 0x2748774cdf8eeb99ull, 0x34b0bcb5e19b48a8ull,
    0x391c0cb3c5c95a63ull, 0x4ed8aa4ae3418acbull, 0x5b9cca4f7763e373ull, 0x682e6ff3d6b2b8a3ull,
    0x748f82ee5defb2fcull, 0x78a5636f43172f60ull, 0x84c87814a1f0ab72ull, 0x8cc702081a6439ecull,
    0x90befffa23631e28ull, 0xa4506cebde82bde9ull, 0xbef9a3f7b2c67915ull, 0xc67178f2e372532bull,
    0xca273eceea26619cull, 0xd186b8c721c0c207ull, 0xeada7dd6cde0eb1eull, 0xf57d4f7fee6ed178ull,
    0x06f067aa72176fbaull, 0x0a637dc5a2c898a6ull, 0x113f9804bef90daeull, 0x1b710b35131c471bull,
    0x28db77f523047d84ull, 0x32caab7b40c72493ull, 0x3c9ebe0a15c9bebcull, 0x431d67c49c100d4cull,
    0x4cc5d4becb3e42b6ull, 0x597f299cfc657e2aull, 0x5fcb6fab3ad6faecull, 0x6c44198c4a475817ull
};

// SHA-512 functions
uint64 Ch(uint64 x, uint64 y, uint64 z) { return (x & y) ^ (~x & z); }
uint64 Maj(uint64 x, uint64 y, uint64 z) { return (x & y) ^ (x & z) ^ (y & z); }
uint64 Sigma0(uint64 x) { return ROTR64(x, 28) ^ ROTR64(x, 34) ^ ROTR64(x, 39); }
uint64 Sigma1(uint64 x) { return ROTR64(x, 14) ^ ROTR64(x, 18) ^ ROTR64(x, 41); }
uint64 sigma0(uint64 x) { return ROTR64(x, 1) ^ ROTR64(x, 8) ^ (x >> 7); }
uint64 sigma1(uint64 x) { return ROTR64(x, 19) ^ ROTR64(x, 61) ^ (x >> 6); }

void sha512_transform(uint64 *state, const byte *data) {
    uint64 a, b, c, d, e, f, g, h, t1, t2, m[80];
    for (int i = 0; i < 16; i++) {
        m[i] = ((uint64)data[i * 8 + 0] << 56) | ((uint64)data[i * 8 + 1] << 48) | ((uint64)data[i * 8 + 2] << 40)
            | ((uint64)data[i * 8 + 3] << 32) | ((uint64)data[i * 8 + 4] << 24) | ((uint64)data[i * 8 + 5] << 16)
            | ((uint64)data[i * 8 + 6] << 8) | ((uint64)data[i * 8 + 7] << 0);
    }
    for (int i = 16; i < 80; i++) {
        m[i] = sigma1(m[i - 2]) + m[i - 7] + sigma0(m[i - 15]) + m[i - 16];
    }
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];
    for (int i = 0; i < 80; i++) {
        t1 = h + Sigma1(e) + Ch(e, f, g) + k[i] + m[i];
        t2 = Sigma0(a) + Maj(a, b, c);
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

void sha512(const void *data, size_t length, byte *hash) {
    uint64 state[8] = {
        0x6a09e667f3bcc908ull, 0xbb67ae8584caa73bull, 0x3c6ef372fe94f82bull, 0xa54ff53a5f1d36f1ull,
        0x510e527fade682d1ull, 0x9b05688c2b3e6c1full, 0x1f83d9abfb41bd6bull, 0x5be0cd19137e2179ull
    };
    size_t i;
    size_t size = length;
    const byte *cur = (const byte*)data;
    while (length >= 128) {
        sha512_transform(state, cur);
        cur += 128;
        length -= 128;
    }
    byte last[256] = { 0 };
    memcpy(last, cur, length);
    last[length] = 0x80;
    if (length < 112) {
        for (i = length + 1; i < 125; i++) last[i] = 0;
        i = 120 - 8;
    } else {
        for (i = length + 1; i < 248; i++) last[i] = 0;
        i = 256 - 8;
    }
    ulong longSize = (ulong)(size << 3);
    last[i + 0] = (byte)(longSize >> 56);
    last[i + 1] = (byte)(longSize >> 48);
    last[i + 2] = (byte)(longSize >> 40);
    last[i + 3] = (byte)(longSize >> 32);
    last[i + 4] = (byte)(longSize >> 24);
    last[i + 5] = (byte)(longSize >> 16);
    last[i + 6] = (byte)(longSize >> 8);
    last[i + 7] = (byte)(longSize >> 0);
    sha512_transform(state, last);
    for (i = 0; i < 8; i++) {
        hash[i * 8 + 0] = (byte)(state[i] >> 56);
        hash[i * 8 + 1] = (byte)(state[i] >> 48);
        hash[i * 8 + 2] = (byte)(state[i] >> 40);
        hash[i * 8 + 3] = (byte)(state[i] >> 32);
        hash[i * 8 + 4] = (byte)(state[i] >> 24);
        hash[i * 8 + 5] = (byte)(state[i] >> 16);
        hash[i * 8 + 6] = (byte)(state[i] >> 8);
        hash[i * 8 + 7] = (byte)(state[i] >> 0);
    }
}

int main() {
    char input[1024];
    byte hash[64];
    printf("Enter a string to hash: ");
    fgets(input, 1024, stdin);
    input[strcspn(input, "\r\n")] = '\0';
    sha512(input, strlen(input), hash);
    printf("SHA-512 hash of \"%s\":\n", input);
    for (int i = 0; i < 64; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}