//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long hash(const char *str) {
    unsigned long long h = 5381;
    int c;
    while ((c = *str++)) {
        h = ((h << 5) + h) ^ c;
    }
    return h;
}

int main() {
    const char *msg = "Hello, World!";
    unsigned long long h = hash(msg);
    printf("Hash value for \"%s\" is: %llu\n", msg, h);
    return 0;
}