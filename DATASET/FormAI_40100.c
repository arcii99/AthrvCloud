//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
/* 
A Unique C Compression Algorithm Example Program
- This program takes a string of characters as input and applies a lossless compression algorithm.
- It replaces the sequence of repeating characters with a number indicating the number of repetitions and the character that repeats.
- For example: "aaabbbccc" will be compressed to "3a3b3c"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000], output[1000];
    int count = 1;

    // Read input from user
    printf("Enter a string of characters to compress:\n");
    fgets(input, 1000, stdin);

    // Compress the input string
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == input[i+1])
        {
            count++;
        }
        else
        {
            // Add count and character to output string
            sprintf(output + strlen(output), "%d", count);
            sprintf(output + strlen(output), "%c", input[i]);
            count = 1;
        }
    }

    // Print the compressed result
    printf("The compressed string is: %s\n", output);

    return 0;
}