//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

// Function to check whether a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str); // length of the string
    for(int i = 0; i < len/2; i++) {
        if(str[i] != str[len-i-1]) {
            return 0; // not a palindrome
        }
    }
    return 1; // is a palindrome
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    
    if(isPalindrome(input)) {
        printf("%s is a palindrome!\n", input);
    } else {
        printf("%s is not a palindrome!\n", input);
    }
    
    return 0;
}