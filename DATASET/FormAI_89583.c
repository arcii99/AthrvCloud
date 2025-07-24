//FormAI DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10000

char *text_summarizer(char *article)
{
    // Initializing variables
    int i = 0;
    int article_length = strlen(article);
    char *summary = (char *)calloc(MAX_SIZE, sizeof(char));

    // Check if summary memory allocation was successful
    if (summary == NULL)
    {
        printf("Error: Summary memory allocation failed");
        exit(1);
    }

    // Loop to scan through the entire article
    while (i < article_length)
    {
        // Find a sentence
        int j = i;
        while (j < article_length && article[j] != '.')
            j++;

        // Identify the length of the sentence
        int sentence_length = j - i + 1;

        // Extract the sentence
        char *sentence = (char *)calloc(sentence_length, sizeof(char));
        strncpy(sentence, article + i, sentence_length);

        // Check if sentence memory allocation was successful
        if (sentence == NULL)
        {
            printf("Error: Sentence memory allocation failed");
            exit(1);
        }

        // Check if the sentence contains a keyword
        if (strstr(sentence, "important") || strstr(sentence, "critical") || strstr(sentence, "essential"))
        {
            strcat(summary, sentence);
            strcat(summary, " ");
        }

        // Increment i to start scanning from the next sentence
        i = j + 1;

        // Free memory for the extracted sentence
        free(sentence);
    }

    // Return the generated summary
    return summary;
}

int main()
{
    // Initialize article
    char article[] = "In today's world, staying healthy is important. It is essential to avoid diseases and illnesses. There are many ways to stay healthy. Eating a balanced diet is critical. Daily exercise is also essential. Similarly, getting enough sleep is important.";

    // Call the text summarizer function
    char *summary = text_summarizer(article);

    // Print the generated summary
    printf("%s", summary);

    // Free memory for the generated summary
    free(summary);

    return 0;
}