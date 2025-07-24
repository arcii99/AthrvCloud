//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 100
#define SPAM_THRESHOLD 10

int main()
{
    int spam_count = 0;
    char message[MAX_MSG_LENGTH];
    
    printf("Welcome to the Spam Detection system!\n");
    
    while(1)
    {
        printf("Enter a message: ");
        fgets(message, MAX_MSG_LENGTH, stdin);
        
        int msg_length = strlen(message);
        if(msg_length > 0 && message[msg_length - 1] == '\n')
        {
            message[msg_length - 1] = '\0';
        }
        
        int i;
        for(i = 0; i < msg_length; i++)
        {
            if(message[i] == '$' || message[i] == '£' || message[i] == '€')
            {
                spam_count++;
            }
        }
        
        if(spam_count >= SPAM_THRESHOLD)
        {
            printf("This message is likely spam!\n");
            printf("Please do not send any more spam messages... Thank you.\n");
            break;
        }
        else
        {
            printf("Message received. Thank you!\n");
        }
    }

    return 0;
}