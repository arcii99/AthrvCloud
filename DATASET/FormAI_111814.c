//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Input string to be analyzed
    char input[100];

    // User prompt
    printf("Enter your sentence: ");

    // Read input from user
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;

    // Tokenize input into words
    char *token = strtok(input, " ");

    int pos_count = 0;
    int neg_count = 0;
    int neutral_count = 0;

    // Loop through all words in input
    while(token != NULL)
    {
        // Positive words list
        char *pos_words[] = {"good", "great", "excellent", "amazing", "wonderful"};

        // Negative words list
        char *neg_words[] = {"bad", "awful", "terrible", "horrible", "disappointing"};

        // Check if current token is positive, negative or neutral
        int is_positive = 0;
        int is_negative = 0;

        for(int i = 0; i < 5; i++)
        {
            if(strcmp(token, pos_words[i]) == 0)
            {
                is_positive = 1;
                break;
            }
            else if(strcmp(token, neg_words[i]) == 0)
            {
                is_negative = 1;
                break;
            }
        }

        if(is_positive)
            pos_count++;
        else if(is_negative)
            neg_count++;
        else
            neutral_count++;

        token = strtok(NULL, " ");
    }

    // Determine overall sentiment
    if(pos_count > neg_count)
        printf("The sentiment of the input is positive.\n");
    else if(neg_count > pos_count)
        printf("The sentiment of the input is negative.\n");
    else
        printf("The sentiment of the input is neutral.\n");

    return 0;
}