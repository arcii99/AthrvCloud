//FormAI DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

char *compress(char *str)
{
    int count = 0, index = 0, len = strlen(str);
    char *compressedStr = (char *)malloc(sizeof(char) * (SIZE));
    if (compressedStr == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < len; i++)
    {
        count++;
        if (i + 1 == len || str[i] != str[i + 1])
        {
            compressedStr[index++] = str[i];
            compressedStr[index++] = count + 48;
            count = 0;
        }
        if (index >= SIZE - 2)
        {
            compressedStr[SIZE - 1] = '\0';
            return compressedStr;
        }
    }
    return compressedStr;
}

void main()
{
    char str[SIZE], *compressedStr;
    printf("Enter a string to compress: ");
    scanf("%[^\n]s", str);
    compressedStr = compress(str);
    printf("Compressed string: %s\n", compressedStr);
    free(compressedStr);
}