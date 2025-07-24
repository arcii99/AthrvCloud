//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[], int start, int end) {
    if(start >= end) {
        return 1;
    }
    if(tolower(str[start]) != tolower(str[end])) {
        return 0;
    }
    return isPalindrome(str, start+1, end-1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    if(isPalindrome(str, 0, strlen(str)-1)) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }
    return 0;
}