//FormAI DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER 2048

char* compress(char* input)
{
    char* output = (char*)malloc(sizeof(char) * MAX_BUFFER); // allocate memory for output buffer
    char curr;
    int count = 0, output_index = 0, input_index = 0;
    int input_length = strlen(input);

    while(input_index < input_length)
    {
        curr = input[input_index];
        count = 1;
        // count the consecutive similar characters
        while(count < 255 && input_index + count < input_length && input[input_index + count] == curr)
            count++;
        // if more than one repeated character
        if(count > 1)
        {
            output[output_index++] = (char)(count + 127); // add the count of repeated character
            output[output_index++] = curr; // add actual repeated character
        }
        // if character not repeated
        else
            output[output_index++] = curr; // add the character as it is
        input_index += count;
    }

    output[output_index++] = '\0'; // null terminate the output buffer
    return output;
}

int main()
{
    char input[MAX_BUFFER], *output;
    printf("Enter the string to compress: ");
    scanf("%[^\n]s", input);
    output = compress(input);
    printf("Compressed string: %s\n", output);
    free(output); // free the memory allocated for output buffer
    return 0;
}