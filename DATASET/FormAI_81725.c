//FormAI DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_LENGTH 20

const char *SPAM_WORDS[MAX_SPAM_WORDS] = {"buy", "discount", "money", "free", "sale"};

int main()
{
    char input[100];
    int detected_spam = 0;
    
    printf("Enter a message: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;
    
    // Check for spam words
    for (int i = 0; i < MAX_SPAM_WORDS; i++)
    {
        if (strstr(input, SPAM_WORDS[i]) != NULL)
        {
            printf("Spam word detected: %s\n", SPAM_WORDS[i]);
            detected_spam = 1;
        }
    }
    
    if (!detected_spam)
    {
        printf("No spam detected.\n");
    }
    
    return 0;
}