//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include<stdio.h>
#include<string.h>

int main()
{
    printf("Welcome to the Palindrome Checker program!\n\n");
    printf("Please enter a word or phrase to check if it is a palindrome: ");
    char input[100];
    scanf("%s", input);
    printf("\n");

    int length = strlen(input);
    int isPalindrome = 1;

    for(int i=0; i<length/2; i++)
    {
        if(input[i]!=input[length-i-1])
        {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome == 1)
    {
        printf("%s is a palindrome!\n", input);
        printf("Wow, impressive!\n");
    }
    else
    {
        printf("%s is not a palindrome.\n", input);
        printf("Sorry, better luck next time!\n");
    }

    printf("\nThank you for using the Palindrome Checker program!\n");

    return 0;
}