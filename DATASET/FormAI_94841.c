//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function to compress the input string
void compress(char* input)
{
    // Initialize the compressed string
    char compressed[MAX_LEN] = "";

    // Get the length of the input string
    int len = strlen(input);

    // Initialize the counters
    int count = 1;
    int i = 0;
    int j = 0;

    // Loop through the input string
    while (i < len)
    {
        // Check if the next character is the same as the current one
        if (input[i] == input[i + 1])
        {
            // Increment the counter
            count++;
        }
        else
        {
            // Append the current character and the count to the compressed string
            sprintf(compressed + strlen(compressed), "%c%d", input[i], count);

            // Reset the counter
            count = 1;
        }

        // Increment the index
        i++;
    }

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);
}

int main()
{
    // Get the input string
    char input[MAX_LEN];
    printf("Enter the string to compress: ");
    fgets(input, MAX_LEN, stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = '\0';

    // Compress the input string
    compress(input);

    return 0;
}