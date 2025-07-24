//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: irregular
#include <stdio.h>
#include <string.h>

// Swap function for XOR hashing algorithm
void swap(char *a, char *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// XOR hashing algorithm
char* xor_hash(const char* str) {
    char* hash = (char*) malloc(32 * sizeof(char));
    memset(hash, 0, 32);
    int length = strlen(str);
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = 0; j < 32; j++) {
            char bit = (char) ((str[i] >> j) & 1);
            hash[j] ^= bit;
        }
    }
    return hash;
}

// Main function
int main() {
    printf("Welcome to my unique C hash function program!\n");
    printf("Please enter a string to hash: ");

    char input[256];
    fgets(input, 256, stdin);

    // Remove newline character from input
    if (input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';

    char* hash = xor_hash(input);

    printf("The hash of %s is: ", input);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i] & 0xff);
    }
    printf("\n");

    free(hash);
    return 0;
}