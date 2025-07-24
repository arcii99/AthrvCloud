//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int i, j, length;
    int isPalindrome = 1;

    printf("Enter a string: ");
    fgets(text, 100, stdin);
    length = strlen(text) - 1;

    for (i = 0, j = length - 1; i < length / 2; i++, j--) {
        if (text[i] != text[j]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("\"%s\" is a palindrome.", text);
    } else {
        printf("\"%s\" is not a palindrome.", text);
    }

    return 0;
}