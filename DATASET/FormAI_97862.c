//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str);

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);     // Read input string
    str[strcspn(str, "\n")] = 0;        // Remove newline character

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}

int isPalindrome(char *str) {
    char temp[strlen(str)];
    int len = strlen(str);
    int j = 0;

    // Copy only alphanumeric characters and convert uppercase to lowercase
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            temp[j++] = tolower(str[i]);
        }
    }
    temp[j] = '\0';     // Terminate string

    int n = strlen(temp);
    // Check if each character from start and end is same
    for (int i = 0; i < n / 2; i++) {
        if (temp[i] != temp[n - 1 - i]) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Palindrome
}