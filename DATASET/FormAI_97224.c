//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>

unsigned int hash(char *str)
{
    unsigned int hash = 0;
    int c;

    while ((c = *str++))
    {
        hash += c;
    }

    return hash;
}

int main(void)
{
    char input[100];
    printf("Enter a string to hash:\n");

    if (fgets(input, 100, stdin) != NULL)
    {
        printf("Hash value: %u\n", hash(input));
    }

    return 0;
}