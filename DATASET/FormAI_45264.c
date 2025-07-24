//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* str) {
    int len = strlen(str);
    int mid = len / 2;
    int i, j;
    for(i = 0, j = len - 1; i <= mid && j >= mid; i++, j--) {
        if(str[i] == str[j]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if(isPalindrome(input)) {
        printf("%s is a palindrome!\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    return 0;
}