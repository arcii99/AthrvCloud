//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate custom cryptographic hash
unsigned int custom_hash(const char* str, int len)
{
    unsigned int hash = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        hash = hash * 31 + str[i]; // Our custom hash function uses an algorithm of multiplying by 31 and adding the ASCII value of each character
    }

    return hash; // We return the final hash value as an unsigned integer
}

int main()
{
    char input[100]; // We'll take input from the user to generate a hash for
    unsigned int hash; // This will hold the resulting hash value

    // Cheerful greeting to the user
    printf("Welcome to our custom cryptographic hash function program!\n");
    printf("Enter a string to generate a hash for: ");

    // We take input from the user
    fgets(input, 100, stdin);

    // We remove the newline character at the end of the input
    input[strcspn(input, "\n")] = 0;

    // We generate the hash value using our custom hash function
    hash = custom_hash(input, strlen(input));

    // We print the final hash value to the user
    printf("The hash value for \"%s\" is: %u\n", input, hash);

    // Cheerful goodbye to the user
    printf("Thanks for using our custom hash function!\n");

    return 0;
}