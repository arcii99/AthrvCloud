//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100] = "compress this string using my unique algorithm";
    char compressed[100];
    int i, j, k;
    int count = 1;

    // loop through each character in the input string
    for (i = 0, j = 0; i < strlen(input); i++)
    {
        // if the current character is the same as the next one, increment the count
        if (input[i] == input[i+1])
        {
            count++;
        }
        // otherwise, add the character and its count to the compressed string
        else
        {
            compressed[j] = input[i];
            j++;
            sprintf(compressed+j, "%d", count);
            while (compressed[j] != '\0')
            {
                j++;
            }
            count = 1;
        }
    }

    // add the null terminator to the end of the compressed string
    compressed[j] = '\0';

    printf("Compressed string: %s\n", compressed);

    return 0;
}