//FormAI DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200
#define MAX_SUMMARY_LENGTH 500

char *summarize(char *text);

int main()
{
    char text[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    char *summary;

    printf("Enter text to summarize:\n");

    int i = 0;
    while (i < MAX_SENTENCES && fgets(text[i], MAX_SENTENCE_LENGTH, stdin) != NULL)
    {
        i++;
    }

    summary = summarize(text[0]);

    printf("\n\nSummary:\n%s\n", summary);

    return 0;
}

char *summarize(char *text)
{
    // Remove trailing newline character
    text[strcspn(text, "\n")] = 0;

    // Split text into sentences
    char *sentences[MAX_SENTENCES];
    char *sentence;
    sentence = strtok(text, ".!?");

    int num_sentences = 0;
    while (sentence != NULL && num_sentences < MAX_SENTENCES)
    {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".!?");
    }

    // Find the most important sentence
    int importance[MAX_SENTENCES];
    memset(importance, 0, sizeof(importance));

    for (int i = 0; i < num_sentences; i++)
    {
        for (int j = 0; j < num_sentences; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (strstr(sentences[j], sentences[i]) != NULL)
            {
                importance[i]++;
            }
        }
    }

    int max_importance = 0;
    int max_sentence_index = 0;

    for (int i = 0; i < num_sentences; i++)
    {
        if (importance[i] > max_importance)
        {
            max_importance = importance[i];
            max_sentence_index = i;
        }
    }

    // Generate summary
    char *summary = malloc(MAX_SUMMARY_LENGTH);
    memset(summary, 0, MAX_SUMMARY_LENGTH);

    strcat(summary, sentences[max_sentence_index]);
    strcat(summary, ".");

    return summary;
}