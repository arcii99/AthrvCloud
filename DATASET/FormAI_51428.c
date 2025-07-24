//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE unsigned char
#define WORD unsigned int

// Constants for Ken Thompson style hash function
#define FIBPRIME 11400862456688148481ull
#define GOLDENRATIO 0x9e3779b97f4a7c15ull
#define XORSHIFT(X, SHF) ((X^(X>>SHF)))

// Main Ken Thompson-style hash function
WORD ken_thompson_hash(BYTE *str, size_t len) {
    WORD hash = (len * FIBPRIME);

    for(size_t i = 0; i < len; i++) {
        hash ^= XORSHIFT(str[i] * FIBPRIME, 17) * GOLDENRATIO;
        hash = XORSHIFT(hash, 13) * FIBPRIME;
    }

    return hash;
}

int main() {
    char str[] = "This is an example Ken Thompson-style hash function program";
    size_t len = strlen(str);
    WORD hash = ken_thompson_hash(str, len);

    printf("Original string: %s\n", str);
    printf("Hash value: %u\n", hash);

    return 0;
}