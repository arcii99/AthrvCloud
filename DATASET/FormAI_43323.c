//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: multivariable
#include<stdio.h>
#include<string.h>
#define MAX 100

void palindromeCheck(char string[MAX], int length);

int main()
{
    char inputString[MAX];
    printf("\nEnter a string to check for palindrome: ");
    fgets(inputString, MAX, stdin);
    inputString[strlen(inputString)-1] = '\0';
    int length = strlen(inputString);

    palindromeCheck(inputString, length);

    return 0;
}

void palindromeCheck(char string[MAX], int length)
{
    int leftIndex = 0, rightIndex = length-1, flag = 1;

    while(rightIndex >= leftIndex)
    {
        if(string[leftIndex] != string[rightIndex])
        {
            flag = 0;
            break;
        }
            
        leftIndex++;
        rightIndex--;
    }

    if(flag == 1)
    {
        printf("\n%s is a palindrome.", string);
    }
    else
    {
        printf("\n%s is not a palindrome.", string);
    }
}