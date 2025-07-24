//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROTATE_LEFT(x, n) (((x) << n) | ((x) >> (32 - n)))

unsigned int cheerful_hash(const char *input_str)
{
    unsigned int hash_value = 0;
    unsigned int i = 0;

    for (i = 0; i < strlen(input_str); i++)
    {
        hash_value = hash_value + (input_str[i] * i);
        hash_value = ROTATE_LEFT(hash_value, 7);
    }

    return hash_value;
}

int main()
{
    char input[100];
    unsigned int hash;

    printf("\nWelcome to the Cheerful Hash Function! Let's create some hashes today!\n\n");
    printf("Please enter a string to be hashed (without spaces) : ");
    fgets(input, sizeof(input), stdin);

    hash = cheerful_hash(input);

    printf("\nOh boy, we created a cheerful hash!\n");
    printf("The hash value for '%s' is: %u\n\n", input, hash);

    return 0;
}