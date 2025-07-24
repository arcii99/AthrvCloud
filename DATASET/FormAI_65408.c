//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>

int main() {

    printf("Welcome to the C User Input Sanitizer Program!\n");
    printf("Enter any word or sentence:\n");
    
    char input[1000];
    fgets(input, 1000, stdin);

    printf("\nOriginal Input: %s", input);

    // User input sanitizer
    int i = 0;
    while (input[i]) {
        if (isalnum(input[i])) {
            input[i] = tolower(input[i]);
        }
        else if (isspace(input[i])) {
            input[i] = ' ';
        }
        else {
            input[i] = '\0';
        }
        i++;
    }

    printf("Sanitized Input: %s\n", input);

    printf("\nThank you for using the C User Input Sanitizer Program!\n");
    return 0;
}