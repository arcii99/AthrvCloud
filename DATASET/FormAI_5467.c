//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: standalone
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Constants for SHA-384 and SHA-512
static const uint64_t K[80] = {
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

// Rotate right function
#define ROTR(x,n) (((x) >> (n)) | ((x) << (64u - (n))))

// SHA-512 functions
#define Ch(x,y,z) ((x & y) ^ (~x & z))
#define Maj(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define Sigma0(x) (ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39))
#define Sigma1(x) (ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41))
#define delta0(x) (ROTR(x, 1) ^ ROTR(x, 8) ^ ((x) >> 7))
#define delta1(x) (ROTR(x, 19) ^ ROTR(x, 61) ^ ((x) >> 6))

// Initialize SHA-512 context
void sha512_init(uint64_t *ctx)
{
    ctx[0] = 0x6a09e667f3bcc908;
    ctx[1] = 0xbb67ae8584caa73b;
    ctx[2] = 0x3c6ef372fe94f82b;
    ctx[3] = 0xa54ff53a5f1d36f1;
    ctx[4] = 0x510e527fade682d1;
    ctx[5] = 0x9b05688c2b3e6c1f;
    ctx[6] = 0x1f83d9abfb41bd6b;
    ctx[7] = 0x5be0cd19137e2179;
}

// Process a 1024-bit block of data
void sha512_process(uint64_t *ctx, const uint64_t *data)
{
    uint64_t a, b, c, d, e, f, g, h, t1, t2;
    uint64_t w[80];
    int i;

    // Copy the data into the message schedule
    for (i = 0; i < 16; ++i)
        w[i] = data[i];

    // Prepare the message schedule
    for (i = 16; i < 80; ++i)
        w[i] = delta1(w[i-2]) + w[i-7] + delta0(w[i-15]) + w[i-16];

    // Initialize the working variables
    a = ctx[0];
    b = ctx[1];
    c = ctx[2];
    d = ctx[3];
    e = ctx[4];
    f = ctx[5];
    g = ctx[6];
    h = ctx[7];

    // Perform the hash calculations
    for (i = 0; i < 80; ++i)
    {
        t1 = h + Sigma1(e) + Ch(e, f, g) + K[i] + w[i];
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

    // Update the context
    ctx[0] += a;
    ctx[1] += b;
    ctx[2] += c;
    ctx[3] += d;
    ctx[4] += e;
    ctx[5] += f;
    ctx[6] += g;
    ctx[7] += h;
}

// SHA-384 hash function
void sha384(const uint8_t *message, size_t len, uint8_t *hash)
{
    const uint64_t *data;
    uint64_t buf[8];
    size_t i, r, blocks;

    // Initialize the context
    sha512_init(buf);

    // Process the message in 1024-bit blocks
    data = (const uint64_t*) message;
    blocks = len / 128;
    for (i = 0; i < blocks; ++i)
        sha512_process(buf, data + 16 * i);

    // Pad the message if necessary
    r = len % 128;
    uint8_t pad[128] = {0};
    memcpy(pad, message + len - r, r);
    pad[r] = 0x80;
    if (r >= 112)
    {
        sha512_process(buf, (const uint64_t*) pad);
        memset(pad, 0, 128);
    }
    *(uint64_t*) (pad + 112) = 0;
    *(uint64_t*) (pad + 120) = (blocks * 2 + 1) << 6;
    sha512_process(buf, (const uint64_t*) pad);

    // Write the hash value
    for (i = 0; i < 6; ++i)
    {
        *hash++ = (buf[i] >> 56) & 0xff;
        *hash++ = (buf[i] >> 48) & 0xff;
        *hash++ = (buf[i] >> 40) & 0xff;
        *hash++ = (buf[i] >> 32) & 0xff;
        *hash++ = (buf[i] >> 24) & 0xff;
        *hash++ = (buf[i] >> 16) & 0xff;
        *hash++ = (buf[i] >> 8) & 0xff;
        *hash++ = buf[i] & 0xff;
    }
}

// Test the SHA-384 implementation
int main()
{
    uint8_t message[] = "Hello, world!";
    uint8_t hash[48];

    sha384(message, strlen((char*)message), hash);

    printf("Hash value: ");
    for (int i = 0; i < 48; ++i)
        printf("%02x", hash[i]);
    printf("\n");

    return 0;
}