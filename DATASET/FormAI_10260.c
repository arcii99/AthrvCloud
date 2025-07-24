//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: curious
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// implementation of a curious cryptographic hash function

uint32_t hash(char* input) {
    uint32_t len = strlen(input);
    uint32_t* ptr = (uint32_t*)input;
    uint32_t hash = 0;

    for (uint32_t i = 0; i < len / 4; i++) {
        hash ^= ptr[i];
        hash *= 0x12345679;
        hash += 0x1337;
        hash &= 0xFFFFFFFF;
    }

    uint32_t remaining_bytes = len % 4;
    uint32_t last = 0;
    memcpy(&last, input + len - remaining_bytes, remaining_bytes);
    hash ^= last;
    hash *= 0x12345679;
    hash += 0x1337;
    hash &= 0xFFFFFFFF;

    return hash;
}

int main() {
    char input[] = "A curious mind is a powerful tool";
    uint32_t hash_val = hash(input);

    printf("Input: %s\n", input);
    printf("Hash value: %u\n", hash_val);

    return 0;
}