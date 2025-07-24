//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to remove all non alphanumeric characters and convert uppercase to lowercase
void clean(char str[]) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

int isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    clean(input);

    if (isPalindrome(input)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}