//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>

void main() {
    char string[100];
    int length, i, j, flag = 0;
    printf("Welcome to Palindrome Checker!\n");
    printf("Enter a string: ");
    scanf("%s", string);
    length = strlen(string);
    for (i = 0, j = length - 1; i < length / 2; i++, j--) {
        if (string[i] != string[j]) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("'%s' is not a palindrome.\n", string);
    } else {
        printf("'%s' is a palindrome!\n", string);
    }
    printf("Thank you for using Palindrome Checker!");
}