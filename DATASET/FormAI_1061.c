//FormAI DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
bool is_valid_syntax(char syntax[]);
void parse_syntax(char syntax[]);

int main() {
    char syntax[100];

    printf("Enter C syntax: ");
    fgets(syntax, 100, stdin);

    // Remove newline character from input string
    syntax[strcspn(syntax, "\n")] = '\0';

    if(is_valid_syntax(syntax)) {
        printf("Syntax is valid.\n");
        parse_syntax(syntax);
    }
    else {
        printf("Invalid syntax.\n");
    }

    return 0;
}

bool is_valid_syntax(char syntax[]) {
    int length = strlen(syntax);

    // Check for opening and closing parentheses
    if(syntax[0] != '(' || syntax[length-1] != ')') {
        return false;
    }

    // Check that parentheses are balanced and correctly nested
    int count = 0;
    for(int i=0; i<length; i++) {
        if(syntax[i] == '(') {
            count++;
        }
        else if(syntax[i] == ')') {
            count--;
        }
        if(count < 0) {
            return false;
        }
    }

    // If parentheses are balanced and nested correctly, syntax is valid
    return count == 0;
}

void parse_syntax(char syntax[]) {
    printf("Parsing syntax...\n");

    // Your handling code for correctly formed C syntax goes here
    // For example:
    printf("Declaration statement found.\n");
    printf("Identifer: %s\n", "example_variable");
    printf("Type: %s\n", "int");
}