//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: retro
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long long quadword;

#define BUFFER_SIZE 1024

byte rot(byte value, word count) {
    return (value << count) | (value >> (8 - count));
}

byte sbox(byte value, word box[256]) {
    return box[value];
}

void swap(byte *a, byte *b) {
    byte temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(byte *state) {
    word index;
    word a, b;
    static word p = 0, q = 0;
    static word permutation[512];
    static word inv_per[512] = { 0 };
    static const word p_init = 0x9e3779b9;
    static const word q_init = 0xc6a4a793;
    static const word j_init = 10;
    static const word r_init = 0;

    if (r_init == 0) {
        for (index = 0; index < 256; ++index) {
            permutation[index] = index;
        }
        for (index = 0; index < 256; ++index) {
            swap(&permutation[index], &permutation[rand() & 0xff]);
        }
        for (index = 0; index < 256; ++index) {
            inv_per[permutation[index]] = index;
        }
        p = p_init;
        q = q_init;
    }

    for (index = 0; index < 256; ++index) {
        a = permutation[index];
        b = permutation[(index + 1) & 0xff];

        p = p + state[a];
        q = q + state[b];

        swap(&state[a], &state[b]);

        p = rot(p, 1);
        q = rot(q, 1);

        state[a] = sbox(state[a], permutation);
        state[b] = sbox(state[b], permutation);
    }
}

void xor_buffer(byte *buffer, byte * hash) {
    word index;
    for (index = 0; index < 32; ++index) {
        buffer[index] ^= hash[index];
    }
}

void expand_key(byte *key, byte *expanded) {
    word length;
    word index;
    word rot_index;
    word byte_index;
    byte value;
    byte carry;
    byte *end = expanded + 1024;
    word box[256] = { 0 };

    for (index = 0; index < 256; ++index) {
        box[index] = rand() & 0xff;
    }

    for (index = 0; index < 32; ++index) {
        expanded[index] = key[index];
    }

    length = 192;

    byte_index = 32;
    value = 0;
    carry = 0;

    while (byte_index < 1024) {
        for (index = 0; index < 32; ++index) {
            expanded[byte_index++] = value ^ key[index];
            value = key[index];
        }

        for (index = 0; index < 4 && byte_index < 1024; ++index) {
            rot_index = byte_index - 32;
            value = expanded[byte_index - 4];
            value ^= expanded[byte_index - 8];
            value ^= expanded[byte_index - 14];
            value ^= expanded[byte_index - 32];

            expanded[byte_index++] = sbox(value, box);
        }
    }

    shuffle(expanded);
}

void compress(byte *state, byte * message_block, byte * expanded) {
    static const word iv1 = 0xbb67ae85;
    static const word iv2 = 0x3c6ef372;
    static const word iv3 = 0xa54ff53a;
    static const word iv4 = 0x510e527f;

    quadword a = iv1;
    quadword b = iv2;
    quadword c = iv3;
    quadword d = iv4;

    quadword *message_block_quad = (quadword *) message_block;
    quadword *expanded_quad = (quadword *) expanded;
    word index;

    a ^= message_block_quad[0];
    b ^= message_block_quad[1];
    c ^= message_block_quad[2];
    d ^= message_block_quad[3];

    for (index = 0; index < 12; ++index) {
        a ^= b << 13;
        c ^= d << 13;
        b ^= a << 8;
        d ^= c << 8;
        a ^= c >> 13;
        b ^= d >> 13;
        c ^= a >> 8;
        d ^= b >> 8;
        a ^= expanded_quad[index * 4 + 0];
        b ^= expanded_quad[index * 4 + 1];
        c ^= expanded_quad[index * 4 + 2];
        d ^= expanded_quad[index * 4 + 3];
    }

    a ^= message_block_quad[1];
    b ^= message_block_quad[2];
    c ^= message_block_quad[3];
    d ^= message_block_quad[0];

    for (index = 0; index < 12; ++index) {
        a ^= b >> 13;
        c ^= d >> 13;
        b ^= a << 8;
        d ^= c << 8;
        a ^= c >> 13;
        b ^= d >> 13;
        c ^= a >> 8;
        d ^= b >> 8;
        a ^= expanded_quad[47 - index * 4];
        b ^= expanded_quad[46 - index * 4];
        c ^= expanded_quad[45 - index * 4];
        d ^= expanded_quad[44 - index * 4];
    }

    state[0] = a;
    state[1] = a >> 8;
    state[2] = a >> 16;
    state[3] = a >> 24;

    state[4] = b;
    state[5] = b >> 8;
    state[6] = b >> 16;
    state[7] = b >> 24;

    state[8] = c;
    state[9] = c >> 8;
    state[10] = c >> 16;
    state[11] = c >> 24;

    state[12] = d;
    state[13] = d >> 8;
    state[14] = d >> 16;
    state[15] = d >> 24;
}

void hash_buffer(byte *buffer, quadword length, byte * hash) {
    byte state[16] = { 0 };
    byte message_block[64] = { 0 };
    byte expanded[1024] = { 0 };
    quadword index;
    word remainder;
    word index2;
    word *length_ptr = (word *) &length;
    word box[256] = { 0 };

    for (index = 0; index < 256; ++index) {
        box[index] = rand() & 0xff;
    }

    expand_key(buffer, expanded);

    for (index = 0; index < 16; ++index) {
        state[index] = rand() & 0xff;
    }

    for (index = 0; index < length / 64; ++index) {
        memcpy(message_block, buffer + index * 64, 64);
        xor_buffer(message_block, state);
        compress(state, message_block, expanded);
    }

    remainder = length % 64;

    message_block[0] = 0x80;
    memcpy(message_block + 1, (buffer + index * 64), remainder);
    if (remainder >= 56) {
        xor_buffer(message_block, state);
        compress(state, message_block, expanded);
        memset(message_block, 0, 56);

    }

    length *= 8;
    memcpy(message_block + 56, length_ptr, 4);
    memcpy(message_block + 60, length_ptr + 1, 4);
    xor_buffer(message_block, state);
    compress(state, message_block, expanded);

    for (index = 0; index < 32; ++index) {
        hash[index] = sbox(state[index], box);
    }

    memset(expanded, 0, sizeof(expanded));
    memset(state, 0, sizeof(state));
    memset(message_block, 0, sizeof(message_block));
}

int main(int argc, const char **argv) {

    byte buffer[BUFFER_SIZE] = { 0 };
    byte hash[32] = { 0 };
    quadword bytes_read = 0;
    FILE *file;
    if (argc <= 1) {
        printf("Usage: hash file [file...]");
        return 1;
    }

    while (*++argv != NULL) {
        file = fopen(*argv, "rb");
        if (file == NULL) {
            printf("Error opening file %s", *argv);
            continue;
        }

        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
            hash_buffer(buffer, bytes_read, hash);
        }

        printf("File: %s", *argv);
        printf("Hash: ");
        for (int i = 0; i < 32; i++) {
            printf("%02x", hash[i]);
        }
        printf("\n\n");
        fclose(file);
    }

    return 0;
}