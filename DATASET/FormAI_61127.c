//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: funny
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 100

int main()
{
    char sentence[500] = "Can cows climb cliffs? Cows can't climb cliffs! Crazy cows...";
    char* words[MAX_WORDS] = { NULL };
    int frequency[MAX_WORDS] = { 0 };
    char* token;
    const char sep[] = " ,.?!"; // delimiter characters

    /* Split sentence into array of words */
    token = strtok(sentence, sep);
    int word_count = 0;
    while (token != NULL && word_count < MAX_WORDS)
    {
        words[word_count++] = token; // add word to array
        token = strtok(NULL, sep); // get next word
    }

    /* Count frequency of each word */
    for (int i = 0; i < word_count; i++)
    {
        for (int j = i + 1; j < word_count; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                frequency[i]++;
                words[j] = ""; // mark word as counted
            }
        }
    }

    /* Print word frequency */
    printf("Word Frequency\n");
    for (int i = 0; i < word_count; i++)
    {
        if (strlen(words[i]) > 0) // ignore empty words
        {
            printf("%-10s %d\n", words[i], frequency[i] + 1); // add 1 to frequency for original word
        }
    }

    printf("\n");
    printf("Why did the programmer quit his job? He didn't get arrays!\n");
    printf("Why do programmers prefer dark mode? Because light attracts bugs!\n");
    printf("Why do programmers prefer dogs? Because they love fetching pointers!\n");
    printf("Why do programmers hate nature? Because they don't know how to merge branches!\n");
    printf("Why do programmers always mix up Christmas and Halloween? Because Oct 31 equals Dec 25!\n");
    printf("Why don't programmers like nature? Because it has too many bugs!\n");

    return 0;
}