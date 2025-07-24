//FormAI DATASET v1.0 Category: Text processing ; Style: decentralized
// This is a decentralized C program that takes in a string, determines the length of the string, and checks if it is a palindrome.
// The program is built using functions and allows for easy modification.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to determine length of string
int stringLength(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Function to check if string is a palindrome
int isPalindrome(char* str) {
    int len = stringLength(str);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Reading string from user input
    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);

    // Checking if string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }

    return 0;
}