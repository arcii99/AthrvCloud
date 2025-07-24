//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include<stdio.h>
#include<string.h>

int main()
{
    char string[100],reverse[100];
    int length,i,j=0;

    printf("Enter a string : ");
    scanf("%s",&string);

    length=strlen(string);

    for(i=length-1;i>=0;i--)
    {
        reverse[j]=string[i];
        j++;
    }
    reverse[j] = '\0';

    printf("Reverse string is : %s",reverse);

    return 0;
}