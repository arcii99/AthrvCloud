//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t getModuloValue(uint32_t data, uint32_t modulo)
{
    return (data % modulo);
}

uint32_t hashFunction(uint32_t data, uint32_t salt, uint32_t modulo)
{
    uint32_t result = (data ^ salt) + (data * salt);
    return getModuloValue(result, modulo);
}

int main()
{
    char inputString[256];
    uint32_t salt = 123; // Random salt value to be used for hash function
    uint32_t modulo = 100000; // Modulo value to be used for hash function
    
    printf("Enter a string to hash: ");
    fgets(inputString, 256, stdin);
    inputString[strcspn(inputString, "\n")] = 0; // Remove the newline character
    
    uint32_t hashValue = 0;
    for(int i = 0; i < strlen(inputString); i++)
    {
        uint32_t characterValue = (uint32_t) inputString[i];
        hashValue += hashFunction(characterValue, salt, modulo);
    }
    
    printf("The hash value of '%s' is: %d\n", inputString, hashValue);
    
    return 0;
}