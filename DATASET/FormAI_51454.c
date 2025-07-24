//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int isPalindrome(char str[]);

int main()
{
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}

int isPalindrome(char str[])
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if ( ! isalnum(str[left])) {
            left++;
        } else if ( ! isalnum(str[right])) {
            right--;
        } else if (tolower(str[left]) == tolower(str[right])) {
            left++;
            right--;
        } else {
            return 0;
        }
    }

    return 1;
}