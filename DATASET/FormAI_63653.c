//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) // function to check if a string is palindrome
{
    int len = strlen(str); // get length of the string
    int i; // loop control variable

    for (i = 0; i < len / 2; i++) { 
        if (str[i] != str[len - i - 1]) { // if the first and the last characters do not match
            return 0; // the string is not palindrome
        }
    }

    return 1; // the string is palindrome
}

int main()
{
    char str[100]; // string to check

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) { // if the string is palindrome
        printf("%s is palindrome", str);
    }
    else { // if the string is not palindrome
        printf("%s is not palindrome", str);
    }

    return 0;
}