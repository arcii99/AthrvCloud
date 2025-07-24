//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 100

int main()
{
    char text[1000];
    char summary[MAX_SUMMARY_LENGTH];

    printf("Enter a text to summarize: ");
    fgets(text, 1000, stdin);

    // Remove new line character from the end of the string
    text[strcspn(text, "\n")] = '\0';

    // Split the text into sentences
    char *sentence = strtok(text, ".!?");

    // Count the number of sentences
    int num_sentences = 0;
    while (sentence != NULL)
    {
        num_sentences++;
        sentence = strtok(NULL, ".!?");
    }

    // Calculate the length of each sentence and store in array
    int sentence_lengths[num_sentences];
    int i = 0;
    sentence = strtok(text, ".!?");
    while (sentence != NULL)
    {
        sentence_lengths[i] = strlen(sentence);
        i++;
        sentence = strtok(NULL, ".!?");
    }

    // Determine which sentences to include in summary
    int summary_length = 0;
    int sentence_count = 0;
    sentence = strtok(text, ".!?");
    while (sentence != NULL && summary_length < MAX_SUMMARY_LENGTH)
    {
        if (sentence_count == num_sentences - 1) // Always include the final sentence
        {
            strcat(summary, sentence);
            summary_length += strlen(sentence);
        }
        else if (summary_length + sentence_lengths[sentence_count] <= MAX_SUMMARY_LENGTH)
        {
            strcat(summary, sentence);
            summary_length += sentence_lengths[sentence_count];
        }
        else
        {
            break;
        }

        strcat(summary, ". "); // Add period and space between sentences
        summary_length += 2;
        sentence_count++;

        sentence = strtok(NULL, ".!?");
    }

    printf("\nSummary: %s", summary);

    return 0;
}