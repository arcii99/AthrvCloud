//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
/*
Author: Ada Lovelace
Title: Spam Detection System
Description: This program detects spam messages by analyzing their content and providing a confidence score.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGE_LENGTH 1000  // Maximum length of message to be processed
#define SCORE_THRESHOLD 0.5      // Threshold for determining whether or not a message is spam

// Function declarations
float analyze_message(char message[]);
bool contains_keywords(char message[]);
int count_punctuation_marks(char message[]);
int count_uppercase_letters(char message[]);
int count_lowercase_letters(char message[]);

int main()
{
    char message[MAX_MESSAGE_LENGTH];
    float confidence_score;

    printf("Enter the message you would like to check for spam: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    confidence_score = analyze_message(message);

    if (confidence_score >= SCORE_THRESHOLD)
    {
        printf("The message is likely spam.\n");
    }
    else
    {
        printf("The message is not spam.\n");
    }

    return 0;
}

float analyze_message(char message[])
{
    float score = 0.0;

    // Check if message contains any of the following known spam keywords
    if (contains_keywords(message))
    {
        score += 0.3;
    }

    // Count number of punctuation marks
    int num_punct_marks = count_punctuation_marks(message);
    if (num_punct_marks > 5)
    {
        score += 0.2;
    }

    // Count number of uppercase letters
    int num_uppercase_letters = count_uppercase_letters(message);
    if (num_uppercase_letters > 10)
    {
        score += 0.1;
    }

    // Count number of lowercase letters
    int num_lowercase_letters = count_lowercase_letters(message);
    if (num_lowercase_letters > 5)
    {
        score += 0.1;
    }

    // Return the final confidence score
    return score;
}

bool contains_keywords(char message[])
{
    char keywords[][20] = {"BUY NOW", "CLICK HERE", "FREE", "MONEY BACK GUARANTEE"};

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        if (strstr(message, keywords[i]) != NULL)
        {
            return true;
        }
    }

    return false;
}

int count_punctuation_marks(char message[])
{
    int count = 0;

    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] == ',' || message[i] == '.' || message[i] == ';' || message[i] == ':' || message[i] == '!' || message[i] == '?')
        {
            count++;
        }
    }

    return count;
}

int count_uppercase_letters(char message[])
{
    int count = 0;

    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            count++;
        }
    }

    return count;
}

int count_lowercase_letters(char message[])
{
    int count = 0;

    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            count++;
        }
    }

    return count;
}