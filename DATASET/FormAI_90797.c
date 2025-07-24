//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() 
{
    char message[100];
    int count = 0;
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    int len = strlen(message);
    for (int i = 0; i < len; i++)
    {
        if (message[i] == 'c') 
        {
            count++;
        }
    }
    if (count >= 3) 
    {
        printf("This message looks like spam!\n");
        printf("There are %d occurrences of the letter 'c' in your message.\n", count);
        printf("Sherlock Holmes would say that this message is too suspicious to be genuine.\n");
    } 
    else 
    {
        printf("This message looks genuine.\n");
        printf("There are only %d occurrences of the letter 'c' in your message.\n", count);
        printf("Sherlock Holmes would say that this message is most likely genuine.\n");
    }
    return 0;
}