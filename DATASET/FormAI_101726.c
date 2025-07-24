//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// A function to check if a given string is a palindrome
int isPalindrome(char* str)
{
    int len = strlen(str);

    // Check for empty or single character strings
    if (len < 2) {
        return 1;
    }

    // Loop through half of the string and check if the corresponding characters are the same
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    int palindrome = isPalindrome(str);

    if (palindrome) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}