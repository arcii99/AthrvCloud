//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_LEN 200
#define MAX_SUMMARY_LEN 200

int main()
{
    char text[MAX_SENTENCES][MAX_SENTENCE_LEN], summary[MAX_SUMMARY_LEN];
    int num_sentences;

    printf("Enter the number of sentences in the text: ");
    scanf("%d", &num_sentences);

    printf("Enter the text:\n");
    for (int i = 0; i < num_sentences; i++)
    {
        scanf(" %[^\n]s", text[i]);
    }

    // Summarize the text
    int sentence_scores[num_sentences];
    memset(sentence_scores, 0, sizeof(sentence_scores)); // Initialize all scores to 0
    int words_in_sentence;
    char *word_in_sentence;

    for (int i = 0; i < num_sentences; i++)
    {
        words_in_sentence = 0;
        word_in_sentence = strtok(text[i], " ");

        // Count number of words in the sentence
        while (word_in_sentence != NULL)
        {
            words_in_sentence++;
            word_in_sentence = strtok(NULL, " ");
        }

        // Assign score based on sentence length
        if (words_in_sentence <= 10)
            sentence_scores[i] += 1;
        else if (words_in_sentence <= 20)
            sentence_scores[i] += 2;
        else
            sentence_scores[i] += 3;

        // Assign score based on presence of keywords
        if (strstr(text[i], "important") || strstr(text[i], "essential"))
            sentence_scores[i] += 2;
        if (strstr(text[i], "urgent"))
            sentence_scores[i] += 3;
    }

    // Form the summary
    int summary_len = 0, num_summary_sentences = 0;
    for (int i = 0; i < num_sentences; i++)
    {
        if (sentence_scores[i] >= 3) // Sentences with score of 3 or more are included in summary
        {
            strcat(summary, text[i]);
            strcat(summary, " ");
            summary_len += strlen(text[i]) + 1; // Length of summary + space
            num_summary_sentences++;

            if (num_summary_sentences >= 3) // Maximum 3 sentences in summary
                break;
        }
    }

    printf("\nSummary:\n%s\n", summary);

    return 0;
}