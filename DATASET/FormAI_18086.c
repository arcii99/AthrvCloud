//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to implement RLE compression algorithm
void RLE_Compression(char *input_str, char *output_str)
{
    int length = strlen(input_str);
    int count = 1;

    for (int i = 0, j = 1; j <= length; i++, j++)
    {
        if (input_str[i] == input_str[j])
        {
            count++;
        }
        else
        {
            sprintf(output_str, "%s%c%d", output_str, input_str[i], count);
            count = 1;
        }
    }
}

int main()
{
    char input_str[100], output_str[100];

    printf("Enter the string to compress: ");
    scanf("%[^\n]s", input_str);

    RLE_Compression(input_str, output_str);

    printf("Original String: %s\n", input_str);
    printf("Compressed String: %s\n", output_str);

    return 0;
}