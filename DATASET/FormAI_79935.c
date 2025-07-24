//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

void reverseString(char* str);
void toUpper(char* str);
int countOccurrences(char* str, char c);
void removeChar(char* str, char c);
int isPalindrome(char* str);
void swap(char* a, char* b);

int main() {
    char str[MAX_STR_LEN];

    // Get user input
    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);
    str[strcspn(str, "\n")] = 0; // remove newline character from input

    // Reverse the string
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Convert to uppercase
    toUpper(str);
    printf("Uppercase string: %s\n", str);

    // Count occurrences of a character
    char c = 'E';
    int count = countOccurrences(str, c);
    printf("Number of occurrences of %c: %d\n", c, count);

    // Remove all occurrences of a character
    removeChar(str, c);
    printf("String with all occurrences of %c removed: %s\n", c, str);

    // Check if string is a palindrome
    int palindrome = isPalindrome(str);
    if(palindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

void reverseString(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        swap(&str[i], &str[len-i-1]);
    }
}

void toUpper(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= ('a'-'A');
        }
    }
}

int countOccurrences(char* str, char c) {
    int len = strlen(str);
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == c) {
            count++;
        }
    }
    return count;
}

void removeChar(char* str, char c) {
    int len = strlen(str);
    int j = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] != c) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int isPalindrome(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        if(str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}