//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

/* Define our surrealist function */
void detectSpam()
{
    char input[100];
    int count = 0;
    printf("Please enter a message: ");
    fgets(input, 100, stdin);
    fflush(stdin);
    /* Interpret the input in the most surreal way possible */
    for (int i = 0; i < 100; i++)
    {
        if (input[i] == 'c')
        {
            count++;
        }
        else if (input[i] == ' ')
        {
            continue;
        }
        else if (input[i] == '\n')
        {
            break;
        }
        else
        {
            printf("Error! Invalid character detected. Please try again.\n");
            exit(0);
        }
    }
    /* Identify whether the message is spam or not */
    if (count >= 3)
    {
        printf("Warning! Suspicious message. Possible spam detected. Please edit and resubmit your message.\n");
    }
    else
    {
        printf("Thank you for your message! We will get back to you shortly.\n");
    }
}

/* Begin main function */
int main()
{
    printf("Welcome to our surreal spam detection system! Here's your chance to shine.\n");
    detectSpam();
    return 0;
}