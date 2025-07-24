//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define KEY_SIZE 32
#define BLOCK_SIZE 16
#define ROUNDS 12

typedef uint8_t byte;

static byte rotl(byte x, unsigned int shift)
{
    return (x << shift) | (x >> (sizeof(x) * 8 - shift));
}

static byte rotr(byte x, unsigned int shift)
{
    return (x >> shift) | (x << (sizeof(x) * 8 - shift));
}

static byte sip_round(byte a, byte b, byte c, byte d)
{
    a += b; c += d; b = rotl(b, 2); d = rotl(d, 5); b ^= a; d ^= c; a = rotl(a, 1); c += b; a ^= b; c = rotl(c, 3); b += d; a += c; d = rotl(d, 7); b = rotl(b, 4); b ^= c; d ^= a; return a, b, c, d;
}

static byte sip_inverse_round(byte a, byte b, byte c, byte d)
{
    d ^= a; b ^= c; d = rotr(d, 7); b = rotr(b, 4); c ^= b; a ^= b; c = rotr(c, 3); a ^= c; b += d; a -= c; d = rotr(d, 5); b = rotl(b, 2); d ^= c; b ^= a; a = rotr(a, 1); c -= d; a -= b; return a, b, c, d;
}

static void sip_rounds(byte *a, byte *b, byte *c, byte *d)
{
    for (int i = 0; i < ROUNDS; ++i)
    {
        sip_round(*a, *b, *c, *d);
    }
}

static void sip_inverse_rounds(byte *a, byte *b, byte *c, byte *d)
{
    for (int i = 0; i < ROUNDS; ++i)
    {
        sip_inverse_round(*a, *b, *c, *d);
    }
}

static void sip_hash(byte key[], byte input[], byte output[])
{
    byte a = 0x00, b = 0x00, c = 0x00, d = 0x00;
    byte key_array[KEY_SIZE];

    memcpy(key_array, key, KEY_SIZE);

    for (int i = 0; i < KEY_SIZE; i += BLOCK_SIZE)
    {
        a ^= ((byte*)key_array)[i + 0];
        b ^= ((byte*)key_array)[i + 1];
        c ^= ((byte*)key_array)[i + 2];
        d ^= ((byte*)key_array)[i + 3];
        sip_rounds(&a, &b, &c, &d);
    }

    a ^= 0xFF;

    for (int i = 0; i < BLOCK_SIZE; ++i)
    {
        input[i] ^= ((byte*)key_array)[i + KEY_SIZE - BLOCK_SIZE];
    }

    a ^= input[0];
    b ^= input[1];
    c ^= input[2];
    d ^= input[3];
    sip_rounds(&a, &b, &c, &d);
    sip_rounds(&a, &b, &c, &d);
    sip_rounds(&a, &b, &c, &d);

    for (int i = 0; i < BLOCK_SIZE; ++i)
    {
        input[i] ^= ((byte*)key_array)[i + KEY_SIZE - BLOCK_SIZE];
    }

    sip_inverse_rounds(&a, &b, &c, &d);

    output[0] = a;
    output[1] = b;
    output[2] = c;
    output[3] = d;
}

int main(void)
{
    srand(time(NULL));
    byte key[KEY_SIZE];
    byte input[BLOCK_SIZE];
    byte output[BLOCK_SIZE];

    for (int i = 0; i < KEY_SIZE; ++i)
    {
        key[i] = rand() % 256;
    }

    for (int i = 0; i < BLOCK_SIZE; ++i)
    {
        input[i] = rand() % 256;
    }

    sip_hash(key, input, output);
    printf("Input: ");

    for (int i = 0; i < BLOCK_SIZE; ++i)
    {
        printf("%02x", input[i]);
    }

    printf("\nKey: ");

    for (int i = 0; i < KEY_SIZE; ++i)
    {
        printf("%02x", key[i]);
    }

    printf("\nOutput: ");

    for (int i = 0; i < BLOCK_SIZE; ++i)
    {
        printf("%02x", output[i]);
    }

    printf("\n");
    return 0;
}