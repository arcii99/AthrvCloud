//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the hash function
uint32_t myHash(char* data, uint32_t length) {
    uint32_t hash = 5381;
    uint32_t i;

    for (i = 0; i < length; i++) {
        hash = ((hash << 5) + hash) + (uint32_t)data[i];
    }

    return hash;
}

// main function
int main() {
    char input[100];

    // Read the input string
    printf("Enter a string to hash: ");
    scanf("%s", input);

    // Compute the hash of the input string
    uint32_t hash = myHash(input, strlen(input));
    printf("The hash of \"%s\" is 0x%08X\n", input, hash);

    return 0;
}