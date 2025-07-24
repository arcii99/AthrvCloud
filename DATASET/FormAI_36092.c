//FormAI DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[1000];
    int i, j, k, count;

    printf("Enter the message: ");
    fgets(message, 1000, stdin); 

    // Scanning the message character by character
    for(i = 0; i < strlen(message); i++)
    {
        count = 0; // Initializing count to 0 for each character in message
        if((message[i] == 'c') || (message[i] == 'C')) // Identifying if the character is 'c' or 'C'
        {
            for(j = i; j < (i+5); j++) // Checking the next 5 characters
            {
                if((message[j] == 'a') || (message[j] == 'A'))
                {
                    count++; // Incrementing the count variable if the character is 'a' or 'A'
                }
            }
            if(count == 2) // If the count is 2, then the message contains spam
            {
                printf("SPAM!!!");
                exit(0); // Terminating the program if the message contains spam
            }
        }
    }
    printf("No spam found!");
    return 0;
}