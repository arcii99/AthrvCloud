//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: relaxed
// Here's an example program for a custom cryptographic hash function in C

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// arbitrary constants for the hash function
const uint32_t prime = 0x01000193; //   16777619
const uint32_t seed  = 0x811C9DC5; // 2166136261

// custom hash function
uint32_t custom_hash(const char* input, const size_t len)
{
    uint32_t hash = seed;
    const char* end = input + len;

    while(input != end)
    {
        hash *= prime;
        hash ^= (uint32_t)*input++;
    }

    return hash;
}

int main()
{
    char* input = "Hello, world!";   // test input
    size_t len = strlen(input);     // get length of input

    uint32_t hash = custom_hash(input, len);

    printf("Hash of \"%s\" = %u\n", input, hash);

    return 0;
}