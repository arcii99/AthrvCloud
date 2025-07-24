//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * This program checks whether a given input string is a palindrome or not.
 * A palindrome is a word or phrase that reads the same backwards as forwards.
 * For example "racecar" is a palindrome.
 *
 * To check whether the input string is a palindrome or not, we remove
 * any non-alphabetic characters (like spaces, commas, apostrophes etc,)
 * from the input string and then compare the string with its reverse.
 */

void removeNonAlphabeticChars(char *str) {
    char *src = str;
    char *dst = str;
    
    while (*src) {
        if (isalpha((unsigned char)*src)) {
            *dst = tolower((unsigned char)*src);
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

int isPalindrome(char *str) {
    int len = strlen(str);
    
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char inputStr[100];
    printf("Enter a word or phrase: ");
    fgets(inputStr, 100, stdin);
    
    // Remove non-alphabetic characters from input string
    removeNonAlphabeticChars(inputStr);
    
    // Check whether input string is a palindrome or not
    if (isPalindrome(inputStr)) {
        printf("%s is a palindrome.\n", inputStr);
    } else {
        printf("%s is not a palindrome.\n", inputStr);
    }
    return 0;
}