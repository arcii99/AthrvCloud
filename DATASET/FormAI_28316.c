//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *word);

int main() {
    char word[50];

    printf("Enter a word to check if it's a palindrome: ");
    scanf("%s", word);

    if(isPalindrome(word)) {
        printf("%s is a palindrome!\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}

int isPalindrome(char *word) {
    int length = strlen(word);
    char copy[length];
    int i, j;

    // Convert word to lowercase and remove non-alphabetic characters
    for(i = 0, j = 0; i < length; i++) {
        if(isalpha(word[i])) {
            copy[j++] = tolower(word[i]);
        }
    }
    copy[j] = '\0'; // add null terminator to end of string

    length = strlen(copy); // update length to new length of copy

    // Check if copy is a palindrome
    for(i = 0, j = length - 1; i < j; i++, j--) {
        if(copy[i] != copy[j]) {
            return 0;
        }
    }

    return 1;
}