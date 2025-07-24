//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_LENGTH 100

void checkPalindrome(char *string);

int main()
{
    char str[MAX_LENGTH] = {0};
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    checkPalindrome(str);

    return 0;
}

void checkPalindrome(char *string)
{
    int length = strlen(string);
    int i,j;
    int flag=0;
    char temp[MAX_LENGTH]={0};

    for(i=0,j=0;i<length;i++)
    {
        if(isalpha(string[i])) //check if character is alphabetic
        {
            temp[j++] = tolower(string[i]); //convert to lowercase and add to temp string
        }
    }

    length = strlen(temp); //new length after removing non-alphabetic characters
    for(i=0,j=length-1;i<j;i++,j--)
    {
        if(temp[i]!=temp[j])
        {
            flag=1; //not a palindrome
            break;
        }
    }
    if(flag==1)
        printf("The entered string is not a palindrome.\n");
    else
        printf("The entered string is a palindrome.\n");
}