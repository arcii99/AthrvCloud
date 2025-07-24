//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 200 // Maximum length of summary

void summarizeText(char *text, int length)
{
    char summary[MAX_SUMMARY_LENGTH] = ""; // Initialize summary string

    int sentenceCount = 0;
    char *token;

    // Split text into sentences
    token = strtok(text, ".!?");
    while (token != NULL)
    {
        sentenceCount++;
        strcat(summary, token); // Add token to summary
        strcat(summary, ". "); // Add period and space after sentence
        token = strtok(NULL, ".!?");
    }

    // Output summary
    printf("\n--- Happy Summary ---\n");
    printf("%s\n", summary);

    // Output summary stats
    printf("\nSummary Stats:\n");
    printf("Sentence count: %d\n", sentenceCount);
    printf("Summary length: %d\n", (int)strlen(summary));
}

int main()
{
    char text[] = "Once upon a time, in a faraway kingdom, there lived a beautiful princess. She had long golden hair and big blue eyes. Everyone who saw her was enchanted by her beauty. One day, while walking in the forest, she met a handsome prince. They fell in love instantly. The prince asked her to marry him and she said yes. They had a grand wedding and lived happily ever after.";

    summarizeText(text, sizeof(text)/sizeof(text[0]));

    return 0;
}