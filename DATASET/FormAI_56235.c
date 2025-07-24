//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char str[])
{
    int length = strlen(str);
    
    for (int i = 0; i < length/2; i++)
    {
        if (str[i] != str[length-1-i])
            return false;
    }
    return true;
}

int main()
{
    char str[100];
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", str);
    
    if (isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);
    
    return 0;
}