//FormAI DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

void remove_punctuation(char *sentence)
{
    char *s = sentence;
    while (*s)
    {
        if (*s == '.' || *s == ',' || *s == ';' || *s == ':' || *s == '?' || *s == '!')
            memmove(s, s + 1, strlen(s + 1) + 1);
        else
            s++;
    }
}

void to_lower_case(char *word)
{
    for (int i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }
}

void summarize(char *input, int num_sentences)
{
    // Define arrays to store sentences and words
    char sentences[MAX_SENTENCES][1000] = {{0}};
    char words[MAX_WORDS][50] = {{0}};

    // Get individual sentences from input
    char *token = strtok(input, ".!?");
    int sentence_count = 0;
    while (token != NULL && sentence_count < MAX_SENTENCES)
    {
        strcpy(sentences[sentence_count], token);
        sentence_count++;
        token = strtok(NULL, ".!?");
    }

    // Get individual words from each sentence
    int total_words = 0;
    for (int i = 0; i < sentence_count; i++)
    {
        char *token = strtok(sentences[i], " ");
        while (token != NULL && total_words < MAX_WORDS)
        {
            remove_punctuation(token);
            to_lower_case(token);
            strcpy(words[total_words], token);
            total_words++;
            token = strtok(NULL, " ");
        }
    }

    // Count the frequency of each word
    int word_frequency[MAX_WORDS] = {0};
    for (int i = 0; i < total_words; i++)
    {
        for (int j = 0; j < total_words; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                word_frequency[i]++;
            }
        }
    }

    // Find the most frequent words
    int most_frequent_words[num_sentences];
    for (int i = 0; i < num_sentences; i++)
    {
        int max_frequency = 0;
        int max_index = -1;
        for (int j = 0; j < total_words; j++)
        {
            if (word_frequency[j] > max_frequency && word_frequency[j] != -1)
            {
                max_frequency = word_frequency[j];
                max_index = j;
            }
        }
        most_frequent_words[i] = max_index;
        word_frequency[max_index] = -1;
    }

    // Print the summary
    printf("Summary:\n");
    for (int i = 0; i < num_sentences; i++)
    {
        printf("%s.", sentences[most_frequent_words[i]]);
    }
}

int main()
{
    char input[10000] = "The quick brown fox jumps over the lazy dog. The lazy dog jumps over the quick brown fox. The quick brown fox is quick. The lazy dog is lazy. The quick brown fox is brown. The lazy dog is brown too.";
    summarize(input, 3);
    return 0;
}