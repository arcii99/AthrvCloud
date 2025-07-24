//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <string.h>

// function to compress a string using run-length encoding
void compress(char* str)
{
    int len = strlen(str);

    // traverse the string from left to right
    int i = 0;
    while (i < len) 
    {
        // count the number of consecutive occurrences of the current character
        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1])
            count++, i++;

        // if there is only one occurrence of the current character, print it as is
        if (count == 1)
            printf("%c", str[i]);

        // else print the count followed by the current character
        else
            printf("%d%c", count, str[i]);

        // move to the next character
        i++;
    }
}

int main()
{
    char str[100];
    printf("Enter a string to compress: ");
    scanf("%[^\n]s", str);

    printf("Compressed string: ");
    compress(str);

    return 0;
}