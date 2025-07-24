//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROTATION(a, b) (((a) << (b)) | ((a) >> (32-(b))))

// Function to create a cryptographic hash of string using SHA-256 algorithm
void sha256(char *str, unsigned char hash[32]) {
    unsigned int h[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };  // initial hash constants
    
    unsigned int k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };  // message schedule constants
    
    // Generate message schedule from string
    unsigned int w[64];
    for (int i = 0; i < 16; i++) {
        int j = i * 4;
        w[i] = (str[j] << 24) | (str[j+1] << 16) | (str[j+2] << 8) | str[j+3];
    }
    for (int i = 16; i < 64; i++) {
        unsigned int s0 = ROTATION(w[i-15], 7) ^ ROTATION(w[i-15], 18) ^ (w[i-15] >> 3);
        unsigned int s1 = ROTATION(w[i-2], 17) ^ ROTATION(w[i-2], 19) ^ (w[i-2] >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }
    
    // Compression function
    unsigned int a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h2 = h[7];
    for (int i = 0; i < 64; i++) {
        unsigned int S1 = ROTATION(e, 6) ^ ROTATION(e, 11) ^ ROTATION(e, 25);
        unsigned int ch = (e & f) ^ (~e & g);
        unsigned int temp1 = h2 + S1 + ch + k[i] + w[i];
        unsigned int S0 = ROTATION(a, 2) ^ ROTATION(a, 13) ^ ROTATION(a, 22);
        unsigned int maj = (a & b) ^ (a & c) ^ (b & c);
        unsigned int temp2 = S0 + maj;
        h2 = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }
    
    // Update hash values
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
    h[5] += f;
    h[6] += g;
    h[7] += h2;
    
    // Convert hash values to byte array
    for (int i = 0; i < 4; i++) {
        hash[i] = h[0] >> (24 - (8*i));
        hash[i+4] = h[1] >> (24 - (8*i));
        hash[i+8] = h[2] >> (24 - (8*i));
        hash[i+12] = h[3] >> (24 - (8*i));
        hash[i+16] = h[4] >> (24 - (8*i));
        hash[i+20] = h[5] >> (24 - (8*i));
        hash[i+24] = h[6] >> (24 - (8*i));
        hash[i+28] = h[7] >> (24 - (8*i));
    }
}

int main() {
    char str[100];
    printf("Enter string to hash: ");
    fgets(str, 100, stdin);
    int len = strlen(str) - 1;  // exclude newline character
    
    // Padding bytes
    int pad_len = 64 - ((len + 8) % 64);
    if (pad_len < 8) pad_len += 64;
    unsigned char pad[pad_len];
    memset(pad, 0, pad_len);
    pad[0] = 0x80;
    unsigned long long bit_len = len * 8;
    for (int i = 0; i < 8; i++) {
        pad[pad_len-8+i] = (bit_len >> (56 - 8*i)) & 0xff;
    }
    
    // Append padding bytes and calculate hash
    unsigned char hash[32];
    sha256(str, hash);
    sha256(pad, hash);
    
    // Print hash in hexadecimal representation
    printf("Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    return 0;
}