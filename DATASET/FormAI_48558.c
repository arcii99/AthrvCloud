//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int main() {
    char str[MAX];
    int i, j, len;
    int palin = 1;
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    // Removing the newline character added by fgets
    str[strcspn(str, "\n")] = '\0';
    // Removing all the spaces and punctuation in the string
    for (i = 0; i < strlen(str); i++) {
        if (ispunct(str[i]) || isspace(str[i])) {
            for (j = i; j < strlen(str); j++) {
                str[j] = str[j + 1];
            }
            i--;
        } else {
            str[i] = tolower(str[i]);
        }
    }
    len = strlen(str);
    // Checking for palindrome
    for (i = 0; i < len/2; i++) {
        if (str[i] != str[len - i - 1]) {
            palin = 0;
            break;
        }
    }
    // Printing the result
    if (palin) {
        printf("%s is a palindrome.", str);
    } else {
        printf("%s is not a palindrome.", str);
    }
    return 0;
}