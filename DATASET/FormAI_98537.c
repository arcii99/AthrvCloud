//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//Defining the hash function
uint32_t crypt_hash_func(const void *input, size_t len, uint32_t seed){
    const uint8_t *data = (const uint8_t *)input;
    uint32_t hash = seed, mix;

    //Defining the magic mix numbers
    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;
    const uint32_t r1 = 15;
    const uint32_t r2 = 13;
    const uint32_t m = 5;
    const uint32_t n = 0xe6546b64;

    //Looping through the data stream for the hashing
    while(len >= 4){
        mix = *(uint32_t *)data;
        mix *= c1;
        mix = (mix << r1) | (mix >> (32 - r1));
        mix *= c2;

        hash ^= mix;
        hash = ((hash << r2) | (hash >> (32 - r2))) * m + n;

        data += 4;
        len -= 4;
    }

    //Hashing the remaining bytes in data stream
    mix = 0;
    switch(len){
        case 3: mix ^= data[2] << 16;
        case 2: mix ^= data[1] << 8;
        case 1: mix ^= data[0];
            mix *= c1;
            mix = (mix << r1) | (mix >> (32 - r1));
            mix *= c2;
            hash ^= mix;
            break;
    }

    //Finalizing the hash value with some magic mixing
    hash ^= strlen(input);
    hash ^= (hash >> 16);
    hash *= 0x85ebca6b;
    hash ^= (hash >> 13);
    hash *= 0xc2b2ae35;
    hash ^= (hash >> 16);

    //Returning the hashed value
    return hash;
}

int main(){
    //Calling the hash function and passing a test string
    char *test_str = "Hello, world!";
    uint32_t hashed_val = crypt_hash_func(test_str, strlen(test_str), 0);

    //Printing the hashed value
    printf("Hashed value of '%s' is %u\n", test_str, hashed_val);

    return 0;
}