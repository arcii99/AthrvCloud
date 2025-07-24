//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char inputStr[100];
    int i, j, len;
    int isPalindrome = 1;

    printf("Enter a string: ");
    fgets(inputStr, 100, stdin);
    inputStr[strcspn(inputStr, "\n")] = 0; //remove trailing newline character from input

    len = strlen(inputStr);
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (inputStr[i] != inputStr[j]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome == 1) {
        printf("Congratulations! The entered string is a Palindrome.\n");
        printf("Your string: %s\n", inputStr);
        printf("Reversed string: ");
        for (i = len - 1; i >= 0; i--) {
            printf("%c", inputStr[i]);
        }
    } else {
        printf("Sorry! The entered string is not a Palindrome.\n");
        printf("Your string: %s\n", inputStr);
        printf("Reversed string: ");
        for (i = len - 1; i >= 0; i--) {
            printf("%c", inputStr[i]);
        }
    }

    return 0;
}