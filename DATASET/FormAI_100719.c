//FormAI DATASET v1.0 Category: Data validation ; Style: minimalist
#include <stdio.h>
#include <ctype.h>

#define MIN_LENGTH 5    // Minimum length of the input string
#define MAX_LENGTH 20   // Maximum length of the input string

int main() {
    char input[MAX_LENGTH + 1];  // Input string with null terminator
    int i, uppercase_count = 0, lowercase_count = 0, digit_count = 0;
    char c;

    printf("Enter a string of length %d-%d: ", MIN_LENGTH, MAX_LENGTH);
    fgets(input, MAX_LENGTH + 1, stdin);    // Read input string

    // Check length of input string
    if (input[MAX_LENGTH] != '\0') {
        printf("Error: Input string exceeded maximum length of %d\n", MAX_LENGTH);
        return 1;
    }
    else if (input[0] == '\n') {
        printf("Error: Input string is empty\n");
        return 1;
    }
    else if (strlen(input) < MIN_LENGTH + 1) {    // Check for newline character
        printf("Error: Input string must have at least %d characters\n", MIN_LENGTH);
        return 1;
    }

    // Count number of uppercase, lowercase and digit characters
    for (i = 0; input[i] != '\0'; i++) {
        c = input[i];
        if (isdigit(c)) {
            digit_count++;
        }
        else if (isupper(c)) {
            uppercase_count++;
        }
        else if (islower(c)) {
            lowercase_count++;
        }
    }

    // Check that input string contains at least one of each character type
    if (digit_count == 0) {
        printf("Error: Input string must contain at least one digit\n");
        return 1;
    }
    else if (uppercase_count == 0) {
        printf("Error: Input string must contain at least one uppercase character\n");
        return 1;
    }
    else if (lowercase_count == 0) {
        printf("Error: Input string must contain at least one lowercase character\n");
        return 1;
    }

    printf("Input string is valid\n");
    return 0;
}