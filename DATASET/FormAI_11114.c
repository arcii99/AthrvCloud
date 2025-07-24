//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define ROTL(x,n) (((x)<<(n))|((x)>>(32-(n))))

uint32_t hash_fnv1a(const void *data, size_t size) {
    const uint8_t *bytes = (const uint8_t *) data;
    uint32_t hash = 2166136261u;
    size_t i;

    for (i = 0; i < size; i++) {
        hash ^= bytes[i];
        hash *= 16777619u;
    }

    return hash;
}

uint32_t hash_jenkins(const void *data, size_t size) {
    const uint8_t *bytes = (const uint8_t *) data;
    uint32_t a = 0xdeadbeefu + size;
    uint32_t b = a;
    uint32_t c = 0xdecadea5u;

    while (size > 12) {
        a += (bytes[0] + ((uint32_t) bytes[1] << 8) +
              ((uint32_t) bytes[2] << 16) + ((uint32_t) bytes[3] << 24));
        b += (bytes[4] + ((uint32_t) bytes[5] << 8) +
              ((uint32_t) bytes[6] << 16) + ((uint32_t) bytes[7] << 24));
        c += (bytes[8] + ((uint32_t) bytes[9] << 8) +
              ((uint32_t) bytes[10] << 16) + ((uint32_t) bytes[11] << 24));
        a -= c;  a ^= ROTL(c, 4);  c += b;
        b -= a;  b ^= ROTL(a, 6);  a += c;
        c -= b;  c ^= ROTL(b, 8);  b += a;
        a -= c;  a ^= ROTL(c,16);  c += b;
        b -= a;  b ^= ROTL(a,19);  a += c;
        c -= b;  c ^= ROTL(b, 4);  b += a;
        size -= 12;
        bytes += 12;
    }
    switch (size) {
        case 12: c += ((uint32_t) bytes[11] << 24);
        case 11: c += ((uint32_t) bytes[10] << 16);
        case 10: c += ((uint32_t) bytes[9] << 8);
        case 9: c += bytes[8];
        case 8: b += ((uint32_t) bytes[7] << 24);
        case 7: b += ((uint32_t) bytes[6] << 16);
        case 6: b += ((uint32_t) bytes[5] << 8);
        case 5: b += bytes[4];
        case 4: a += ((uint32_t) bytes[3] << 24);
        case 3: a += ((uint32_t) bytes[2] << 16);
        case 2: a += ((uint32_t) bytes[1] << 8);
        case 1: a += bytes[0];
    }
    c ^= b; c -= ROTL(b,14);
    a ^= c; a -= ROTL(c,11);
    b ^= a; b -= ROTL(a,25);
    c ^= b; c -= ROTL(b,16);
    a ^= c; a -= ROTL(c,4);
    b ^= a; b -= ROTL(a,14);
    c ^= b; c -= ROTL(b,24);
    return c;
}

int main(int argc, char *argv[]) {
    char *data = "Hello, world!";
    uint32_t fnv1a = hash_fnv1a(data, strlen(data));
    uint32_t jenkins = hash_jenkins(data, strlen(data));

    printf("fnv1a:    %08x\n", fnv1a);
    printf("jenkins:  %08x\n", jenkins);

    return EXIT_SUCCESS;
}