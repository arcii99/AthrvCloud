//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>

int main()
{
    // Initialize variables and arrays
    char message[100];
    int spamCount = 0;
    int keywordCount = 0;
    char keywords[5][10] = {"buy", "sale", "discount", "limited time offer", "act now"};

    // Ask for user input
    printf("Enter message: ");
    scanf("%[^\n]", message);

    // Check for spam keywords
    for (int i = 0; i < 5; i++) 
    {
        if (strstr(message, keywords[i]) != NULL) 
        {
            spamCount++;
            keywordCount++;
        }
    }

    // Display results
    if (spamCount > 0) 
    {
        printf("This message has been flagged as spam.\n");
        printf("%d instances of spam keywords were found.\n", keywordCount);
    } 
    else 
    {
        printf("This message is not spam.\n");
    }

    return 0;
}