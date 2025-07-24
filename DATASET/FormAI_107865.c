//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
int freq[MAX_NUM_WORDS];
int num_words = 0;

void add_word(char *word)
{
    int i;
    for (i = 0; i < num_words; i++)
    {
        if (strcmp(words[i], word) == 0)
        {
            freq[i]++;
            return;
        }
    }
    strcpy(words[num_words], word);
    freq[num_words] = 1;
    num_words++;
}

void process_line(char *line)
{
    char *word;
    int i, j;
    for (i = 0; line[i]; i++)
    {
        if (ispunct(line[i]))
            line[i] = ' ';
        else
            line[i] = tolower(line[i]);
    }

    word = strtok(line, " ");
    while (word != NULL)
    {
        if (strlen(word) >= MAX_WORD_LENGTH)
        {
            printf("Too long word: %s", word);
        }
        else
        {
            add_word(word);
        }
        word = strtok(NULL, " ");
    }
}

int main()
{
    char line[1000];
    int i, j, k;

    while (fgets(line, sizeof(line), stdin))
    {
        process_line(line);
    }

    printf("Word frequency count:\n");
    for (i = 0; i < num_words; i++)
    {
        printf("\'%s\' : %d\n", words[i], freq[i]);
    }

    printf("Paranoid check:\n");
    int sum = 0;
    for (i = 0; i < num_words; i++)
    {
        sum += freq[i];
    }
    if (sum == 0)
    {
        printf("The frequency count is zero. Is there a problem with the program?\n");
    }
    else if (sum > MAX_NUM_WORDS)
    {
        printf("The total number of words counted (%d) is more than the maximum limit (%d). Is the program being used for malicious purposes?\n", sum, MAX_NUM_WORDS);
    }
    else
    {
        for (i = 0; i < num_words; i++)
        {
            if (freq[i] > sum)
            {
                printf("The frequency of word \'%s\' (%d) is greater than the total number of words counted (%d). Is the program being used for malicious purposes?\n", words[i], freq[i], sum);
            }
        }
    }

    return 0;
}