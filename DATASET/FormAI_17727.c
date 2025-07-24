//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i=0; i<len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    // Remove newline character from input
    str[strcspn(str, "\n")] = '\0';
    if (is_palindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}