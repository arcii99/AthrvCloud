//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: all-encompassing
// C program to check if a string is palindrome or not

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[100];
    int i,len;
    int palindrome = 1;
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%[^\n]", str);
    len = strlen(str);
    for(i = 0; i < len/2; i++)
    {
        if(tolower(str[i]) != tolower(str[len-i-1]))
        {
            palindrome = 0;
            break;
        }
    }
    if(palindrome)
        printf("%s is a palindrome.", str);
    else
        printf("%s is not a palindrome.", str);
    
    return 0;
}