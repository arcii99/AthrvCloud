//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants used in the hash function
#define PRIME 5381
#define MODULO 1000000007

unsigned int hash(const char* str) {
    unsigned int result = PRIME;
    int len = strlen(str);

    // Iterate through every character in the string to compute the hash
    for (int i = 0; i < len; i++) {
        // Compute the contribution of the current character to the hash
        int contribution = str[i] * pow(PRIME, len - i);

        // Add the contribution to the result
        result = (result + contribution) % MODULO;
    }

    return result;
}

int main() {
    char* input = calloc(256, sizeof(char));
    printf("Enter a string to hash: ");
    scanf("%s", input);

    unsigned int hashed_input = hash(input);
    printf("The hash of \"%s\" is %u\n", input, hashed_input);

    free(input);
    return 0;
}