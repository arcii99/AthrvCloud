//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: retro
#include<stdio.h>
#include<string.h>

int main()
{
    char string[100];
    int i,c=0;
    printf("***********************\n");
    printf("RETRO STYLE PALINDROME CHECKER\n");
    printf("***********************\n");
    printf("Enter the String:");
    scanf("%s",string);
    printf("\n");
    printf("String length is %d\n",strlen(string));
    printf("Ascii Conversion is -->> ");
    for(i=0;i<strlen(string);i++)
    {
        printf("%d ",string[i]);
    }
    printf("\nReversed string is --> ");
    for(i=strlen(string)-1;i>=0;i--)
    {
        printf("%c",string[i]);
    }
    printf("\n");
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]!=string[strlen(string)-i-1])
        {
            c++;
            break;
        }
    }
    if(c==0)
    {
        printf("The string %s is Palindrome",string);
    }
    else
    {
        printf("The string %s is not Palindrome",string);
    }
    return 0;
}