//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char string[100];

    printf("Enter a string to check if it's a palindrome: \n");
    scanf("%s", string);

    int length = strlen(string);
    bool isPalindrome = true;

    for (int i = 0; i < length/2; i++) {
        if (string[i] != string[length-i-1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        printf("Holy Guacamole! The string you entered is a palindrome! Mind blowing, right?");
    } else {
        printf("Are you kidding me? The string you entered is not a palindrome! Pls try again.");
    }

    return 0;
}