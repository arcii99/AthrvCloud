//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a configurable cryptographic hash function
// You can change the following values to customize the hash function
#define PRIME1 31
#define PRIME2 37
#define HASH_SIZE 256

int hash(char* str);

int main() {
    char* input = malloc(sizeof(char) * HASH_SIZE);
    printf("Enter a string to hash: ");
    fgets(input, HASH_SIZE, stdin);
    // Remove newline character
    input[strcspn(input, "\n")] = 0;
    int hashed_input = hash(input);
    printf("The hash of '%s' is: %d\n", input, hashed_input);
    free(input);
    return 0;
}

int hash(char* str) {
    int hash = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        hash += PRIME1 * PRIME2 * str[i];
    }
    return hash;
}