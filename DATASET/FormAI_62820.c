//FormAI DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODE_LENGTH 20

// Returns the compressed string
char *compress(char *input)
{
    char *output = (char*)malloc(sizeof(char) * CODE_LENGTH);
    strcpy(output, "");

    int length = strlen(input);
    int count = 1;

    for (int i = 0; i < length; i++)
    {
        if (input[i] == input[i + 1])
        {
            count++;
        }
        else
        {
            char temp[CODE_LENGTH];
            sprintf(temp, "%c%d", input[i], count);
            count = 1;
            strcat(output, temp);
        }
    }

    return output;
}

int main()
{
    char input[] = "hello world";

    char *compressed = compress(input);
    printf("Compressed: %s\n", compressed);

    free(compressed);

    return 0;
}