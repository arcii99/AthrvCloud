//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter the string you want to check: ");

    char str[100];
    fgets(str, sizeof(str), stdin); // read input from user

    int len = strlen(str) - 1; // exclude the newline character

    int i, j;
    for(i=0, j=len-1; i<len/2; i++, j--)
    {
        if(str[i] != str[j])
        {
            printf("The string is not a palindrome\n");
            return 0;
        }
    }

    printf("The string is a palindrome\n");

    return 0;
}