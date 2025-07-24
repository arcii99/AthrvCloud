//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 256

// Function Prototypes
int sentiment_analysis(char *input);
int categorize_word(char *word, int *positive, int *negative);
void clear_cin();

// Main Function
int main()
{
    char input[MAX_INPUT];

    printf("Welcome to the Sentiment Analysis Tool!\n\n");
    printf("Please input a phrase or sentence for analysis:\n");

    // Take User Input
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character at end

    // Get Sentiment Analysis Results
    int sentiment_score = sentiment_analysis(input);

    // Output Results
    printf("\nSentiment Analysis Results: ");

    if (sentiment_score > 0)
    {
        printf("Positive\n");
    }
    else if (sentiment_score < 0)
    {
        printf("Negative\n");
    }
    else
    {
        printf("Neutral\n");
    }

    return 0;
}

// Function to Perform Sentiment Analysis on Input String
int sentiment_analysis(char *input)
{
    int positive_count = 0, negative_count = 0;
    char *word;
    char *delimiters = " ,.;:-()";

    word = strtok(input, delimiters);

    while (word != NULL)
    {
        categorize_word(word, &positive_count, &negative_count);
        word = strtok(NULL, delimiters);
    }

    return (positive_count - negative_count);
}

// Helper Function to Categorize a Word as Positive or Negative
int categorize_word(char *word, int *positive, int *negative)
{
    FILE *positive_file, *negative_file;
    char buffer[MAX_INPUT];

    // Open Positive Words File
    if ((positive_file = fopen("positive_words.txt", "r")) == NULL)
    {
        printf("Error! Unable to Open positive_words.txt file.\n");
        exit(1);
    }

    // Open Negative Words File
    if ((negative_file = fopen("negative_words.txt", "r")) == NULL)
    {
        printf("Error! Unable to Open negative_words.txt file.\n");
        exit(1);
    }

    // Loop through Positive Words File
    while (fgets(buffer, MAX_INPUT, positive_file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character at end

        if (strcmp(buffer, word) == 0)
        {
            (*positive)++;
            break;
        }
    }

    // Loop through Negative Words File
    while (fgets(buffer, MAX_INPUT, negative_file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character at end

        if (strcmp(buffer, word) == 0)
        {
            (*negative)++;
            break;
        }
    }

    // Close Files
    fclose(positive_file);
    fclose(negative_file);

    return 0;
}

// Helper Function to Clear Input Buffer
void clear_cin()
{
    while (getchar() != '\n')
    {
        // clear buffer
    }
}