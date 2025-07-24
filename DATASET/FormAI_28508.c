//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum input string length
#define MAX_LEN 100

int main()
{
    // Declare variables
    char input_string[MAX_LEN];
    int num_chars = 0;
    int num_words = 1; // Initializing to 1 for the first word
    int sentiment_score = 0;

    // Prompt the user for input
    printf("Enter a string of text (maximum characters allowed: %d):\n", MAX_LEN);
    fgets(input_string, MAX_LEN, stdin);

    // Remove the newline character at the end of the string (if present)
    input_string[strcspn(input_string, "\n")] = 0;

    // Calculate the number of characters in the input
    num_chars = strlen(input_string);

    // Loop through each character in the input string
    for(int i=0; i<num_chars; i++)
    {
        // If the character is a space or a punctuation mark (excluding hyphen), consider it as a word separator
        if(input_string[i]==' ' || input_string[i]=='.' || input_string[i]==',' || input_string[i]==';' || input_string[i]==':' || input_string[i]=='?' || input_string[i]=='!')
        {
            num_words++;
        }
        else
        {
            // Convert the character to its ASCII value and add it to the sentiment score
            sentiment_score += input_string[i];
        }
    }

    // Calculate the average sentiment score per word
    float avg_sentiment_score = (float)sentiment_score/num_words;

    // Print the sentiment analysis results
    printf("Sentiment analysis:\n");
    printf("Input string: %s\n", input_string);
    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);
    printf("Sentiment score: %d\n", sentiment_score);
    printf("Average sentiment score per word: %.2f\n", avg_sentiment_score);

    return 0;
}