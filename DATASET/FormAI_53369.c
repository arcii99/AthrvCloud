//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    char sanitized_input[100];
    printf("Enter your input :\n");
    fgets(input,sizeof(input),stdin);
    printf("Your original input is : %s",input);
    int i,k=0;
    int count = strlen(input);
    for(i=0;i<count;i++)
    {
        if((input[i]>='a'&& input[i]<='z') || (input[i]>='A'&& input[i]<='Z') || (input[i]>='0' && input[i]<='9'))
        {
            sanitized_input[k]=input[i];
            k++;
        }
    }
    sanitized_input[k]='\0'; //adding null terminated character.
    printf("\nSanitized Input : %s",sanitized_input);
    return 0;
}