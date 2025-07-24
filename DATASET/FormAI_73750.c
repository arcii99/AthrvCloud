//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main()
{
    char buffer[BUFFER_SIZE];
    int pos = 0, neg = 0, neutral = 0;

    printf("Enter some text to analyze sentiment: \n");

    // read input text
    fgets(buffer, BUFFER_SIZE, stdin);

    // remove newline character
    buffer[strcspn(buffer, "\n")] = 0;

    // tokenize input text into words
    char *pch;
    pch = strtok (buffer," ,.-");

    while (pch != NULL)
    {
        // convert word to lowercase
        for(int i = 0; i < strlen(pch); i++)
        {
            pch[i] = tolower(pch[i]);
        }
        
        // check if word is positive, negative or neutral
        if (strcmp(pch, "good") == 0 || strcmp(pch, "great") == 0 || strcmp(pch, "excellent") == 0)
        {
            pos++;
        }
        else if (strcmp(pch, "bad") == 0 || strcmp(pch, "terrible") == 0 || strcmp(pch, "awful") == 0)
        {
            neg++;
        }
        else
        {
            neutral++;
        }
        
        pch = strtok (NULL, " ,.-");
    }

    // print sentiment analysis result
    printf("Sentiment analysis result:\n");
    printf("Positive words: %d\n", pos);
    printf("Negative words: %d\n", neg);
    printf("Neutral words: %d\n", neutral);

    return 0;
}