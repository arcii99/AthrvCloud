//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t compute_hash(char *input, size_t len);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Invalid number of arguments: <input string>\n");
        exit(EXIT_FAILURE);
    }

    uint32_t hash = compute_hash(argv[1], strlen(argv[1]));
    printf("%u\n", hash);

    return 0;
}

uint32_t compute_hash(char *input, size_t len) {
    uint32_t hash = len;

    for (size_t i = 0; i < len; i++) {
        hash = ((hash << 5) ^ (hash >> 27)) ^ input[i];
    }

    return hash;
}