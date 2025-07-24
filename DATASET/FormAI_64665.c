//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to convert input string to hexadecimal
void strToHex(const char *input, uint8_t *output, size_t len)
{
    int i, j;
    for(i = 0, j = 0; j < len; i += 2, j++) {
        sscanf(input + i, "%2hhx", output + j);
    }
}

// Function to perform SHA256 hash
void sha256(const char* input, size_t len, uint8_t* output)
{
    uint32_t total_len = len * 8;
    uint32_t pad_len = (448 - (total_len % 512)) % 512;
    uint32_t pad_size = (pad_len + 64) / 8 + 1;
    uint32_t message_size = len + pad_size;

    char message[message_size];
    memset(message, 0, message_size);
    memcpy(message, input, len);
    message[len] = 0x80;

    for(int i = len + 1; i < message_size - pad_size; i++) {
        message[i] = 0x00;
    }

    uint32_t *word_array = (uint32_t*)(message + message_size - 64);
    memset(word_array, 0, 64);
    memcpy(word_array, &total_len, 4);

    uint32_t a, b, c, d, e, f, g, h, temp1, temp2, t;
    uint32_t H[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19};
    uint32_t K[64] = {
        0x428a2f98,
        0x71374491,
        0xb5c0fbcf,
        0xe9b5dba5,
        0x3956c25b,
        0x59f111f1,
        0x923f82a4,
        0xab1c5ed5,
        0xd807aa98,
        0x12835b01,
        0x243185be,
        0x550c7dc3,
        0x72be5d74,
        0x80deb1fe,
        0x9bdc06a7,
        0xc19bf174,
        0xe49b69c1,
        0xefbe4786,
        0x0fc19dc6,
        0x240ca1cc,
        0x2de92c6f,
        0x4a7484aa,
        0x5cb0a9dc,
        0x76f988da,
        0x983e5152,
        0xa831c66d,
        0xb00327c8,
        0xbf597fc7,
        0xc6e00bf3,
        0xd5a79147,
        0x06ca6351,
        0x14292967,
        0x27b70a85,
        0x2e1b2138,
        0x4d2c6dfc,
        0x53380d13,
        0x650a7354,
        0x766a0abb,
        0x81c2c92e,
        0x92722c85,
        0xa2bfe8a1,
        0xa81a664b,
        0xc24b8b70,
        0xc76c51a3,
        0xd192e819,
        0xd6990624,
        0xf40e3585,
        0x106aa070,
        0x19a4c116,
        0x1e376c08,
        0x2748774c,
        0x34b0bcb5,
        0x391c0cb3,
        0x4ed8aa4a,
        0x5b9cca4f,
        0x682e6ff3,
        0x748f82ee,
        0x78a5636f,
        0x84c87814,
        0x8cc70208,
        0x90befffa,
        0xa4506ceb,
        0xbef9a3f7,
        0xc67178f2
    };

    uint32_t M[16];

    for(int i = 0; i < message_size / 64; i++) {

        memcpy(M, message + (i * 64), 64);

        for(int j = 16; j < 64; j++) {
            uint32_t s0 = (M[j-15] >> 7) | (M[j-15] << 25);
            s0 ^= ((M[j-15] >> 18) | (M[j-15] << 14)) ^ (M[j-15] >> 3);

            uint32_t s1 = (M[j-2] >> 17) | (M[j-2] << 15);
            s1 ^= ((M[j-2] >> 19) | (M[j-2] << 13)) ^ (M[j-2] >> 10);

            M[j] = M[j-16] + s0 + M[j-7] + s1;
        }

        a = H[0]; b = H[1]; c = H[2]; d = H[3];
        e = H[4]; f = H[5]; g = H[6]; h = H[7];

        for(int j = 0; j < 64; j++) {

            uint32_t s1 = (e >> 6) | (e << 26);
            s1 ^= ((e >> 11) | (e << 21)) ^ ((e >> 25) | (e << 7));

            t = h + s1 + ((e & f) ^ ((~e) & g)) + K[j] + M[j];

            uint32_t s0 = (a >> 2) | (a << 30);
            s0 ^= ((a >> 13) | (a << 19)) ^ ((a >> 22) | (a << 10));

            temp1 = s0 + ((a & b) ^ (a & c) ^ (b & c));
            temp2 = ((~a) & (d)) ^ ((b) & (c));
            t += temp1 + temp2;

            h = g;
            g = f;
            f = e;
            e = d + t;
            d = c;
            c = b;
            b = a;
            a = t + temp1;
        }

        H[0] += a; H[1] += b; H[2] += c; H[3] += d;
        H[4] += e; H[5] += f; H[6] += g; H[7] += h;
    }

    output[0] = (H[0] >> 24) & 0xff;
    output[1] = (H[0] >> 16) & 0xff;
    output[2] = (H[0] >> 8) & 0xff;
    output[3] = H[0] & 0xff;

    output[4] = (H[1] >> 24) & 0xff;
    output[5] = (H[1] >> 16) & 0xff;
    output[6] = (H[1] >> 8) & 0xff;
    output[7] = H[1] & 0xff;

    output[8] = (H[2] >> 24) & 0xff;
    output[9] = (H[2] >> 16) & 0xff;
    output[10] = (H[2] >> 8) & 0xff;
    output[11] = H[2] & 0xff;

    output[12] = (H[3] >> 24) & 0xff;
    output[13] = (H[3] >> 16) & 0xff;
    output[14] = (H[3] >> 8) & 0xff;
    output[15] = H[3] & 0xff;

    output[16] = (H[4] >> 24) & 0xff;
    output[17] = (H[4] >> 16) & 0xff;
    output[18] = (H[4] >> 8) & 0xff;
    output[19] = H[4] & 0xff;

    output[20] = (H[5] >> 24) & 0xff;
    output[21] = (H[5] >> 16) & 0xff;
    output[22] = (H[5] >> 8) & 0xff;
    output[23] = H[5] & 0xff;

    output[24] = (H[6] >> 24) & 0xff;
    output[25] = (H[6] >> 16) & 0xff;
    output[26] = (H[6] >> 8) & 0xff;
    output[27] = H[6] & 0xff;

    output[28] = (H[7] >> 24) & 0xff;
    output[29] = (H[7] >> 16) & 0xff;
    output[30] = (H[7] >> 8) & 0xff;
    output[31] = H[7] & 0xff;

}

int main()
{
    char *input = "Hello, world!";
    uint8_t output[32];

    sha256(input, strlen(input), output);

    char hex[65];
    for(int i = 0; i < 32; i++) {
        sprintf(hex + (i * 2), "%02x", output[i]);
    }
    hex[64] = 0;

    printf("Input text: %s\n", input);
    printf("Hash (SHA256): %s\n", hex);

    return 0;
}