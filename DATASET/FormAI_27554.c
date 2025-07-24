//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long hash(const char *str)
{
    unsigned long long hash = 0;
    int c;

    while(c = *str++)
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main()
{
    char text[100];

    printf("Enter text to hash: ");
    fgets(text, 100, stdin);

    unsigned long long hashedValue = hash(text);

    printf("Hashed value for the entered text is: %llu\n", hashedValue);

    return 0;
}