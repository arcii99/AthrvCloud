//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Welcome to the Palindrome Checker!\n");

    char str[100];
    int start, end, check = 1; 

    printf("Enter a string to check if it's a palindrome: \n");
    gets(str); 

    start = 0;
    end = strlen(str) - 1;

    while (end > start) {
        if (str[start++] != str[end--]) {
            check = 0;
            break;
        }
    }

    if (check) {
        printf("Congratulations! The given string is a palindrome.\n");
    } else {
        printf("Oops! The given string is not a palindrome.\n");
    }

    return 0;
}