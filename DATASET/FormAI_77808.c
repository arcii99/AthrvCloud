//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: realistic
#include <stdio.h>
#include <string.h>

int isPalindrome(char string[]) {
    int length = strlen(string); // get the length of the string
    
    for(int i = 0; i < length / 2; ++i) {
        if(string[i] != string[length - i - 1]) {
            return 0; // if any character does not match, it is not a palindrome
        }
    }
    
    return 1; // otherwise it is a palindrome
}

int main() {
    printf("Enter a string: ");
    char string[100];
    fgets(string, 100, stdin); // get user input, maximum length of string is 100
    
    // remove the newline character from the user input
    int length = strlen(string);
    if(string[length - 1] == '\n') {
        string[length - 1] = '\0';
    }
    
    if(isPalindrome(string)) {
        printf("%s is a palindrome.\n", string);
    } else {
        printf("%s is not a palindrome.\n", string);
    }
    
    return 0;
}