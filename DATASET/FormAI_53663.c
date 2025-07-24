//FormAI DATASET v1.0 Category: Spam Detection System ; Style: happy
#include<stdio.h>
#include<string.h>

int main()
{
    char message[10000];
    int count=0;
    printf("Welcome to the Spam Detection System!\n");
    printf("Please type in your message:\n");
    scanf("%s", message);
    for(int i=0; i<strlen(message); i++)
    {
        if(message[i] == 's') //Check for the letter 's'
        {
            if(message[i+1] == 'p') //If it is followed by the letter 'p'
            {
                if(message[i+2] == 'a') //If 'a' follows 'sp'
                {
                    if(message[i+3] == 'm') //If 'm' follows 'spa'
                    {
                        count++; //Increase the count of spam
                    }
                }
            }
        }
    }
    if(count > 0) //If there is spam in the message
    {
        printf("Alert! This message contains spam.\n"); //Display alert message
    }
    else
    {
        printf("This message is safe to send.\n"); //Display safe message
    }
    return 0;
}