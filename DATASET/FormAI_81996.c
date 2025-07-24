//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countWords(char *str);

int main()
{
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    countWords(sentence);
    return 0;
}

void countWords(char *str)
{
    char *word;
    char delimiters[12] = {' ', ',', '.', '?', '!', ':', ';', '-', '(', ')', '\n'};
    int i, j, count;
    int wordCount = 0;
    int freqCount[50] = {0}; //array to store word frequencies
    int n = strlen(str);

    word = strtok(str, delimiters);

    while (word != NULL)
    {
        count = 1; //initialize count for current word
        j = 0;
        for (i = 0; i < n; i++)
        {
            if (toupper(word[j]) == toupper(str[i]))
            {
                j++;
                if (j == strlen(word))
                {
                    wordCount++;
                    freqCount[wordCount - 1] = count++; //store current count in array
                    j = 0;
                }
            }
            else
            {
                j = 0;
            }
        }

        word = strtok(NULL, delimiters);
    }

    printf("\nWord Frequency Table\n");

    for (i = 0; i < wordCount; i++)
    {
        printf("%-10s - %d\n", strtok(str, " "), freqCount[i]);
    }

    printf("\nTotal Words: %d", wordCount);
}