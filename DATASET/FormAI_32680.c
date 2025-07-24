//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include <stdio.h>
#include <string.h>

char reverse(char str[]) // function to reverse the input string
{
    int i, j, len;
    char temp;
    len = strlen(str);
    j = len - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

int main()
{
    char str[1000];
    printf("Welcome to Palindromic Check!\n");
    printf("Enter your word or phrase: ");
    fgets(str, sizeof(str), stdin); // get user input
    str[strcspn(str, "\n")] = '\0'; // remove trailing newline character
    printf("\n");
    printf("Checking if '%s' is palindrome...\n", str);
    printf("\n"); 
    if (strcmp(str, reverse(str)) == 0) // compare original string with reversed string
    {
        printf("'%s' is a palindrome!\n", str);
        printf("\n");
    }
    else
    {
        printf("'%s' is not a palindrome!\n", str);
        printf("\n");
    }
    printf("Thank you for using Palindromic Check!\n");
    return 0;
}