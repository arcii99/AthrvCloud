//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to check if given string is a palindrome */
int isPalindrome(char *str) {
    int i, j;
    int len = strlen(str);
 
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char inputStr[100];
 
    printf("Welcome to Palindrome Checker!\n");
    printf("Enter the string to be checked: ");
    scanf("%s", inputStr);

    /* Call isPalindrome function to check if input string is a palindrome or not */
    if (isPalindrome(inputStr)) {
        printf("%s is a palindrome.\n", inputStr);
    } else {
        printf("%s is not a palindrome.\n", inputStr);
    }
 
    return 0;
}