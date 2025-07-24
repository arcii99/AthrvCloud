//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int positive_count = 0, negative_count = 0;

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter a sentence to analyze its sentiment: ");
    fgets(input, 100, stdin);

    // Removing the trailing newline character
    if (strlen(input) > 0 && input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';

    char* positive_words[] = {"good", "happy", "love", "like", "excited", "amazing"};
    char* negative_words[] = {"bad", "sad", "hate", "dislike", "disappointed", "terrible"};

    // Tokenizing the input sentence and comparing with the positive and negative words
    char* token = strtok(input, " ");
    while (token != NULL)
    {
        for (int i = 0; i < 6; i++)
        {
            if (strcmp(token, positive_words[i]) == 0)
            {
                positive_count++;
                break;
            }
            if (strcmp(token, negative_words[i]) == 0)
            {
                negative_count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("Sentiment analysis result: \n");
    if (positive_count > negative_count)
        printf("This sentence is mostly positive.\n");
    else if (negative_count > positive_count)
        printf("This sentence is mostly negative.\n");
    else
        printf("This sentence is neutral.\n");

    return 0;
}