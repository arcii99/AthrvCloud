//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countWords(char *str);

int main()
{
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, 100, stdin);
    countWords(str);
    return 0;
}

void countWords(char *str)
{
    int count = 0;
    char words[100][100];
    char *token = strtok(str, " ,.!?");

    while (token != NULL)
    {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " ,.!?");
    }

    for (int i = 0; i < count; i++)
    {
        int wordCount = 1;

        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                wordCount++;
                strcpy(words[j], "");
            }
        }

        if (strcmp(words[i], "") != 0)
        {
            printf("%s: %d\n", words[i], wordCount);
        }
    }
}