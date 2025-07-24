//FormAI DATASET v1.0 Category: Spam Detection System ; Style: complex
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MIN_SPAM_SCORE 5

int main()
{
    char line[MAX_LINE_LENGTH];
    int spamScore = 0;
    bool isSpam = false;

    printf("Enter a message:\n");

    // Read the message line by line
    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
        // Remove trailing newline character
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n')
        {
            line[len-1] = '\0';
        }

        // Check for common spam phrases
        if (strstr(line, "make money fast") || strstr(line, "get rich quick"))
        {
            spamScore += 2;
        }

        if (strstr(line, "enlarge your")) 
        {
            spamScore += 1;
        }

        if (strstr(line, "click here"))
        {
            spamScore += 1;
        }

        // Check for excessive use of exclamation marks
        int exclamationCount = 0;
        for (char *c = line; *c; c++)
        {
            if (*c == '!')
            {
                exclamationCount++;
            }
        }

        if (exclamationCount >= 3)
        {
            spamScore += 1;
        }

        // Check if message is entirely in upper case
        bool isUpperCase = true;
        for (char *c = line; *c; c++)
        {
            if (*c >= 'a' && *c <= 'z')
            {
                isUpperCase = false;
                break;
            }
        }

        if (isUpperCase)
        {
            spamScore += 1;
        }

        // Check if message is empty
        if (len == 0)
        {
            printf("Please enter a message.\n");
            continue;
        }

        // Determine if message is spam or not
        if (spamScore >= MIN_SPAM_SCORE)
        {
            isSpam = true;
        }

        // Print appropriate message
        if (isSpam)
        {
            printf("This message has been flagged as spam.\n");
        }
        else
        {
            printf("This message is not spam.\n");
        }

        // Reset spam score and flag for next message
        spamScore = 0;
        isSpam = false;
    }

    return 0;
}