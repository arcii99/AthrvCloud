//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str);

int main()
{
    printf("Welcome to the C Palindrome Checker!\n");
    printf("Please enter a word or phrase: ");

    char input[100];
    fgets(input, 100, stdin);

    int len = strlen(input);
    if(input[len-1] == '\n') input[len-1] = '\0'; 

    if(is_palindrome(input)) printf("Yes, '%s' is a palindrome!\n", input);
    else printf("Sorry, '%s' is not a palindrome.\nBut don't worry, I'll fix it for you!\n", input);

    char fixed_input[100];
    char c;
    int i, j;
    for(i=0,j=0; i < len; i++)
    {
        c = tolower(input[i]); 
        if(isalpha(c)) fixed_input[j++] = c; 
    }
    fixed_input[j] = '\0';

    if(is_palindrome(fixed_input)) printf("Fixed: '%s' is a palindrome!\n", fixed_input);
    else printf("Fixed: '%s' is still not a palindrome.\n", fixed_input);

    return 0;
}

// Helper function to check if string is a palindrome
int is_palindrome(char *str)
{
    int len = strlen(str);
    for(int i=0; i < len/2; i++)
    {
        if(str[i] != str[len-i-1]) return 0; 
    }

    return 1; 
}