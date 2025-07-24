//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

uint32_t ggT(uint32_t a, uint32_t b) {
    if (a == 0)
        return b;
    return ggT(b % a, a);
}

uint32_t hash(const char* data) {
    uint32_t h1 = 0xdeadbeef;
    uint32_t h2 = 0x1337c0de;
    uint32_t u = 0;

    size_t len = strlen(data);

    for (size_t i = 0; i < len; i++) {
        u = ggT(h1, h2);
        h1 = (ROTL(h1, 7) + u) ^ (data[i] + u);
        h2 = (ROTL(h2, 11) + u) ^ (data[i] - u);
    }

    return h1 ^ h2;
}

int main(void) {
    char* data = "Hello, World!";
    uint32_t result = hash(data);

    printf("The hash for '%s' is: %u\n", data, result);

    return EXIT_SUCCESS;
}