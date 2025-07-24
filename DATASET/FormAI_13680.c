//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <string.h>

int main()
{
    // Define input message
    char message[1000];
    printf("Enter the message: ");
    fgets(message, 1000, stdin);
    
    // Loop through the message and count the number of positive and negative words
    int positiveCount = 0;
    int negativeCount = 0;
    char *positiveWords[] = {"happy", "excellent", "good", "great", "awesome"};
    char *negativeWords[] = {"sad", "terrible", "bad", "awful", "horrible"};
    char *token = strtok(message, " ,.\n");
    while (token != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(token, positiveWords[i]) == 0)
            {
                positiveCount++;
            }
            if (strcmp(token, negativeWords[i]) == 0)
            {
                negativeCount++;
            }
        }
        token = strtok(NULL, " ,.\n");
    }
    
    // Determine the sentiment score and label
    int sentimentScore = positiveCount - negativeCount;
    char sentimentLabel[20];
    if (sentimentScore > 0)
    {
        strcpy(sentimentLabel, "Positive");
    }
    else if (sentimentScore < 0)
    {
        strcpy(sentimentLabel, "Negative");
    }
    else
    {
        strcpy(sentimentLabel, "Neutral");
    }
    
    // Print the results
    printf("Sentiment Score: %d\n", sentimentScore);
    printf("Sentiment Label: %s\n", sentimentLabel);
    
    return 0;
}