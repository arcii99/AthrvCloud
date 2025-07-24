//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: realistic
#include <stdio.h>
#include <string.h>

/* A function to check if a given string is palindrome */
int isPalindrome(char *str)
{
    int len = strlen(str);
 
    // Compare characters from opposite ends
    // until they meet in the middle
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}
 
int main()
{
    char str[100];
 
    printf("Enter a string: ");
    scanf("%s", str);
 
    if (isPalindrome(str))
        printf("%s is a palindrome", str);
    else
        printf("%s is not a palindrome", str);
 
    return 0;
}