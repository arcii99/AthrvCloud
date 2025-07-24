//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove special characters from a given string
char* remove_special_chars(char* string) {
    int i, j = 0;
    char* temp = malloc(strlen(string) + 1);
    for (i = 0; string[i] != '\0'; i++) {
        if (isalnum(string[i])) {
            temp[j++] = string[i];
        }
    }
    temp[j] = '\0';
    return temp;
}

int main() {
    // Prompting the user to input a string
    printf("Enter a string: ");
    char input[100];
    fgets(input, 100, stdin);

    // Sanitizing the user input
    char* sanitized_input = remove_special_chars(input);

    // Printing the sanitized input
    printf("\nSanitized Input: %s", sanitized_input);

    // Freeing the dynamically allocated memory
    free(sanitized_input);

    // Exiting the program
    return 0;
}