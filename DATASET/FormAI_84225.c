//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100 /* size of the input buffer */

int main()
{
    /* initialise variables */
    char input_buffer[BUFFER_SIZE];
    char compressed_buffer[BUFFER_SIZE];
    int input_length = 0;
    int compressed_length = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    char current_char = '\0';
    int current_count = 0;

    /* get user input and calculate input length */
    printf("Please enter the text you would like to compress: ");
    fgets(input_buffer, BUFFER_SIZE, stdin);
    while (input_buffer[input_length] != '\0')
    {
        input_length++;
    }

    /* compress input text */
    for (i = 0; i < input_length; i++)
    {
        current_char = input_buffer[i];
        current_count = 1;
        for (j = i + 1; j < input_length; j++)
        {
            if (input_buffer[j] == current_char)
            {
                current_count++;
            }
            else
            {
                break;
            }
        }
        if (current_count > 1)
        {
            compressed_buffer[compressed_length++] = current_char;
            compressed_buffer[compressed_length++] = current_count + '0';
            i = j - 1;
        }
        else 
        {
            compressed_buffer[compressed_length++] = current_char;
        }
    }

    /* print compressed text */
    printf("The compressed text is: ");
    for (i = 0; i < compressed_length; i++)
    {
        printf("%c", compressed_buffer[i]);
    }
    printf("\n");

    return 0;
}