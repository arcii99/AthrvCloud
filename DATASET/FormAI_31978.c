//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to sanitize user input
char* sanitize(char* input) {
    int len = strlen(input);
    char* result = (char*) malloc((len + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(input[i])) { // checks if character is alphanumeric
            result[j++] = tolower(input[i]); // makes character lowercase and adds it to result
        }
    }
    result[j] = '\0'; // adds null terminator to end of result
    return result;
}

int main() {
    char input[100];
    printf("Enter some input: ");
    fgets(input, sizeof(input), stdin); // gets input from user
    char* sanitized_input = sanitize(input); // sanitizes input
    printf("Sanitized Input: %s\n", sanitized_input);
    free(sanitized_input); // frees memory allocated for sanitized input
    return 0;
}