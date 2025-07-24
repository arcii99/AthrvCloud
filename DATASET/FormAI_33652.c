//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BLOCK_SIZE 64 // SHA-1 block size
#define RESULT_SIZE 20 // SHA-1 result size

// Rotate left operation for 32-bit words
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Swap operation for 32-bit words
#define SWAP(x) (((x) << 24) | (((x) << 8) & 0x00FF0000) | (((x) >> 8) & 0x0000FF00) | ((x) >> 24))

// SHA-1 constants
const unsigned int K[4] = {
    0x5A827999,
    0x6ED9EBA1,
    0x8F1BBCDC,
    0xCA62C1D6
};

// SHA-1 initial hash values
const unsigned int H[5] = {
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476,
    0xC3D2E1F0
};

// SHA-1 message scheduling function
void sha1_schedule(unsigned int* block, unsigned int* w) {
    int i;
    for (i = 0; i < 16; i++) {
        w[i] = SWAP(block[i]);
    }
    for (; i < 80; i++) {
        w[i] = ROTL(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);
    }
}

// SHA-1 compression function
void sha1_compress(unsigned int* h, unsigned int* w) {
    int i;
    unsigned int a, b, c, d, e, f, k, temp;
    unsigned int* x = (unsigned int*)malloc(80*sizeof(unsigned int));
    memcpy(x, h, 20);
    
    for (i = 0; i < 80; i++) {
        if (i < 20) {
            f = (b & c) | ((~b) & d);
            k = K[0];
        }
        else if (i < 40) {
            f = b ^ c ^ d;
            k = K[1];
        }
        else if (i < 60) {
            f = (b & c) | (b & d) | (c & d);
            k = K[2];
        }
        else {
            f = b ^ c ^ d;
            k = K[3];
        }
        temp = ROTL(a, 5) + f + e + k + w[i];
        e = d;
        d = c;
        c = ROTL(b, 30);
        b = a;
        a = temp;
    }
    
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;

    free(x);
}

// SHA-1 hash function
void sha1_hash(unsigned char* message, unsigned long long length, unsigned char* result) {
    int i, j;
    unsigned int h[5];
    unsigned char block[BLOCK_SIZE];
    unsigned int w[80];
    unsigned long long bit_len = length * 8;

    memcpy(h, H, 20);

    for (i = 0; i < length/BLOCK_SIZE; i++) {
        memcpy(block, message + i*BLOCK_SIZE, BLOCK_SIZE);
        sha1_schedule((unsigned int*)block, w);
        sha1_compress(h, w);
    }

    i *= BLOCK_SIZE;
    if (length % BLOCK_SIZE != 0) {
        memcpy(block, message + i, length % BLOCK_SIZE);
        block[length % BLOCK_SIZE] = 0x80;
        if (length % BLOCK_SIZE > 55) {
            sha1_schedule((unsigned int*)block, w);
            sha1_compress(h, w);
            memset(block, 0, BLOCK_SIZE);
        }
        *((unsigned long long*)(block + 56)) = bit_len;
        sha1_schedule((unsigned int*)block, w);
        sha1_compress(h, w);
    }

    for (i = 0, j = 0; i < 5; i++) {
        result[j++] = h[i] >> 24;
        result[j++] = h[i] >> 16;
        result[j++] = h[i] >> 8;
        result[j++] = h[i];
    }
}

// Main function
int main() {
    char message[1024];
    unsigned char result[RESULT_SIZE];
    int i;

    printf("Enter message: ");
    fgets(message, 1024, stdin);
    message[strcspn(message, "\n")] = 0;

    sha1_hash((unsigned char*)message, strlen(message), result);

    printf("SHA-1 hash of \"%s\": ", message);
    for (i = 0; i < RESULT_SIZE; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");

    return 0;
}