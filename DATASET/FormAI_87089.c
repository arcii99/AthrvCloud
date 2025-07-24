//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <string.h>

// This function calculates the sentiment score for a given sentence
// It takes a sentence as input and returns an integer sentiment score
int calculateSentimentScore(char sentence[])
{
    int score = 0;
    int length = strlen(sentence);
    char temp[length + 1];
    strcpy(temp, sentence); // make a copy of the string so we can safely modify it
    char *token = strtok(temp, " "); // split the string on spaces

    while (token != NULL)
    {
        if (strstr(token, "good") != NULL || strstr(token, "great") != NULL || strstr(token, "excellent") != NULL)
            score += 1;
        else if (strstr(token, "bad") != NULL || strstr(token, "terrible") != NULL || strstr(token, "awful") != NULL)
            score -= 1;

        token = strtok(NULL, " "); // move to the next token
    }

    return score;
}

int main()
{
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin); // read a line of input from the user
    sentence[strcspn(sentence, "\n")] = 0; // remove the newline character from the end of the input

    int score = calculateSentimentScore(sentence);

    if (score > 0)
        printf("The sentiment score for \"%s\" is positive.\n", sentence);
    else if (score < 0)
        printf("The sentiment score for \"%s\" is negative.\n", sentence);
    else
        printf("The sentiment score for \"%s\" is neutral.\n", sentence);

    return 0;
}