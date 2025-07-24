//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void toLowerCase(char* str) {
    // Function to convert a string to lower case
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int isPalindrome(char* str) {
    // Function to check if a given string is palindrome
    int len = strlen(str);
    if (len == 0) {
        return 1;
    }
    char* start = str;
    char* end = &str[len - 1];
    while (end > start) {
        if (*start != *end) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter the string to check if it is a palindrome: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline from input

    toLowerCase(str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}