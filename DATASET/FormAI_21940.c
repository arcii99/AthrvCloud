//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR_SIZE 100

bool isPalindrome(char str[MAX_STR_SIZE])
{
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    char str[MAX_STR_SIZE];
    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, MAX_STR_SIZE, stdin);
    
    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';
    
    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
    
    return 0;
}