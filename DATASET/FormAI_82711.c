//FormAI DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <string.h>

// This C program takes an input string and manipulates it in a puzzling way.
// It reverses the words in the string, but keeps the letters in each word in the correct order.
// For example, "Hello, World!" becomes "olleH, dlroW!"

// Function to reverse a string in-place
void reverse(char str[], int len) {
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to reverse the words in a string
void reverseWords(char str[]) {
    int len = strlen(str);
    int i, j;
    reverse(str, len);

    // Reverse each word in the string
    for (i = j = 0; i < len; i++) {
        if (str[i] == ' ') {
            // Reverse the current word
            reverse(str + j, i - j);
            j = i + 1;
        }
    }

    // Reverse the last word in the string
    reverse(str + j, i - j);
}

int main() {
    // Input string
    char str[] = "Hello, World!";

    printf("Original string: %s\n", str);

    // Reverse the words in the string
    reverseWords(str);

    // Output the manipulated string
    printf("Manipulated string: %s\n", str);

    return 0;
}