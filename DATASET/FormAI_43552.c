//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    printf("My love, please enter a word or sentence that you want me to check for palindrome: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    if (is_palindrome(str)) {
        printf("\nMy love, this is a palindrome! Your love for me is as pure and unchanging as this word. ❤️\n");
    } else {
        printf("\nMy love, this is not a palindrome. But, my love for you is as strong as ever. ❤️\n");
    }

    return 0;
}