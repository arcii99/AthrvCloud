//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, flag = 0;

    printf("Welcome to the Palindrome Checker!\n\n");
    printf("Please enter a string to check if it is a palindrome: ");
    scanf("%s", str);

    j = strlen(str) - 1;

    for (i = 0; i < j; i++, j--) {
        if (str[i] != str[j]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("\nThe string is not a palindrome.");
    } else {
        printf("\nThe string is a palindrome!");
    }

    printf("\n\nThank you for using Palindrome Checker. Have a great day!");
    
    return 0;
}