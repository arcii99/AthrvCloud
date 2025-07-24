//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

/*
 * This program checks whether a given string is palindrome or not.
 * A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward.
 * Examples of palindrome words: Deified, Racecar, Level, Madam, etc.
 */

int main() {
    char str[MAX_LENGTH];
    int i, j, flag;
    
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    
    // Remove newline character from the input string
    str[strcspn(str, "\n")] = '\0';
    
    // Convert the input string to lowercase and remove non-alphanumeric characters
    char processed_str[MAX_LENGTH];
    int k = 0;
    for (i = 0; i < strlen(str); i++) {
        if (isalnum(str[i])) {
            processed_str[k++] = tolower(str[i]);
        }
    }
    processed_str[k] = '\0';
    
    // Check if the processed string is a palindrome
    flag = 1;
    for (i = 0, j = strlen(processed_str)-1; i < j; i++, j--) {
        if (processed_str[i] != processed_str[j]) {
            flag = 0;
            break;
        }
    }
    
    // Print the output
    if (flag) {
        printf("\n%s is a palindrome!\n", str);
    } else {
        printf("\n%s is not a palindrome.\n", str);
    }
    
    return 0;
}