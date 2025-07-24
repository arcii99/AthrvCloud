//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORDS 1000

int main()
{
    int i, j, len, wordCount = 0;

    char text[MAX_WORDS], word[MAX_WORDS];

    int freq[MAX_WORDS];

    printf("Enter a string of text: ");

    fgets(text, MAX_WORDS, stdin);

    len = strlen(text);

    for(i = 0; i < len; i++)
    {
        if(text[i] == '\n')
        {
            text[i] = '\0';
            break;
        }
    }

    for(i = 0; i < len; i++)
    {
        if(text[i] == ' ' || text[i] == '\t' || text[i] == '\n')
        {
            word[j] = '\0';
            for(int k = 0; k < wordCount; k++)
            {
                if(strcmp(word, &text[freq[k]]) == 0)
                {
                    freq[k + 1]++;
                    break;
                }
                else if(k == (wordCount - 1))
                {
                    freq[wordCount] = i;
                    freq[wordCount + 1] = 1;
                    wordCount += 2;
                    break;
                }
            }
            j = 0;
        }
        else
        {
            word[j] = text[i];
            j++;
        }
    }

    printf("Word frequency count:\n");

    for(i = 0; i < wordCount; i += 2)
    {
        printf("%s - %d\n", &text[freq[i]], freq[i + 1]);
    }

    return 0;
}