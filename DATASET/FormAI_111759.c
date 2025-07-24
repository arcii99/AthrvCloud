//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>

int main() {
    char program[1000], c;
    int i = 0;

    printf("Enter C program:\n");

    while ((c = getchar()) != EOF) {
        program[i++] = c;
    }
    program[i] = '\0';

    // Parse program
    int braces = 0, brackets = 0, parentheses = 0, quotes = 0, single_quotes = 0, comments = 0;

    for (int i = 0; program[i] != '\0'; i++) {
        if (program[i] == '{') braces++;
        else if (program[i] == '}') braces--;

        if (program[i] == '[') brackets++;
        else if (program[i] == ']') brackets--;

        if (program[i] == '(') parentheses++;
        else if (program[i] == ')') parentheses--;

        if (program[i] == '\"' && program[i-1] != '\\') quotes++;

        if (program[i] == '\'' && program[i-1] != '\\') {
            if (single_quotes == 1) single_quotes--;
            else single_quotes++;
        }

        if (program[i] == '/' && program[i+1] == '/') comments++;
        else if (program[i] == '/' && program[i+1] == '*') comments++;
        else if (program[i] == '*' && program[i+1] == '/') comments--;
    }

    // Check for errors
    if (braces != 0) printf("Missing curly braces\n");
    if (brackets != 0) printf("Missing square brackets\n");
    if (parentheses != 0) printf("Missing parentheses\n");
    if (quotes % 2 != 0) printf("Missing quotes\n");
    if (single_quotes % 2 != 0) printf("Missing single quotes\n");
    if (comments != 0) printf("Missing or extra comments\n");

    return 0;
}