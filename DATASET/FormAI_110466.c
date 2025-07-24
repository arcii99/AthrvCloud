//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include<stdio.h>
#include<string.h>

int main()
{
    char input[100];
    int positivityScore = 0, negativityScore = 0;

    // Take user input
    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter the sentence that you would like to analyze: ");
    fgets(input, 100, stdin);

    // Remove the newline character
    input[strcspn(input, "\n")] = 0;

    // Split the input into words
    char* word = strtok(input, " ");

    while(word != NULL)
    {
        // Check if the word is positive or negative
        if(strcmp(word, "good") == 0 || strcmp(word, "happy") == 0 || strcmp(word, "love") == 0)
        {
            positivityScore++;
        }
        else if(strcmp(word, "bad") == 0 || strcmp(word, "angry") == 0 || strcmp(word, "hate") == 0)
        {
            negativityScore++;
        }

        word = strtok(NULL, " ");
    }

    // Print the final sentiment score
    printf("\nSentiment Analysis Result:\n");
    printf("Positive Score: %d\n", positivityScore);
    printf("Negative Score: %d\n", negativityScore);

    if(positivityScore > negativityScore)
    {
        printf("The sentence is positive!");
    }
    else if(positivityScore < negativityScore)
    {
        printf("The sentence is negative!");
    }
    else
    {
        printf("The sentence is neutral.");
    }

    return 0;
}