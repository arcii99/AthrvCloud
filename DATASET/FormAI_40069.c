//FormAI DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>

int main() {
    // Greet the user
    printf("Welcome to the C Syntax parsing program!\n");

    // Ask the user for input
    printf("Please enter some C syntax code:\n");

    // Read in the user's code
    char code[100];
    fgets(code, 100, stdin);

    // Parse the code
    int brackets = 0;
    int parentheses = 0;
    int braces = 0;
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '{') {
            braces++;
        } else if (code[i] == '}') {
            braces--;
        } else if (code[i] == '(') {
            parentheses++;
        } else if (code[i] == ')') {
            parentheses--;
        } else if (code[i] == '[') {
            brackets++;
        } else if (code[i] == ']') {
            brackets--;
        }
    }

    // Print the results
    if (brackets == 0 && parentheses == 0 && braces == 0) {
        printf("Your code is syntactically correct, hooray!\n");
    } else {
        printf("Uh oh, your code is syntactically incorrect. Please check your brackets, parentheses, and braces.\n");
    }

    // Say goodbye
    printf("Thanks for using the C Syntax parsing program. Happy coding!\n");

    return 0;
}