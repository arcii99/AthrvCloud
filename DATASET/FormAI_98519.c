//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Statistical Cryptographic Hash Function */

uint32_t statistical_hash(const char *str) {
    uint32_t hash = 5381;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        hash = ((hash << 5) + hash) + str[i];
    }

    return hash;
}

int main() {
    char str[] = "Hello, World!";
    uint32_t hash = statistical_hash(str);

    printf("The hash of \"%s\" is: %d\n", str, hash);

    return 0;
}