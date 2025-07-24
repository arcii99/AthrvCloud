//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: future-proof
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Rotation macros for 32-bit integers
#define ROTL32(x,y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x,y) ((x >> y) | (x << (32 - y)))

// Constants used for SHA-256
static const uint32_t K[] = {
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

// SHA-256 functions
static uint32_t Ch(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (~x & z);
}

static uint32_t Maj(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

static uint32_t Sigma0(uint32_t x)
{
    return ROTR32(x, 2) ^ ROTR32(x, 13) ^ ROTR32(x, 22);
}

static uint32_t Sigma1(uint32_t x)
{
    return ROTR32(x, 6) ^ ROTR32(x, 11) ^ ROTR32(x, 25);
}

static uint32_t sigma0(uint32_t x)
{
    return ROTR32(x, 7) ^ ROTR32(x, 18) ^ (x >> 3);
}

static uint32_t sigma1(uint32_t x)
{
    return ROTR32(x, 17) ^ ROTR32(x, 19) ^ (x >> 10);
}

// Main SHA-256 function
void sha256(const uint8_t *message, uint32_t len, uint8_t hash[])
{
    uint32_t h[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    uint32_t messageSchedule[64] = {0};
    uint32_t a, b, c, d, e, f, g, hPrime;
    uint32_t t1, t2;

    uint32_t i, j;

    // Divide the message into 512-bit blocks
    for(i = 0; i < len/64; i++)
    {
        // Copy the block into the message schedule
        for(j = 0; j < 16; j++)
        {
            messageSchedule[j] = (message[(i*64)+(j*4)] << 24) |
                                 (message[(i*64)+(j*4)+1] << 16) |
                                 (message[(i*64)+(j*4)+2] << 8) |
                                 (message[(i*64)+(j*4)+3]);
        }

        // Extend the message schedule
        for(j = 16; j < 64; j++)
        {
            messageSchedule[j] = sigma1(messageSchedule[j-2]) + messageSchedule[j-7] +
                                  sigma0(messageSchedule[j-15]) + messageSchedule[j-16];
        }

        // Initialize working variables
        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];
        f = h[5];
        g = h[6];
        hPrime = h[7];

        // Compression loop
        for(j = 0; j < 64; j++)
        {
            t1 = hPrime + Sigma1(e) + Ch(e,f,g) + K[j] + messageSchedule[j];
            t2 = Sigma0(a) + Maj(a,b,c);
            hPrime = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Update the hash values
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += hPrime;
    }

    // Convert the hash to bytes
    for(i = 0; i < 32; i++)
    {
        hash[i] = (h[i/4] >> (24-8*(i%4))) & 0xff;
    }
}

int main()
{
    uint8_t message[] = "Hello, world! This is a test message.";
    uint8_t hash[32];

    sha256(message, strlen((char*)message), hash);

    printf("Hash: ");
    for(int i=0; i<32; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}