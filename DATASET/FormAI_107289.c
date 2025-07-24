//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTATION(x,n) (((x) << (n)) | ((x) >> (32-(n))))

uint32_t hash_function(const char* data, size_t size)
{
    uint32_t hash = 0;

    for (int i = 0; i < size; i++) {
        hash ^= ROTATION(data[i], i % 32);
    }

    return hash;
}

int main()
{
    char* input = "Hello, world!"; 
    size_t input_size = strlen(input); 

    uint32_t hash = hash_function(input, input_size);

    printf("Hash of \"%s\" is: %u\n", input, hash);
   
    return 0;
}