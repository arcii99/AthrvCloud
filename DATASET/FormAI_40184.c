//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char str[]) 
{
    int left = 0, right = strlen(str) - 1;
    while (left < right) 
    {
        while (!isalnum(str[left]))
            left++;
            
        while (!isalnum(str[right]))
            right--;
            
        if (toupper(str[left++]) != toupper(str[right--]))
            return false;
    }
    return true;
}

int main() 
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    if (isPalindrome(str))
        printf("'%s' is a palindrome\n", str);
    else
        printf("'%s' is not a palindrome\n", str);
        
    return 0;
}