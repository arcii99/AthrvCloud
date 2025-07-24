//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 0.8 // define the spam threshold

int main()
{
    printf("Welcome to the Spam Detection System!\n");
    printf("Enter your text message:\n");

    char message[1000];
    fgets(message, 1000, stdin);

    // Remove the new line character at the end
    message[strcspn(message, "\n")] = 0;

    int spamCount = 0;
    int totalWords = 0;

    char* token = strtok(message, " ");

    // Loop through each word in the message
    while (token != NULL)
    {
        totalWords++;

        // Check if the word contains any spam keywords
        if (strstr(token, "buy") || strstr(token, "sale") || strstr(token, "discount"))
        {
            spamCount++;
        }

        token = strtok(NULL, " ");
    }

    // Calculate the spam percentage
    float spamPercentage = (float)spamCount / totalWords;

    printf("\nSpam Percentage: %f\n", spamPercentage);

    if (spamPercentage > SPAM_THRESHOLD)
    {
        printf("This message is likely spam.\n");
    }
    else
    {
        printf("This message is not likely spam.\n");
    }

    return 0;
}