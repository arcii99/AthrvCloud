//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char str[])
{
    int length = strlen(str);
 
    for (int i = 0; i < length/2; i++)
        if (str[i] != str[length-i-1])
            return false;
 
    return true;
}
 
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
 
    return 0;
}