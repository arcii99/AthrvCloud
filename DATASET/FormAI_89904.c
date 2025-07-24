//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str, int start, int end)
{
    if(start >= end) // Base case: If start pointer crosses the end pointer, it's a palindrome
        return 1;
    if(tolower(str[start]) != tolower(str[end])) // If the characters don't match, it's not a palindrome
        return 0;
    return isPalindrome(str, start + 1, end - 1); // Recursive call to check the remaining substring
}

int main()
{
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin); // Read the input string from the user
    
    int len = strlen(input);
    if(input[len-1] == '\n') // Remove the newline character from the input string
        input[len-1] = '\0';
    
    if(isPalindrome(input, 0, strlen(input)-1))
        printf("%s is a palindrome\n", input);
    else
        printf("%s is not a palindrome\n", input);
    
    return 0;
}