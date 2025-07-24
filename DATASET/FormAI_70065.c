//FormAI DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character is a whitespace
bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

// Function to remove whitespace from a string
void removeWhitespace(char* str) {
    int len = strlen(str);
    int i = 0, j = 0;

    // Traverse through the string
    for (i = 0; i < len; i++) {
        // If character is not a whitespace, save it
        if (!isWhitespace(str[i])) {
            str[j++] = str[i];
        }
    }

    // Terminate the string properly
    str[j] = '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove whitespace from the string
    removeWhitespace(str);

    printf("String without whitespace: %s\n", str);

    return 0;
}