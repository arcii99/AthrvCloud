//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter the input string: ");
    scanf("%[^\n]%*c", input);

    int len = strlen(input);
    char compressed[50] = "";
    int i = 0, count = 1, j = 0;

    while (i < len)
    {
        if (input[i] == input[i+1])
        {
            count++;
        }
        else
        {
            compressed[j] = input[i];
            char str[5];
            sprintf(str, "%d", count);
            strcat(compressed, str);
            j += strlen(str) + 1;
            count = 1;
        }
        i++;
    }
    compressed[j] = '\0';

    if (strlen(compressed) < strlen(input))
    {
        printf("Compressed string: %s\n", compressed);
    }
    else
    {
        printf("Compressed string is not shorter than original.\n");
    }

    return 0;
}