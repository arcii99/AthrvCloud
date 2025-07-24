//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: light-weight
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

// Function to check palindromic string
int isPalindrome(char * str)
{
    int len = strlen(str); // Finding length of string
    int i;
    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
            return 0; // Not a Palindrome
    }
    return 1; // Palindrome String
}

int main()
{
    char str[MAX_SIZE]; // Creating an array of characters to store the input string
    printf("Enter the string: ");
    scanf("%[^\n]s",str); // Reading the input string
    if(isPalindrome(str))
        printf("The string is Palindrome.\n");
    else
        printf("The string is not a Palindrome.\n");
    return 0; // End of program
}