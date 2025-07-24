//FormAI DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 10 // Arbitrary number of times a word needs to appear for it to be identified as spam
#define MAX_STRING_LENGTH 1000 // Maximum length of input string

const char *spam_words[] = {"buy", "free", "offer", "discount", "money", "click", "limited", "exclusive"}; // List of spam keywords

int is_spam(const char *input)
{
    int i, j, count;
    char str[MAX_STRING_LENGTH];
    strcpy(str, input); // Copy the input string into a new buffer to tokenize it

    char *token = strtok(str, " "); // Tokenize the string
    while (token != NULL)
    {
        count = 0;
        for (i = 0; i < sizeof(spam_words)/sizeof(char*); i++)
        {
            if (strcmp(token, spam_words[i]) == 0)
            {
                count++;
            }
        }
        if (count >= SPAM_THRESHOLD) // If the number of occurrences of a spam word is above the threshold, return true
        {
            return 1;
        }
        token = strtok(NULL, " "); // Move to the next token
    }

    return 0;
}

int main()
{
    char input[MAX_STRING_LENGTH];
    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    if (is_spam(input))
    {
        printf("The message is identified as spam.\n");
    }
    else
    {
        printf("The message is not identified as spam.\n");
    }

    return 0;
}