//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ada Lovelace inspired cryptographic hash function
unsigned long ada_hash(char *input)
{
    unsigned long hash = 0;
    int i;

    for (i = 0; i < strlen(input); i++)
    {
        hash += (unsigned long)input[i];  // add each character's ASCII value to the hash
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

// test the hash function
int main()
{
    char input[] = "Ada Lovelace was the first computer programmer";
    unsigned long hash = ada_hash(input);
    printf("Hash value for '%s': %lu\n", input, hash);

    return 0;
}