//FormAI DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char originalString[1000], compressedString[1000], decompressedString[1000];
    int i, j = 0, count = 1, length, compressedLength;

    printf("Please enter a string to be compressed: ");
    scanf("%s", originalString);

    length = strlen(originalString);

    // Compression Algorithm
    for (i = 1; i <= length; i++)
    {
        if (originalString[i] == originalString[i - 1])
        {
            count++;
        }
        else
        {
            compressedString[j++] = originalString[i - 1];
            compressedString[j++] = count + '0';
            count = 1;
        }
    }

    compressedString[j] = '\0';
    compressedLength = strlen(compressedString);

    // Decompression Algorithm
    for (i = 0; i < compressedLength; i += 2)
    {
        int num = compressedString[i + 1] - '0';
        while(num--)
        {
            decompressedString[strlen(decompressedString)] = compressedString[i];
        }
    }

    decompressedString[strlen(decompressedString)] = '\0';

    printf("\nOriginal String: %s", originalString);
    printf("\nCompressed String: %s", compressedString);
    printf("\nDecompressed String: %s", decompressedString);

    return 0;
}