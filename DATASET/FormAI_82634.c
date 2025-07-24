//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* The core function */
uint32_t hash(const char *message) {
    uint32_t h = 0;
    while (*message) {
        h = (h << 4) + (uint32_t)(*message++);
        if ((h & 0xf0000000) != 0) {
            h ^= (h >> 24);
            h &= 0x0fffffff;
        }
    }
    return h;
}

/* Helper functions; these are not required for the hash function */
void print_hash(const char *message) {
    uint32_t h = hash(message);
    printf("Message: %s\n", message);
    printf("Hash: %08x\n", h);
}

int main(void) {
    print_hash("Hello, world!");
    print_hash("The quick brown fox jumps over the lazy dog");
    print_hash("Lorem ipsum dolor sit amet");
    return 0;
}