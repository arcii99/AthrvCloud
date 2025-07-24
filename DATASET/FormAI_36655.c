//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    // Remove whitespace
    int len = strlen(str);
    char newString[len];
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            newString[index] = str[i];
            index++;
        }
    }
    newString[index] = '\0';

    if (isPalindrome(newString)) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }

    return 0;
}