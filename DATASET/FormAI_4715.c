//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main()
{
    char input[MAX_INPUT_LENGTH];
    int i, stackPointer = 0;

    printf("Intrusion Detection System\n");

    while(1)
    {
        printf("Enter command: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        if(strncmp(input, "exit", 4) == 0)
        {
            printf("Exiting IDS...\n");
            break;
        }

        for(i = 0; i < strlen(input); i++)
        {
            if(input[i] == '[')
            {
                stackPointer++;
            }
            else if(input[i] == ']')
            {
                stackPointer--;
            }

            if(stackPointer < 0)
            {
                printf("Intrusion Attempt Detected: unbalanced parentheses\n");
                break;
            }
        }

        if(stackPointer == 0)
        {
            printf("Command Accepted\n");
        }
        else if(stackPointer > 0)
        {
            printf("Intrusion Attempt Detected: unbalanced parentheses\n");
        }

        stackPointer = 0;
    }

    return 0;
}