//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char* str);

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

int isPalindrome(char* str) {
    char* reversedStr = malloc(sizeof(char) * strlen(str));
    int i, j = 0;
    for (i = strlen(str) - 2; i >= 0; i--) {
        if (isalpha(str[i])) {
            reversedStr[j] = tolower(str[i]);
            j++;
        }
    }
    reversedStr[j] = '\0';

    for (i = 0; i < strlen(reversedStr) / 2; i++) {
        if (reversedStr[i] != reversedStr[strlen(reversedStr) - i - 1]) {
            return 0;
        }
    }

    return 1;
}