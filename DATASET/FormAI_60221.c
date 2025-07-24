//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to generate a unique hash
unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main()
{
    char input[100];
    printf("Enter a string to hash: ");
    scanf("%s", input);

    // Generate the hash and print it
    unsigned long result = hash(input);
    printf("The hash of '%s' is: %lu\n", input, result);

    return 0;
}