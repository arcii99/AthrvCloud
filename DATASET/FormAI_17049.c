//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress the input string 
void compress(char *input_string, char *compressed_string)
{
    int count = 1;
    int index = 0;
    int length = strlen(input_string);

    for (int i = 0; i < length; ++i)
    {
        // check if characters adjacent and count them 
        if (input_string[i] == input_string[i+1])
        {
            count++;
        }
        else
        {
            // add the compressed string
            compressed_string[index++] = input_string[i];
            compressed_string[index++] = count + '0';
            count = 1;
        }
    }
    compressed_string[index] = '\0';
}

int main()
{
    char input_string[100], compressed_string[100];

    printf("Enter the string to be compressed: ");
    scanf("%s", input_string);

    printf("Input string: %s\n", input_string);

    compress(input_string, compressed_string);

    printf("Compressed string: %s\n", compressed_string);

    return 0;
}