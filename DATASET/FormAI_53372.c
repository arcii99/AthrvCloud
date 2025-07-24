//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check if a given string is a palindrome
int isPalindrome(char str[]) {
    int length = strlen(str);
    
    // initialize two pointers, one at the beginning and the other at the end
    int i = 0;
    int j = length - 1;
    
    // keep moving the pointers towards each other until they meet
    while (i < j) {
        // ignore non-alphanumeric characters and convert uppercase to lowercase
        while (!isalnum(str[i])) {
            i++;
        }
        while (!isalnum(str[j])) {
            j--;
        }
        if (tolower(str[i]) != tolower(str[j])) {
            return 0; // not a palindrome
        }
        i++;
        j--;
    }
    return 1; // is a palindrome
}

int main() {
    char str[100];
    printf("Enter a word or phrase to check if it's a palindrome:\n");
    fgets(str, 100, stdin);

    // remove newline character at the end of string
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
    
    if (isPalindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is NOT a palindrome!\n", str);
    }
    
    return 0;
}