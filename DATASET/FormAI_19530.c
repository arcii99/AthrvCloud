//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 
 * This is a C program to check whether a given string is a palindrome or not.
 * A string is said to be a palindrome if it reads the same backward as forward.
 * This program is designed to ignore spaces, punctuations and case sensitivity.
 * This program uses the stack to store the characters of the string.
 * By: [Your Name], [Your Email], [Date]
 */

#define MAX 100

char stack[MAX];
int top = -1;

// Function for pushing a character into the stack
void push(char ch) {
    if (top >= MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    stack[++top] = ch;
}

// Function for popping a character from the stack
char pop() {
    if (top < 0) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return stack[top--];
}

// Function to check if a character is an alphabet or a digit
int isAlNum(char ch) {
    return isalpha(ch) || isdigit(ch);
}

// Function to convert a character to lowercase
char toLower(char ch) {
    return tolower(ch);
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    // Pushing the characters of the string to the stack
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (isAlNum(ch)) {
            push(toLower(ch));
        }
    }
    // Popping the characters from the stack and comparing with the input string
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (isAlNum(ch)) {
            if (toLower(ch) != pop()) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0; // Removing the newline character from the input string
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}