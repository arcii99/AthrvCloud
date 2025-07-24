//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>   
#include <string.h>

#define MAX_INPUT_LENGTH 1000 
#define MAX_SUMMARY_LENGTH 100

int main()
{
    char input[MAX_INPUT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];

    printf("Enter the input text:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Split the input into phrases using the period separator
    char* phrase = strtok(input, ".");
    char phrases[MAX_SUMMARY_LENGTH][MAX_INPUT_LENGTH];
    int num_phrases = 0;
    while (phrase != NULL) 
    {
        strcpy(phrases[num_phrases], phrase);
        num_phrases++;
        if (num_phrases == MAX_SUMMARY_LENGTH) break;
        phrase = strtok(NULL, ".");
    }

    // Determine the relevance of each phrase using word frequency analysis
    int freq[MAX_SUMMARY_LENGTH] = {0};
    char* word = strtok(input, " ");
    while (word != NULL) 
    {
        for (int i = 0; i < num_phrases; i++) 
        {
            if (strstr(phrases[i], word) != NULL) 
            {
                freq[i]++;
            }
        }
        word = strtok(NULL, " ");
    }

    // Extract the most relevant phrases for the summary
    int num_summary_phrases = 0;
    while (num_summary_phrases < 3 && num_summary_phrases < num_phrases) 
    {
        int max_freq = 0;
        int max_phrase = -1;
        for (int i = 0; i < num_phrases; i++) 
        {
            if (freq[i] > max_freq) 
            {
                max_freq = freq[i];
                max_phrase = i;
            }
        }
        if (max_phrase != -1) 
        {
            strcpy(summary, phrases[max_phrase]);
            num_summary_phrases++;
            freq[max_phrase] = 0;
        }
    }

    printf("Summary:\n");
    printf("%s\n", summary);
    return 0;
}