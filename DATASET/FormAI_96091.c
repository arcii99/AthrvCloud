//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define constants for SHA-512 hash function
#define ROTR(x, n) (((x) >> (n)) | ((x) << (64 - (n))))
#define Ch(x, y, z) ((x & y) ^ (~x & z))
#define Maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39))
#define SIGMA1(x) (ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41))
#define sigma0(x) (ROTR(x, 1) ^ ROTR(x, 8) ^ ((x) >> 7))
#define sigma1(x) (ROTR(x, 19) ^ ROTR(x, 61) ^ ((x) >> 6))

// Define initial buffer for SHA-512 hash function
const uint64_t K[] = {
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
    0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817};

// Define SHA-512 hash function
void sha512_hash(const uint8_t *message, size_t message_len, uint64_t hash[8])
{
    // Define variables for SHA-512 hash function
    uint64_t w[80];
    uint64_t a, b, c, d, e, f, g, h, T1, T2;
    uint64_t H[] = {0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
                    0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179};
    size_t i, idx, j;

    // Pad message to multiple of 1024 bits
    size_t new_len = ((((message_len + 16) / 128) + 1) * 128) - 16;
    uint8_t *padded = calloc(new_len, 1);
    memcpy(padded, message, message_len);
    padded[message_len] = 0x80;
    *(uint64_t *)(padded + new_len - 8) = (uint64_t)message_len * 8;

    // Process padded message in 1024-bit blocks
    for (i = 0; i < new_len; i += 128)
    {
        // Read 1024-bit block of padded message into message schedule array
        for (j = 0; j < 16; j++)
        {
            idx = i + (j * 8);
            w[j] = (((uint64_t)(padded[idx + 0]) << 56) |
                    ((uint64_t)(padded[idx + 1]) << 48) |
                    ((uint64_t)(padded[idx + 2]) << 40) |
                    ((uint64_t)(padded[idx + 3]) << 32) |
                    ((uint64_t)(padded[idx + 4]) << 24) |
                    ((uint64_t)(padded[idx + 5]) << 16) |
                    ((uint64_t)(padded[idx + 6]) << 8) |
                    ((uint64_t)(padded[idx + 7]) << 0));
        }
        for (j = 16; j < 80; j++)
        {
            w[j] = sigma1(w[j-2]) + w[j-7] + sigma0(w[j-15]) + w[j-16];
        }

        // Initialize working variables with current hash value
        a = H[0]; b = H[1]; c = H[2]; d = H[3];
        e = H[4]; f = H[5]; g = H[6]; h = H[7];

        // Perform 80 rounds of SHA-512 hash function
        for (j = 0; j < 80; j++)
        {
            T1 = h + SIGMA1(e) + Ch(e, f, g) + K[j] + w[j];
            T2 = SIGMA0(a) + Maj(a, b, c);
            h = g; g = f; f = e; e = d + T1;
            d = c; c = b; b = a; a = T1 + T2;
        }

        // Update hash value with working variables
        H[0] += a; H[1] += b; H[2] += c; H[3] += d;
        H[4] += e; H[5] += f; H[6] += g; H[7] += h;
    }

    // Copy final hash value to output array
    memcpy(hash, H, 64);
}

int main(int argc, char **argv)
{
    // Define input message for SHA-512 hash function
    uint8_t message[] = {0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64};

    // Define buffer for SHA-512 hash output
    uint64_t hash[8];

    // Hash input message using SHA-512 hash function
    sha512_hash(message, sizeof(message), hash);

    // Print hash output in hexadecimal format
    printf("SHA-512 Hash:\n");
    for (size_t i = 0; i < 8; i++)
    {
        printf("%016lx", hash[i]);
    }
    printf("\n");

    return 0;
}