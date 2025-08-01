//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (~x & z);
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & ~z);
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | ~z);
}

void MD5(uint8_t *initial_msg, size_t initial_len, uint8_t *digest) {

    uint32_t h0, h1, h2, h3;
    uint8_t *msg = NULL;

    uint32_t *w = NULL;
    uint32_t a, b, c, d, i, f, g, temp;

    size_t new_len, offset;

    static uint32_t s[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                            5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
                            4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                            6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

    static uint32_t k[] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                            0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                            0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                            0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
                            0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
                            0xd62f105d, 0x2441453, 0xd8a1e681, 0xe7d3fbc8,
                            0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
                            0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
                            0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
                            0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
                            0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x4881d05,
                            0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
                            0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
                            0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
                            0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
                            0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

    new_len = (((initial_len + 8) / 64) + 1) * 64;
    msg = (uint8_t *)malloc(new_len);
    memset(msg, 0, new_len);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 128;
    offset = initial_len + 1;

    while (offset < new_len - 8) {
        *(uint64_t *)(msg + offset) = 0;
        offset += 8;
    }

    *(uint64_t *)(msg + offset) = (uint64_t)initial_len * 8;
    offset += 8;

    h0 = 0x67452301;
    h1 = 0xefcdab89;
    h2 = 0x98badcfe;
    h3 = 0x10325476;

    for (i = 0; i < new_len; i += 64) {

        a = h0;
        b = h1;
        c = h2;
        d = h3;

        w = (uint32_t *)(msg + i);

        for (uint32_t j = 0; j < 64; j++) {
            if (j < 16) {
                f = F(b, c, d);
                g = j;
            }
            else if (j < 32) {
                f = G(b, c, d);
                g = (5 * j + 1) % 16;
            }
            else if (j < 48) {
                f = H(b, c, d);
                g = (3 * j + 5) % 16;
            }
            else {
                f = I(b, c, d);
                g = (7 * j) % 16;
            }

            temp = d;
            d = c;
            c = b;
            b = b + ROTL((a + f + k[j] + w[g]), s[j]);
            a = temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    free(msg);

    memcpy(digest, &h0, sizeof(h0));
    memcpy(digest + 4, &h1, sizeof(h1));
    memcpy(digest + 8, &h2, sizeof(h2));
    memcpy(digest + 12, &h3, sizeof(h3));
}

int main() {
    char input[] = "Hello World!";
    uint8_t digest[16];

    MD5((uint8_t *)input, strlen(input), digest);

    printf("MD5 Hash of \"%s\":\n", input);
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}