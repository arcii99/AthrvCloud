//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFFER_SIZE 1000

int main()
{
    char input[MAX_BUFFER_SIZE], output[MAX_BUFFER_SIZE];
    char compressed[MAX_BUFFER_SIZE];
    int count = 0, outputIdx = 0;

    printf("Enter input string: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);
    input[strlen(input) - 1] = '\0'; // remove '\n' character from input

    // Compress algorithm
    for(int i = 0; i < strlen(input); i++)
    {
        count++;
        if(input[i] != input[i+1])
        {
            // Store the compressed character in output array
            output[outputIdx++] = input[i];
            output[outputIdx++] = count + '0';
            count = 0; // reset count for new character
        }
    }
    output[outputIdx] = '\0';

    printf("Compressed output: %s\n", output);

    // Decompression algorithm
    int i = 0, j = 0;
    while(i < outputIdx)
    {
        compressed[j++] = output[i]; // Store the characters
        int n = output[i+1] - '0'; // Get the occurrence count
        for(int k = 0; k < n-1; k++)
            compressed[j++] = output[i]; // Again store the character
        i += 2; // Move to next compressed character
    }

    compressed[j] = '\0';

    printf("Decompressed output: %s\n", compressed);

    return 0;
}