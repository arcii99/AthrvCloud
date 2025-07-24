//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char input[100],output[100];
    int i,j;

    printf("Enter the input string:\n");
    scanf("%s",&input);

    // Converting input string to uppercase
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]>='a'&&input[i]<='z')
        {
            input[i]=input[i]-32;
        }
    }

    // Reversing the input string
    j=0;
    for(i=strlen(input)-1;i>=0;i--)
    {
        output[j++]=input[i];
    }
    output[j]='\0';

    // Printing the output string
    printf("The output string is:\n%s",output);

    return 0;
}