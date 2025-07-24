//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char input[]) {
    int len = strlen(input);
    for (int i=0; i<len/2; i++) {
        if (input[i] != input[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[100];
    printf("Enter a word or phrase: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    
    if (isPalindrome(input)) {
        printf("%s is a palindrome!\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    
    return 0;
}