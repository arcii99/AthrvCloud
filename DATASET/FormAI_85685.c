//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include <stdio.h>
#include <string.h>

// Function to check if a given string is a palindrome or not
int isPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a string to check: ");

    char str[100];
    fgets(str, 100, stdin);

    // remove newline character at the end of input
    str[strcspn(str, "\n")] = 0;

    int check = isPalindrome(str);
    if (check == 1) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome :(\n", str);
    }

    printf("Thank you for using the Palindrome Checker!\n");
    return 0;
}