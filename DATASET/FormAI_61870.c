//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN], output[MAX_LEN];
    int i, j;

    // Get user input
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    // Remove newline character from input if it exists
    if(input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Remove leading and trailing whitespace from input
    while(isspace(input[0])) {
        strcpy(input, input + 1);
    }
    while(isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Sanitize input string by replacing all non-alphanumeric characters with underscores
    for(i = 0, j = 0; i < strlen(input); i++, j++) {
        if(isalnum(input[i])) {
            output[j] = input[i];
        }
        else {
            output[j] = '_';
        }
    }
    output[j] = '\0';

    // Print sanitized input string
    printf("Sanitized input string: %s\n", output);

    return 0;
}