//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: automated
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int length, i, palindrome = 1;

    printf("Enter a string: ");
    scanf("%s", string);

    length = strlen(string);

    for (i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            palindrome = 0;
            break;
        }
    }

    if (palindrome == 1) {
        printf("%s is a palindrome", string);
    } else {
        printf("%s is not a palindrome", string);
    }

    return 0;
}