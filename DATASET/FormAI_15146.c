//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char input[MAX_SIZE], compressed[MAX_SIZE];
    int i, j, count;

    printf("Enter a string to compress: ");
    fgets(input, MAX_SIZE, stdin);

    printf("Original string: %s", input);

    // Initialize compressed string
    memset(compressed, '\0', sizeof(compressed));

    // Run Length Encoding algorithm
    i = 0;
    j = 0;
    while (input[i] != '\0')
    {
        count = 1;
        while (input[i] == input[i+1])
        {
            count++;
            i++;
        }

        compressed[j++] = count + '0';
        compressed[j++] = input[i];
        i++;
    }
    compressed[j] = '\0';

    printf("Compressed string: %s\n", compressed);

    return 0;
}