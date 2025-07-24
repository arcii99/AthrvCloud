//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

uint32_t hash(const char *string) {
    uint32_t h = 0x8615DFAA; // Initialize hash value to a random value
    uint32_t k; //hash code for the current byte
    uint32_t i = 0;//iterator
    uint32_t len=strlen(string);//length of the input string
    while(i < len) {
        k = string[i];
        h ^= k;// XOR the hash and the current byte
        h = ROTATE_LEFT(h, 7);//rotate left by 7 bits
        h ^= 0xabcdef12;//XOR the hash and a random constant
        i++;
    }
    return h;//return the hash value
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s string\n", argv[0]); //instructions on how to use the program
        return 1;
    }
    char *input_string = argv[1];
    uint32_t hashed_value = hash(input_string);
    printf("The hash value of \"%s\" is 0x%08X\n", input_string, hashed_value); //print the hash value
    return 0;
}