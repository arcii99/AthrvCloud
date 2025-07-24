//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char* str) {
    char* front = str;
    char* back = str + strlen(str) - 1;
    
    while (front < back) {
        if (*front != *back) {
            return 0;
        }
        front++;
        back--;
    }
    return 1;
}

int main() {
    char input[100];
    printf("Enter a word or phrase to check if it's a palindrome: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\r\n")] = 0; // Remove newline character from input
    
    // Convert input to lowercase and remove non-alphabetic characters
    char cleanInput[100];
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            cleanInput[j] = tolower(input[i]);
            j++;
        }
    }
    cleanInput[j] = '\0';
    
    if (isPalindrome(cleanInput)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    return 0;
}