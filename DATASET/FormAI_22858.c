//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main()
{
    char input_text[1000];
    int positive_count = 0;
    int negative_count = 0;
    int neutral_count = 0;

    printf("Input some text:\n");
    fgets(input_text, 1000, stdin);

    char *token = strtok(input_text, " ,.\"");

    while(token != NULL)
    {
        if(strcmp(token, "happy") == 0 || strcmp(token, "glad") == 0 || strcmp(token, "joyful") == 0 || strcmp(token, "pleased") == 0)
            positive_count++;
        else if(strcmp(token, "sad") == 0 || strcmp(token, "unhappy") == 0 || strcmp(token, "angry") == 0 || strcmp(token, "miserable") == 0)
            negative_count++;
        else
            neutral_count++;

        token = strtok(NULL, " ,.\"");
    }

    printf("\nPositive words: %d\n", positive_count);
    printf("Negative words: %d\n", negative_count);
    printf("Neutral words: %d\n", neutral_count);

    if(positive_count > negative_count)
        printf("\nThe sentiment analysis of the text is positive.\n");
    else if(negative_count > positive_count)
        printf("\nThe sentiment analysis of the text is negative.\n");
    else
        printf("\nThe sentiment analysis of the text is neutral.\n");

    return 0;
}