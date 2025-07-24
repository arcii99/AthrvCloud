//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void toLowercase(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int isPalindrome(char *str) {
    int length = strlen(str);
    for(int i = 0, j = length-1; i < j; i++, j--) {
        if(str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove new line character from fgets
    int length = strlen(str);
    if(str[length-1] == '\n') {
        str[length-1] = '\0';
    }

    // Convert string to lowercase
    toLowercase(str);

    // Check if string is palindrome
    if(isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    }
    else {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}