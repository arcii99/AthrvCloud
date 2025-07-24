//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check whether the given string is a palindrome or not
int isPalindrome(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        if(str[i] != str[len-i-1])
            return 0;
    }
    return 1;
}

// main function to get input from user and check whether it is a palindrome or not
int main() {
    char input[100];
    printf("Welcome to the Palindrome Checker program!\n\n");
    printf("Enter a string to check if it's a palindrome:\n");
    scanf("%s", input);
    if(isPalindrome(input)) {
        printf("\nThe entered string '%s' is a palindrome!\n", input);
    }
    else {
        printf("\nThe entered string '%s' is not a palindrome!\n", input);
    }
    printf("\nThanks for using Palindrome Checker!\n");
    return 0;
}