//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

int main()
{
    char originalString[MAX_SIZE], compressedString[MAX_SIZE];
    int count[MAX_SIZE], freq[MAX_SIZE];
    int i, j, k, length, compressedLength = 0, compressionRatio;

    printf("Enter the string to be compressed: ");
    gets(originalString);

    length = strlen(originalString);

    //ASCII range is from 0 to 127. So, initializing count array with 0.
    for(i = 0; i < 128; i++)
        count[i] = 0;

    //counting the frequency of each character
    for(i = 0; i < length; i++)
        count[(int)originalString[i]]++;

    k = 0;
    //generate compressed string
    for(i = 0; i < 128; i++)
    {
        if(count[i] != 0)
        {
            compressedString[k++] = (char)i;
            compressedString[k++] = (char)count[i];
        }
    }

    compressedLength = strlen(compressedString);

    //calculate compression ratio
    compressionRatio = (length - compressedLength) * 100 / length;

    printf("\nOriginal String: %s\n", originalString);
    printf("Compressed String: %s\n", compressedString);
    printf("Compression Ratio: %d percent\n", compressionRatio);

    return 0;
}