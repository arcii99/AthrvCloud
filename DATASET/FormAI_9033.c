//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <string.h>

int check_palindrome(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (end > start) {
        if (str[start++] != str[end--]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    printf("Enter a word or phrase to check if it's a palindrome: ");
    fgets(input, 100, stdin);
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }
    int is_palindrome = check_palindrome(input);
    if (is_palindrome) {
        printf("%s is a palindrome!\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    return 0;
}