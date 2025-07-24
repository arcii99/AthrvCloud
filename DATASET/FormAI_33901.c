//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
// This is a sentiment analysis tool that analyses the sentiment of user input and outputs the result

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* main function */
int main()
{
    char input[100]; // declare variable to store user input
    int posCount = 0, negCount = 0, totalWords = 0; // initialize word counters

    printf("Enter your text: ");
    fgets(input, 100, stdin); // get user input and store in input variable

    char *token = strtok(input, " "); // split input by space character as delimiter

    while (token != NULL) // loop through the tokenized input
    {
        totalWords++; // increment total word count

        /* check if word is positive or negative */
        if (strncmp(token, "good", 4) == 0 || strncmp(token, "great", 5) == 0 || strncmp(token, "excellent", 9) == 0)
            posCount++; // increment positive count
        else if (strncmp(token, "bad", 3) == 0 || strncmp(token, "terrible", 8) == 0 || strncmp(token, "horrible", 8) == 0)
            negCount++; // increment negative count

        token = strtok(NULL, " "); // get next token
    }

    /* output sentiment analysis result */
    printf("\nSentiment Analysis Result:\n");
    
    if (totalWords == 0) // check if there are no words entered
    {
        printf("No words entered!\n");
    }
    else if (posCount == negCount) // check if sentiment is neutral
    {
        printf("Neutral Sentiment\n");
    }
    else if (posCount > negCount) // check if sentiment is positive
    {
        printf("Positive Sentiment\n");
    }
    else // sentiment is negative
    {
        printf("Negative Sentiment\n");
    }

    return 0; // exit program
}