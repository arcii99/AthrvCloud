//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include <stdio.h>
#include <string.h>

int main()
{
    char userInput[100];
    int count = 0;
    
    printf("Type in some text:\n");
    fgets(userInput, 100, stdin);
    
    for(int i=0; i<strlen(userInput); i++)
    {
        if(userInput[i] == '(')
        {
            count++;
        }
        else if(userInput[i] == ')')
        {
            count--;
            
            if(count < 0)
            {
                printf("Intrusion detected: extra closing parenthesis");
                return 0;
            }
        }
    }
    
    if(count != 0)
    {
        printf("Intrusion detected: extra opening parenthesis");
    }
    else
    {
        printf("Input is valid.");
    }
    
    return 0;
}