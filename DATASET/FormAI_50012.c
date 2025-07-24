//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[100];
    int length, i;
    bool isPalindrome = true;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);

    for (i = 0; i < length/2; i++) {
        if (str[i] != str[length-i-1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}