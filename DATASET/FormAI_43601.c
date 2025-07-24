//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function prototype declaration
void sentimentAnalysis();

int main()
{
    // Program introduction
    printf("Welcome to the Sentiment Analysis Tool!\n\n");
    printf("This program will analyze the sentiment of a given statement and classify it as positive, negative or neutral.\n");
    printf("Please enter your statement:\n\n");

    // Calling the sentimentAnalysis function
    sentimentAnalysis();

    return 0;
}

// Function definition
void sentimentAnalysis()
{
    // Variable declaration
    char statement[1000];
    int positiveCount = 0, negativeCount = 0, neutralCount = 0;
    double positivePercentage, negativePercentage, neutralPercentage;

    // Reading the input statement
    fgets(statement, 1000, stdin);

    // Analyzing the sentiment of the statement
    for (int i = 0; statement[i] != '\0'; i++)
    {
        if (statement[i] == 'good' || statement[i] == 'nice' || statement[i] == 'happy')
        {
            positiveCount++;
        }
        else if (statement[i] == 'bad' || statement[i] == 'poor' || statement[i] == 'unhappy')
        {
            negativeCount++;
        }
        else
        {
            neutralCount++;
        }
    }

    // Calculating the percentage of positive, negative and neutral sentiments
    positivePercentage = ((double) positiveCount / strlen(statement)) * 100;
    negativePercentage = ((double) negativeCount / strlen(statement)) * 100;
    neutralPercentage = ((double) neutralCount / strlen(statement)) * 100;

    // Displaying the results
    printf("\nPositive Sentiment Percentage: %.2lf%%\n", positivePercentage);
    printf("Negative Sentiment Percentage: %.2lf%%\n", negativePercentage);
    printf("Neutral Sentiment Percentage: %.2lf%%\n", neutralPercentage);

    if (positivePercentage > negativePercentage && positivePercentage > neutralPercentage)
    {
        printf("\nThe given statement is positive in sentiment!\n");
    }
    else if (negativePercentage > positivePercentage && negativePercentage > neutralPercentage)
    {
        printf("\nThe given statement is negative in sentiment!\n");
    }
    else if (neutralPercentage > positivePercentage && neutralPercentage > negativePercentage)
    {
        printf("\nThe given statement is neutral in sentiment!\n");
    }
    else
    {
        printf("\nThe given statement does not have a predominant sentiment!\n");
    }
}