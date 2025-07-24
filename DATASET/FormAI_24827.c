//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 64
#define INIT_A 0x6a09e667
#define INIT_B 0xbb67ae85
#define INIT_C 0x3c6ef372
#define INIT_D 0xa54ff53a

typedef unsigned char BYTE;
typedef unsigned int WORD;

static WORD S[] = {
    7, 12, 17, 22,
    5,  9, 14, 20,
    4, 11, 16, 23,
    6, 10, 15, 21
};

static WORD T[] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

WORD leftrotate(WORD x, int c)
{
    return (x << c) | (x >> (32-c));
}

void md5(BYTE *initial_msg, size_t initial_len, WORD *hash) 
{
    BYTE *msg = NULL;
    int new_len, offset;
    WORD A, B, C, D, F, g, temp;

    A = INIT_A;
    B = INIT_B;
    C = INIT_C;
    D = INIT_D;

    new_len = ((((initial_len + 8) / BLOCK_SIZE) + 1) * BLOCK_SIZE) - 8;
    msg = (BYTE*)calloc(new_len + 64, 1);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 128;

    offset = initial_len + 1;
    while (offset != new_len) 
    {
        if (offset >= new_len - 8) 
        {
            break;
        }

        offset++;
    }

    *((WORD*)(msg + offset)) = initial_len * 8;
    *((WORD*)(msg + offset) + 1) = 0;

    for(int i=0; i < (new_len+64)/64; i++) 
    {
        WORD *M = (WORD*)(msg + i*64);

        for(int j=0; j<16; j++) 
        {
            M[j] = (M[j] >> 24) | ((M[j] >> 8) & 0x0000ff00) | ((M[j] << 8) & 0x00ff0000) | (M[j] << 24);
        }

        A = INIT_A;
        B = INIT_B;
        C = INIT_C;
        D = INIT_D;

        for(int j=0; j<64; j++) 
        {
            if(j < 16) 
            {
                F = (B & C) | (~B & D);
                g = j;
            } 
            else if(j < 32) 
            {
                F = (D & B) | (~D & C);
                g = (5*j + 1) % 16;
            } 
            else if (j < 48) 
            {
                F = B ^ C ^ D;
                g = (3*j + 5) % 16;
            } 
            else 
            {
                F = C ^ (B | ~D);
                g = (7*j) % 16;
            }

            temp = D;
            D = C;
            C = B;
            B = B + leftrotate((A + F + T[j] + M[g]), S[j]);
            A = temp;
        }

        A += INIT_A;
        B += INIT_B;
        C += INIT_C;
        D += INIT_D;
    }

    free(msg);

    hash[0] = A;
    hash[1] = B;
    hash[2] = C;
    hash[3] = D;
}

int main(int argc, char *argv[]) 
{
    WORD hash[4];
    char msg[] = "Some message to hash";
    md5((BYTE*)msg, strlen(msg), hash);

    printf("Hash: %#x %#x %#x %#x\n", hash[0], hash[1], hash[2], hash[3]);

    return 0;
}