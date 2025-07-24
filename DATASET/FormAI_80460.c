//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function to sanitize user input
void sanitizeInput(char input[]) {
    int len = strlen(input);
    char temp[MAX_LEN];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isalnum(input[i])) {
            if (isalpha(input[i])) {
                temp[j] = tolower(input[i]);
            } else {
                temp[j] = input[i];
            }
            j++;
        }
    }
    strncpy(input, temp, j);
}

// Main function
int main() {
    char input[MAX_LEN];

    printf("Enter user input: ");
    fgets(input, MAX_LEN, stdin);

    // Sanitize user input
    sanitizeInput(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}