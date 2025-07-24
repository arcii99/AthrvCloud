//FormAI DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 255

typedef unsigned char byte;

int compress_data(byte *input_buffer, byte *output_buffer, int input_size)
{
    int i, j, output_index = 0;
    byte count = 1;

    for (i = 0; i < input_size; i++)
    {
        // If current byte is same as next byte, then increase the count
        while ((i + 1 < input_size) && (input_buffer[i] == input_buffer[i + 1]))
        {
            count++;
            i++;
        }

        // If count is greater than 1, then compress the data
        if (count > 1)
        {
            output_buffer[output_index++] = count;
            output_buffer[output_index++] = input_buffer[i];
        }
        else // If count is 1, then just copy the data
        {
            output_buffer[output_index++] = input_buffer[i];
        }

        count = 1; // Reset the count back to 1
    }

    return output_index;
}

int decompress_data(byte *input_buffer, byte *output_buffer, int input_size)
{
    int i, j, output_index = 0;

    for (i = 0; i < input_size;)
    {
        byte count = input_buffer[i++];

        // If count is greater than 1, then decompress the data
        if (count > 1)
        {
            byte data = input_buffer[i++];

            for (j = 0; j < count; j++)
            {
                output_buffer[output_index++] = data;
            }
        }
        else // If count is 1, then just copy the data
        {
            output_buffer[output_index++] = input_buffer[i++];
        }
    }

    return output_index;
}

int main()
{
    byte input_buffer[MAX_BUFFER_SIZE] = { 0 };
    byte output_buffer[MAX_BUFFER_SIZE] = { 0 };

    printf("Enter the input data: ");
    fgets(input_buffer, MAX_BUFFER_SIZE, stdin);

    int input_size = strlen(input_buffer) - 1; // Exclude the newline character

    int compressed_size = compress_data(input_buffer, output_buffer, input_size);
    printf("Compressed data: ");
    for (int i = 0; i < compressed_size; i++)
    {
        printf("%d ", output_buffer[i]);
    }

    int decompressed_size = decompress_data(output_buffer, input_buffer, compressed_size);
    input_buffer[decompressed_size] = '\0';
    printf("\nDecompressed data: %s\n", input_buffer);

    return 0;
}