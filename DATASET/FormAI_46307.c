//FormAI DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    char current_char;
    int current_len = 0;
    int output_len = 0;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    int len = strlen(input);
    input[len-1] = '\0'; // Removing newline character at the end

    for(int i=0; i<len; i++)
    {
        current_char = input[i];
        current_len++;

        if(input[i+1] != current_char)
        {
            output[output_len++] = current_char;
            output[output_len++] = current_len + '0';
            current_len = 0;
        }

        if(output_len >= MAX_SIZE-1)
        {
            printf("Output string exceeds maximum size. Compression failed!\n");
            return 1;
        }
    }

    output[output_len] = '\0';

    printf("Input string: %s\n", input);
    printf("Compressed string: %s\n", output);

    return 0;
}