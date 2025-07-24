//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char string[100];
    int i, j, len, flag = 0;

    printf("Welcome to the Palindrome Checker! Let's check if your string is a palindrome or not.\n");
    printf("Please enter a string (maximum length: 100): ");
    fgets(string, 100, stdin);

    len = strlen(string);

    for(i = 0, j = len - 1; i <= j; i++, j--)
    {
        while(!isalnum(string[i]) && i <= j)
        {
            i++;
        }
        while(!isalnum(string[j]) && i <= j)
        {
            j--;
        }
        if(tolower(string[i]) != tolower(string[j]))
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("\nCongratulations! The string is a palindrome.\n");
    }
    else
    {
        printf("\nSorry, the string is not a palindrome.\n");
    }

    return 0;
}