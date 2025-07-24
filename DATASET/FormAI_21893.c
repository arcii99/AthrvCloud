//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

int main()
{
    char str[MAX_WORD_LENGTH], words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS], count = 0;

    printf("Enter a string: ");
    fgets(str, MAX_WORD_LENGTH, stdin);

    char *token = strtok(str, " ");
    while (token != NULL)
    {
        int i = 0;
        while (token[i])
        {
            token[i] = tolower(token[i]);
            i++;
        }

        int flag = 0;
        for (int j = 0; j < count; j++)
        {
            if (strcmp(token, words[j]) == 0)
            {
                freq[j]++;
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            strcpy(words[count], token);
            freq[count] = 1;
            count++;
        }

        token = strtok(NULL, " ");
    }

    printf("\nWord\tFrequency\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\t%d\n", words[i], freq[i]);
    }

    return 0;
}