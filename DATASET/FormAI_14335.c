//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We'll call our compression algorithm the "Squishy Sardine"!
// It's not actually related to sardines in any way, but it's a catchy name.

int main()
{
    char original[100], compressed[100];
    printf("Please enter the string to be compressed:\n");
    fgets(original, 100, stdin);
    int length = strlen(original);

    printf("Compressing...\n");

    // First step of the Squishy Sardine algorithm is to remove all spaces
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if (original[i] != ' ')
        {
            compressed[index++] = original[i];
        }
    }
    compressed[index] = '\0'; // Add null terminator to compressed string

    // Next step is to replace all repeated characters with a single instance
    length = strlen(compressed);
    index = 0;
    for (int i = 0; i < length; i++)
    {
        compressed[index++] = compressed[i];
        while (compressed[i] == compressed[i+1])
        {
            i++;
        }
    }
    compressed[index] = '\0'; // Add null terminator again

    printf("The compressed string is:\n%s\n\n", compressed);

    // And just for fun, let's reverse the compression process and see if we can get the original string back:
    length = strlen(compressed);
    index = 0;
    char uncompressed[100];
    uncompressed[index] = compressed[index]; // Start with first character of compressed string
    for (int i = 1; i < length; i++)
    {
        if (compressed[i] != compressed[i-1])
        {
            uncompressed[++index] = compressed[i];
        }
    }
    uncompressed[++index] = '\0'; // Add null terminator one last time

    printf("Uncompressing...\n");
    printf("The uncompressed string is:\n%s\n", uncompressed);

    return 0;
}