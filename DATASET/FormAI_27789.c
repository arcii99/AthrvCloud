//FormAI DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

int main()
{
    char message[1000]; // declare string to store message
    int i, j, len;
    int spam_count = 0; // initialize spam counter

    // prompt user to input message
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    len = strlen(message); // get length of message

    // check for spam keywords
    for(i=0; i<len; i++)
    {
        if(message[i] == 'm' && message[i+1] == 'o' && message[i+2] == 'n' && message[i+3] == 'e' && message[i+4] == 'y')
        {
            spam_count++;
        }

        if(message[i] == 'w' && message[i+1] == 'i' && message[i+2] == 'n')
        {
            spam_count++;
        }

        if(message[i] == 'f' && message[i+1] == 'r' && message[i+2] == 'e' && message[i+3] == 'e')
        {
            spam_count++;
        }

        if(message[i] == 'c' && message[i+1] == 'l' && message[i+2] == 'a' && message[i+3] == 'i' && message[i+4] == 'm')
        {
            spam_count++;
        }
    }

    // display result
    if(spam_count >= 2)
    {
        printf("This message is classified as spam.");
    }
    else
    {
        printf("This message is not spam.");
    }

    return 0;
}