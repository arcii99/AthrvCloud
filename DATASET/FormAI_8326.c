//FormAI DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_MESSAGE_LENGTH 100

int main()
{
    char spam_words[MAX_SPAM_WORDS][20] = {"buy", "earn money fast", "click here", "subscribe now", "limited offer", "meet singles", "100% free", "discount", "act now", "free trial"};
    
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter your message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    int spam_count = 0;
    char *token;
    token = strtok(message, " ,.-\n");
    while(token != NULL)
    {
        for(int i=0; i<MAX_SPAM_WORDS; i++)
        {
            if(strcmp(token, spam_words[i]) == 0)
            {
                spam_count++;
                break;
            }
        }
        token = strtok(NULL, " ,.-\n");
    }
    
    printf("\nSpam count: %d\n", spam_count);
    
    if(spam_count > 5)
    {
        printf("This message is classified as spam.\n");
    }
    else
    {
        printf("This message is not spam.\n");
    }
    
    return 0;
}