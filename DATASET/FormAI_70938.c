//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Brave style hash function */
static inline uint32_t brave_hash(char *str) {
    uint32_t hash = 0;
    uint32_t i;

    for (i = 0; i < strlen(str); ++i) {
        hash += str[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

int main(void) {
    char *input_string = "I am a brave chatbot!";
    uint32_t hash = brave_hash(input_string);

    printf("Input string: %s\n", input_string);
    printf("Hash: 0x%08x\n", hash);

    return 0;
}