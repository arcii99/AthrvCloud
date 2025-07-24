//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char* str);

int main()
{
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);
    if (isPalindrome(inputString))
        printf("%s is a palindrome.\n", inputString);
    else
        printf("%s is not a palindrome.\n", inputString);
    return 0;
}

int isPalindrome(char* str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}