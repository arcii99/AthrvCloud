//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str, int start, int end)
{
    if (start == end || start > end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

void printResult(char *str, bool palindrome) {
    if (palindrome) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
}

int main()
{
    char input[100];
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", input);
    
    int start = 0;
    int end = strlen(input) - 1;

    bool palindrome = isPalindrome(input, start, end);

    printResult(input, palindrome);

    return 0;
}