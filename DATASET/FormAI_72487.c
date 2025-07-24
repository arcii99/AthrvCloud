//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main()
{
    char c;
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int count[MAX_WORD_LENGTH] = {0};

    while ((c = getchar()) != EOF)
    {
        if (isspace(c) || ispunct(c))
        {
            if (word_count > 0)
            {
                count[word_count]++;
                word_count = 0;
            }
        }
        else
        {
            if (word_count < MAX_WORD_LENGTH - 1)
            {
                word[word_count++] = tolower(c);
            }
        }
    }

    printf("%10s %s\n", "Word", "Frequency");
    for (int i = 1; i < MAX_WORD_LENGTH; ++i)
    {
        if (count[i] > 0)
        {
            printf("%10d %d\n", i, count[i]);
        }
    }

    return 0;
}