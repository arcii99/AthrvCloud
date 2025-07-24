//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the given character is a punctuation mark
int is_punctuation(char ch)
{
    if(ch == '.' || ch == ',' || ch == '?' || ch == '!' || ch == ';' || ch == ':' || ch == '-'
       || ch == '"' || ch == '\'' || ch == '(' || ch == ')' || ch == '{' || ch == '}')
       return 1; // Return 1 if punctuation
    return 0; // Return 0 otherwise
}

// Function to remove punctuation marks from the given string
void remove_punctuation(char str[])
{
    int i, j;
    for(i = j = 0; str[i]; i++)
    {
        if(!is_punctuation(str[i])) // Copy only if it's not a punctuation mark
            str[j++] = str[i];
    }
    str[j] = '\0'; // Terminate the string at the correct position
}

// Function to calculate the sentiment score of the given string
int calculate_sentiment(char str[])
{
    int len = strlen(str);
    int score = 0;
    int i, j;

    for(i = 0; i < len; )
    {
        // Find the next word in the string
        j = i + 1;
        while(j < len && str[j] != ' ') j++;

        // Copy the word into a new string
        char word[j-i+1];
        strncpy(word, &str[i], j-i);
        word[j-i] = '\0';

        // Remove any punctuation marks from the word
        remove_punctuation(word);

        // Calculate the score of the word
        if(strcmp(word, "amazing") == 0 || strcmp(word, "excellent") == 0 || strcmp(word, "great") == 0)
            score += 3;
        else if(strcmp(word, "good") == 0 || strcmp(word, "nice") == 0 || strcmp(word, "fine") == 0)
            score += 2;
        else if(strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "terrible") == 0)
            score -= 2;
        else if(strcmp(word, "horrible") == 0 || strcmp(word, "awful") == 0 || strcmp(word, "worst") == 0)
            score -= 3;

        // Move on to the next word
        i = j + 1;
    }

    return score;
}

int main()
{
    char str[1000];
    printf("Enter a sentence to analyze:");
    fgets(str, 1000, stdin);

    int score = calculate_sentiment(str);

    if(score > 0)
        printf("The sentiment score of the sentence is positive (%d).\n", score);
    else if(score < 0)
        printf("The sentiment score of the sentence is negative (%d).\n", score);
    else
        printf("The sentiment score of the sentence is neutral (%d).\n", score);

    return 0;
}