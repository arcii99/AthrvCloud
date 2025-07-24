//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* This is a custom cryptographic hash function in C.
   It uses a combination of bitwise operations and modular arithmetic
   to generate a unique hash for any given input string. */

uint32_t custom_hash(const char *str) {
    uint32_t hash = 5381;
    int c;

    while ((c = *str++) != 0) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input string>\n", argv[0]);
        return 1;
    }

    char *input_str = argv[1];
    uint32_t hash = custom_hash(input_str);

    printf("Input string: %s\n", input_str);
    printf("Hash value: %u\n", hash);

    return 0;
}