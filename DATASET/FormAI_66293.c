//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char string[50];
    int i, len, flag = 0;

    printf("Welcome to Palindrome Checker!");
    printf("\nEnter a string: ");
    scanf("%[^\n]", string);
    len = strlen(string);

    // Convert the string to lowercase
    for (i = 0; i < len; i++) {
        string[i] = tolower(string[i]);
    }

    // Check for palindrome
    for (i = 0; i < len/2; i++) {
        if (string[i] != string[len-i-1]) {
            flag = 1;
            break;
        }
    }

    // Print the result
    if (flag == 0) {
        printf("\n%s is a Palindrome!\n", string);
    }
    else {
        printf("\n%s is not a Palindrome!\n", string);
    }

    return 0;
}