//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[100];
    int left, right, len;
    int isPalindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }

    left = 0;
    right = len - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}