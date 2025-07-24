//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

int main()
{
    char input[MAX_INPUT_SIZE];
    int checksum = 0, length, i, j;

    printf("Enter input string: ");

    fgets(input, MAX_INPUT_SIZE, stdin);
    length = strlen(input) - 1; // -1 to remove newline character

    printf("Input string is: %s", input);

    // First pass to add ASCII values
    for (i = 0; i < length; i++)
    {
        checksum += input[i];
    }

    // Second pass to add positional values
    for (i = 0; i < length; i++)
    {
        checksum += (i+1) * input[i];
    }

    // Display the checksum
    printf("Checksum: %d\n", checksum);

    return 0;
}