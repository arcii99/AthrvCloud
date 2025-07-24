//FormAI DATASET v1.0 Category: Syntax parsing ; Style: post-apocalyptic
#include <stdio.h>

// Post-apocalyptic C syntax parsing program
int main() {
    printf("Welcome to the post-apocalyptic C syntax parsing program.\n");
    printf("Enter some C code to analyze:\n\n");

    char input[1000];
    fgets(input, 1000, stdin);

    printf("\nAnalyzing your input...\n\n");

    // Begin parsing input
    int i = 0;
    int line_count = 1;
    char current_char = input[i];

    while (current_char != '\0') {
        // Ignore whitespace characters
        if (current_char == ' ' || current_char == '\t') {
            i++;
            current_char = input[i];
            continue;
        }

        // Check for newline character
        if (current_char == '\n') {
            line_count++;
        }

        // Check for comment syntax
        if (current_char == '/' && input[i+1] == '/') {
            printf("Comment found on line %d.\n", line_count);
            printf("Content: ");
            i += 2;
            current_char = input[i];
            while (current_char != '\n') {
                printf("%c", current_char);
                i++;
                current_char = input[i];
            }
            printf("\n\n");
            line_count++;
            continue;
        }

        // Check for variable declaration syntax
        if ((current_char >= 'a' && current_char <= 'z') || (current_char >= 'A' && current_char <= 'Z')) {
            printf("Variable declaration found on line %d.\n", line_count);
            printf("Name: %c", current_char);
            i++;
            current_char = input[i];
            while ((current_char >= 'a' && current_char <= 'z') || (current_char >= 'A' && current_char <= 'Z') || (current_char >= '0' && current_char <= '9') ||  current_char == '_') {
                printf("%c", current_char);
                i++;
                current_char = input[i];
            }
            printf("\n\n");
            line_count++;
            continue;
        }

        // Check for function call syntax
        if (current_char >= 'a' && current_char <= 'z') {
            printf("Function call found on line %d.\n", line_count);
            printf("Name: %c", current_char);
            i++;
            current_char = input[i];
            while ((current_char >= 'a' && current_char <= 'z') || (current_char >= 'A' && current_char <= 'Z') || (current_char >= '0' && current_char <= '9') || current_char == '_') {
                printf("%c", current_char);
                i++;
                current_char = input[i];
            }
            printf("\n\n");
            line_count++;
            continue;
        }

        // Check for operator syntax
        if (current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/' || current_char == '=') {
            printf("Operator found on line %d.\n", line_count);
            printf("Symbol: %c\n\n", current_char);
            i++;
            current_char = input[i];
            continue;
        }

        // If we get to this point, we have found an unrecognized syntax element
        printf("Unrecognized syntax element found on line %d.\n", line_count);
        i++;
        current_char = input[i];
    }

    printf("Parsing complete.\n");

    return 0;
}