//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: medieval
#include<stdio.h>
#include<string.h>

//Function to sanitize user input
void sanitize_input(char input[])
{
    int i,j;
    char sanitized[50]="";
    for(i=0,j=0;i<strlen(input);i++)
    {
        if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') || (input[i]>='0' && input[i]<='9') || input[i]==' ')
        {
            sanitized[j++]=input[i];
        }
    }
    strcpy(input,sanitized);
    printf("Sanitized input: %s",input);
}

int main()
{
    char input[50];
    printf("My liege, please enter your command: ");
    fgets(input,sizeof(input),stdin);
    sanitize_input(input);

    return 0;
}