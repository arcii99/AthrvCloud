//FormAI DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin); // read string from user input

    // check if string is palindrome
    int isPalindrome = 1;
    int n = strlen(str);
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n-i-2]) {
            isPalindrome = 0;
            break;
        }
    }

    // analyze the string
    int upper = 0, lower = 0, digits = 0, special = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            upper++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            lower++;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        }
        else {
            special++;
        }
    }

    // print results
    printf("\nThe string is: %s", str);
    printf("\nLength of the string: %d", n-1);
    if (isPalindrome) {
        printf("\nThe string is a palindrome");
    }
    else {
        printf("\nThe string is not a palindrome");
    }
    printf("\nNumber of uppercase letters: %d", upper);
    printf("\nNumber of lowercase letters: %d", lower);
    printf("\nNumber of digits: %d", digits);
    printf("\nNumber of special characters: %d", special);

    return 0;
}