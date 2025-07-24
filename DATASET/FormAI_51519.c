//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int isPalindrome(char* str);

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character from input
    if (isPalindrome(str)) {
        printf("%s is a palindrome!", str);
    } else {
        printf("%s is not a palindrome.", str);
    }
    return 0;
}

int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}