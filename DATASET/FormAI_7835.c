//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

/**
 * @brief    Returns the hash of a string using a unique cryptographic hash function.
 * 
 * @param    str    The string to hash.
 * @return          The hash value.
 */
int unique_hash(const char *str) {
    int hash = 0;
    
    for (int i = 0; i < strlen(str); i++) {
        hash = (hash * 31) + (int)str[i];
    }
    
    return hash % MAX_LENGTH;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to hash: ");
    scanf("%s", input);

    int hash = unique_hash(input);
    printf("\nThe hash of %s is %d.\n", input, hash);

    return 0;
}