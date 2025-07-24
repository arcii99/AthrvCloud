//FormAI DATASET v1.0 Category: Spam Detection System ; Style: intelligent
#include<stdio.h>
#include<string.h>

int main()
{
    char message[1000];
    int i, j, spam_count=0, non_spam_count=0;

    printf("Enter your message:\n");
    fgets(message, sizeof(message), stdin);

    char *spam_keywords[10] = {"gift", "offer", "amazing", "free", "limited time", "act now", "opportunity", "won", "call now", "credit"};
    int spam_keyword_count = sizeof(spam_keywords)/sizeof(char *);

    char *tokens = strtok(message, " ");
    while(tokens != NULL)
    {
        for (i = 0; i<spam_keyword_count; i++)
        {
            if (strstr(tokens, spam_keywords[i]) != NULL)
            {
                spam_count++;
                break;
            }
        }
        non_spam_count++;
        tokens = strtok(NULL, " ");
    }

    if (spam_count > non_spam_count/10)
    {
        printf("WARNING! This message may be a spam.\n");
    }
    else
    {
        printf("This message appears to be legitimate.\n");
    }

    return 0;
}