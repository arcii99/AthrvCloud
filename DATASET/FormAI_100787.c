//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n)))

void sha256(const char* message, uint32_t digest[]) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    
    uint32_t k[] = {
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
    
    uint32_t message_block[64];
    uint32_t workspace[64];
    uint32_t temp1, temp2;
    
    int message_len = strlen(message);
    int message_bits_len = message_len * 8;
    int pad_len = message_len % 64 < 56 ? 56 - (message_len % 64) : 120 - (message_len % 64);
    
    message_block[message_len] = 0x80;
    for(int i = 0; i < pad_len - 1; i++) {
        message_block[message_len + 1 + i] = 0;
    }
    message_block[56] = message_bits_len >> 24;
    message_block[57] = message_bits_len >> 16;
    message_block[58] = message_bits_len >> 8;
    message_block[59] = message_bits_len;
    
    for(int i = 0; i < (message_len + pad_len) / 64; i++) {
        memcpy(workspace, &message_block[i * 64], 64);
        for(int j = 16; j < 64; j++) {
            uint32_t s0 = ROTATE_LEFT(workspace[j - 15], 7) ^ ROTATE_LEFT(workspace[j - 15], 18) ^ (workspace[j - 15] >> 3);
            uint32_t s1 = ROTATE_LEFT(workspace[j - 2], 17) ^ ROTATE_LEFT(workspace[j - 2], 19) ^ (workspace[j - 2] >> 10);
            workspace[j] = workspace[j - 16] + s0 + workspace[j - 7] + s1;
        }
        
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h_i = h[7];
        for(int j = 0; j < 64; j++) {
            uint32_t t1 = h_i + (ROTATE_LEFT(e, 6) ^ ROTATE_LEFT(e, 11) ^ ROTATE_LEFT(e, 25)) + ((e & f) ^ ((~e) & g)) + k[j] + workspace[j];
            uint32_t t2 = (ROTATE_LEFT(a, 2) ^ ROTATE_LEFT(a, 13) ^ ROTATE_LEFT(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
            h_i = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_i;
    }
    
    for(int i = 0; i < 8; i++) {
        digest[i] = h[i];
    }
}

int main(int argc, char *argv[]) {
    char message[] = "Hello, world!";
    uint32_t digest[8];
    sha256(message, digest);
    
    for(int i = 0; i < 8; i++) {
        printf("%08x", digest[i]);
    }
    printf("\n");

    return 0;
}