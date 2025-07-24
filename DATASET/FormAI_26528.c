//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>

/* Function to check if a given string is a palindrome */
int isPalindrome(char str[]) {
    int len = strlen(str);
    
    // Check if each character matches with the corresponding character from the end
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    
    return 1;
}

/* Main function */
int main() {
    char str[100];
    
    // Getting input from the user
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Checking if the entered string is a palindrome
    if (isPalindrome(str)) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }
    
    return 0;
}