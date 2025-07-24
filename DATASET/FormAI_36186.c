//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>

void check_palindrome(char *str) {
    int len = strlen(str);
    int i = 0, j = len - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            printf("%s is not a Palindrome.\n", str);
            return;
        }
        i++;
        j--;
    }

    printf("%s is a Palindrome.\n", str);
}

int main() {
    char str[100];

    printf("Enter a string to check if it's a Palindrome: ");
    fgets(str, sizeof(str), stdin);

    // remove trailing newline character from input string
    str[strcspn(str, "\n")] = '\0';

    check_palindrome(str);

    return 0;
}