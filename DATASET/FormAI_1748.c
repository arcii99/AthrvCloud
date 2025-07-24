//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 100
#define MAX_SENTENCES 30
#define MAX_WORDS 100

int main()
{
    char input_text[MAX_INPUT_SIZE];
    char output_text[MAX_OUTPUT_SIZE];

    // Read input text
    printf("Enter the text to summarize:\n");
    fgets(input_text, MAX_INPUT_SIZE, stdin);

    // Pre-process input text
    char* sentences[MAX_SENTENCES];
    char* words[MAX_SENTENCES][MAX_WORDS];
    int word_count[MAX_SENTENCES];
    int sentence_count = 0;
    char* temp = strtok(input_text, "\n");
    while (temp != NULL && sentence_count < MAX_SENTENCES)
    {
        sentences[sentence_count] = temp;
        temp = strtok(NULL, "\n");
        char* tok = strtok(sentences[sentence_count], " ");
        int i = 0;
        while (tok != NULL && i < MAX_WORDS)
        {
            words[sentence_count][i] = tok;
            tok = strtok(NULL, " ");
            i++;
        }
        word_count[sentence_count] = i;
        sentence_count++;
    }

    // Calculate BOW score for each sentence
    int bow[MAX_SENTENCES];
    for (int i = 0; i < sentence_count; i++)
    {
        bow[i] = 0;
        for (int j = 0; j < word_count[i]; j++)
        {
            for (int k = 0; k < sentence_count; k++)
            {
                if (k != i)
                {
                    for (int l = 0; l < word_count[k]; l++)
                    {
                        if (strcmp(words[i][j], words[k][l]) == 0)
                        {
                            bow[i]++;
                        }
                    }
                }
            }
        }
    }

    // Generate summary
    int summary_sentences[MAX_SENTENCES];
    int summary_count = 0;
    while (summary_count < MAX_SENTENCES)
    {
        int max_bow = -1;
        int max_index = -1;
        for (int i = 0; i < sentence_count; i++)
        {
            if (bow[i] > max_bow)
            {
                max_bow = bow[i];
                max_index = i;
            }
        }
        if (max_index == -1)
        {
            break;
        }
        summary_sentences[summary_count] = max_index;
        summary_count++;
        bow[max_index] = -1;
    }

    // Output summary
    printf("Summary:\n");
    for (int i = 0; i < summary_count; i++)
    {
        printf("%s\n", sentences[summary_sentences[i]]);
    }

    return 0;
}