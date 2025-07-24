//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a sample C compression algorithm using a basic form of run length encoding

char* compress(char* data)
{
    char* output = (char*)malloc(strlen(data) * sizeof(char));
    int count = 1;
    char temp[10] = "";
    int j = 0;

    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == data[i + 1])
        {
            count++;
        }
        else
        {
            sprintf(temp, "%d%c", count, data[i]);
            strcat(output, temp);
            j += strlen(temp);
            count = 1;
        }
    }

    output[j] = '\0';

    return output;
}

int main()
{
    char data[100];
    char* compressed;

    printf("Enter data to compress: ");
    fgets(data, sizeof(data), stdin);

    compressed = compress(data);

    printf("Compressed data: %s\n", compressed);

    free(compressed);

    return 0;
}