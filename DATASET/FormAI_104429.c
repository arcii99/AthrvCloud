//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {

    char str[100];
    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, 100, stdin);

    if (isPalindrome(str)) {
        printf("Wow! The string entered by you is a Palindrome!\n");
    } else {
        printf("Oops! The string entered by you is not a Palindrome.\n");
    }
    return 0;
}