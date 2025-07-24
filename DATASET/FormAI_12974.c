//FormAI DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100];
    int i, flag;

    printf("Enter a message: ");
    gets(message);

    for(i=0;message[i]!='\0';i++)
    {
        //Checks if the message contains the word "spam"
        if(message[i]=='s' && message[i+1]=='p' && message[i+2]=='a' && message[i+3]=='m')
        {
            flag = 1; //If there's spam, sets flag to 1
            break;
        }
    }

    if(flag==1)
    {
        printf("This message contains spam. Please refrain from sending such messages.\n");
    }
    else
    {
        printf("This message is spam free. You may now proceed to send the message.\n");
    }

    return 0;
}