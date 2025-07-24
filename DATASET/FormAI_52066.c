//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//Function to generate a Cryptographic hash using SHA-256 algorithm
void generateHash(char *string, uint8_t *hash, int length) {
    uint32_t H[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19}; //Initialize hash values

    uint32_t K[64] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 }; //Initialize K constants

    uint64_t bit_length = length * 8; //Get message length in bits
    uint8_t *padded_message = calloc(64, sizeof(uint8_t)); //Allocate memory for padded message
    memcpy(padded_message, string, length); //Copy message into padded buffer
    padded_message[length] = 0x80; //Append 1 bit to message
    int i = 55;
    while (bit_length > 0)
    {
        padded_message[i] = bit_length & 0xff;
        bit_length >>= 8;
        i--;
    }

    uint32_t words[64];
    uint32_t a, b, c, d, e, f, g, h, T1, T2;

    //Process message in 512-bit (64-byte) chunks
    for (int chunk = 0; chunk * 64 < length + 8; chunk++) {
        //Initialize message schedule
        for (int i = 0; i < 16; i++) {
            words[i] = (uint32_t)padded_message[chunk * 64 + i*4] << 24 |
                       (uint32_t)padded_message[chunk * 64 + i*4 + 1] << 16 |
                       (uint32_t)padded_message[chunk * 64 + i*4 + 2] << 8 |
                       (uint32_t)padded_message[chunk * 64 + i*4 + 3];
        }
        for (int i = 16; i < 64; i++) {
            words[i] = words[i-16] + words[i-7] + ((words[i-15] >> 7) | (words[i-15] << 25)) +
                       ((words[i-2] >> 17) | (words[i-2] << 15));
        }

        //Initialize working variables
        a = H[0]; b = H[1]; c = H[2]; d = H[3];
        e = H[4]; f = H[5]; g = H[6]; h = H[7];

        //Main loop
        for (int i = 0; i < 64; i++) {
            T1 = h + ((e >> 6) | (e << 26)) + ((e & f) ^ (~e & g)) + K[i] + words[i];
            T2 = ((a >> 2) | (a << 30)) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        //Update intermediate hash values
        H[0] += a; H[1] += b; H[2] += c; H[3] += d;
        H[4] += e; H[5] += f; H[6] += g; H[7] += h;
    }

    //Convert intermediate hash values to bytes
    for (int i = 0; i < 8; i++) {
        hash[i*4] = (uint8_t)(H[i] >> 24);
        hash[i*4+1] = (uint8_t)(H[i] >> 16);
        hash[i*4+2] = (uint8_t)(H[i] >> 8);
        hash[i*4+3] = (uint8_t)(H[i]);
    }

    free(padded_message); //Deallocate memory for padded message
}

int main() {
    char *string = "Hello, World!";
    uint8_t hash[32];
    generateHash(string, hash, strlen(string));

    printf("Input string: %s\n", string);
    printf("Hash value: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}