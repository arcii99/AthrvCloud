//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char data[MAX_LEN];
    char reversed[MAX_LEN];
    int i, j, len;

    printf("Type something: ");
    fgets(data, MAX_LEN, stdin);

    len = strlen(data) - 1;
    j = 0;

    for (i = len - 1; i >= 0; i--)
    {
        reversed[j++] = data[i];
    }
    reversed[j] = '\0';

    printf("Reversed string: %s\n", reversed);

    // Count vowels
    int count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (data[i] == vowels[j])
            {
                count++;
                break;
            }
        }
    }
    printf("Number of vowels in the string: %d\n", count);

    // Count words
    int words = 1;
    for (i = 0; i < len; i++)
    {
        if (data[i] == ' ')
        {
            words++;
        }
    }
    printf("Number of words in the string: %d\n", words);

    return 0;
}