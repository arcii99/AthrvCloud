//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int isPalindrome(char *str);

int main() {
    char str[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    printf("\n");
    
    if (isPalindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome :(\n", str);
    }
    
    return 0;
}

int isPalindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        if (str[left++] != str[right--]) {
            return 0;
        }
    }
    
    return 1;
}