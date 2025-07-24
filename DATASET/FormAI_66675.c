//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void checkPalindrome(char *str);

int main()
{
    char input[MAX_LENGTH];
    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);
    checkPalindrome(input);
    return 0;
}

void checkPalindrome(char *str)
{
    int length = strlen(str);
    int i, j, flag = 0;
    char lowerStr[MAX_LENGTH], reverseStr[MAX_LENGTH];

    //Convert input string to lowercase
    for(i=0; i<length-1; i++)
    {
        lowerStr[i] = tolower(str[i]);
    }
    lowerStr[i] = '\0';

    //Reverse the input string
    for(i=0, j=length-2; i<length-1; i++, j--)
    {
        reverseStr[i] = lowerStr[j];
    }
    reverseStr[i] = '\0';

    //Compare reverse string and input string
    for(i=0; i<length-1; i++)
    {
        if(reverseStr[i] != lowerStr[i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("The string is a palindrome!\n");
    }
    else
    {
        printf("The string is not a palindrome!\n");
    }
}