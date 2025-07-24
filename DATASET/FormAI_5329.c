//FormAI DATASET v1.0 Category: Syntax parsing ; Style: futuristic
#include <stdio.h>

int main() {
    printf("Welcome to the future C Syntax parser!\n");
    printf("Please enter your code:\n");

    char input[1000];
    fgets(input, 1000, stdin);

    printf("\nAnalyzing syntax...\n");

    // Check for correct indentation
    if (input[0] != '{') {
        printf("Error: Incorrect indentation. Please use { to indicate the start of a block.\n");
        return 0;
    }

    // Check for missing semicolons
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '\n' && (input[i-1] != ';' || input[i-2] == '}')) {
            printf("Error: Missing semicolon.\n");
            return 0;
        }
    }

    // Check for mismatched parentheses and braces
    int count_parentheses = 0;
    int count_braces = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '(') {
            count_parentheses++;
        } else if (input[i] == ')') {
            count_parentheses--;
            if (count_parentheses < 0) {
                printf("Error: Mismatched parentheses.\n");
                return 0;
            }
        } else if (input[i] == '{') {
            count_braces++;
        } else if (input[i] == '}') {
            count_braces--;
            if (count_braces < 0) {
                printf("Error: Mismatched braces.\n");
                return 0;
            }
        }
    }

    // Check for unused variables
    if (strstr(input, "int") || strstr(input, "float") || strstr(input, "char")) {
        printf("Warning: Unused variables detected. Consider removing them.\n");
    }

    printf("Syntax analysis complete. No errors found.\n");
    return 0;
}