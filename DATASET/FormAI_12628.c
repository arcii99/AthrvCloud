//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[1000];
    int count[26] = {0}, i, len, ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        ch = tolower(str[i]) - 'a';

        if(ch >= 0 && ch < 26)
        {
            count[ch]++;
        }
    }

    printf("\nFrequency of each unique character:\n");
    printf("-----------------------------------\n");

    for(i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            printf("'%c' - %d\n", i + 'a', count[i]);
        }
    }

    printf("-----------------------------------\n");

    return 0;
}