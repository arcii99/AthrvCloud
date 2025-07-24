//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str);

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    if (isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}

int isPalindrome(char *str) {
    int i, j, len;
    char copy[100];
    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            copy[j++] = tolower(str[i]);
        }
    }
    len = strlen(copy);
    for (i = 0; i < len / 2; i++) {
        if (copy[i] != copy[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}