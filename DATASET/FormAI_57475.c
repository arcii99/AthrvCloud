//FormAI DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for an input line
#define MAX_LINE_LENGTH 100

// Define token types
typedef enum {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    SEPARATOR,
    ERROR
} token_type;

// Define a token structure
typedef struct {
    token_type type;
    char value[MAX_LINE_LENGTH];
} token;

// Define a function to determine if a character is a separator
int is_separator(char c) {
    char separators[] = { '(', ')', '{', '}', '[', ']', ';', ',' };
    int num_separators = sizeof(separators) / sizeof(separators[0]);
    for (int i = 0; i < num_separators; i++) {
        if (c == separators[i]) return 1;
    }
    return 0;
}

// Define a function to determine if a character is an operator
int is_operator(char c) {
    char operators[] = { '+', '-', '*', '/', '=', '<', '>', '!' };
    int num_operators = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < num_operators; i++) {
        if (c == operators[i]) return 1;
    }
    return 0;
}

// Define a function to determine if a string is a keyword
int is_keyword(char* s) {
    char keywords[][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(s, keywords[i]) == 0) return 1;
    }
    return 0;
}

// Define a function to get the next token
token get_token(char* input) {
    token t;
    t.type = ERROR;
    int i = 0;
    // Skip whitespace
    while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') i++;
    // Check for end of input
    if (input[i] == '\0') return t;
    // Check for separators
    if (is_separator(input[i])) {
        t.type = SEPARATOR;
        t.value[0] = input[i];
        t.value[1] = '\0';
        return t;
    }
    // Check for operators
    if (is_operator(input[i])) {
        t.type = OPERATOR;
        t.value[0] = input[i];
        i++;
        // Check for two-character operators
        if (is_operator(input[i])) {
            t.value[1] = input[i];
            t.value[2] = '\0';
            return t;
        }
        t.value[1] = '\0';
        return t;
    }
    // Check for numbers
    if (isdigit(input[i])) {
        t.type = NUMBER;
        int j = 0;
        while (isdigit(input[i])) {
            t.value[j] = input[i];
            i++; j++;        
        }
        t.value[j] = '\0';
        return t;
    }
    // Check for identifiers or keywords
    if (isalpha(input[i]) || input[i] == '_') {
        t.type = IDENTIFIER;
        int j = 0;
        while (isalpha(input[i]) || isdigit(input[i]) || input[i] == '_') {
            t.value[j] = input[i];
            i++; j++;        
        }
        t.value[j] = '\0';
        if (is_keyword(t.value)) t.type = KEYWORD;
        return t;
    }
    // Return error token if all checks fail
    return t;
}

// Main function
int main() {
    char input[MAX_LINE_LENGTH];
    int i;
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);
    // Process each token
    while (1) {
        token t = get_token(input);
        if (t.type == ERROR) {
            printf("Error: invalid input\n");
            break;
        }
        printf("Type: %d, Value: %s\n", t.type, t.value);
        // Move the input pointer forward
        i = 0;
        while (input[i] != '\0') i++;
        i--;
        while (i >= 0 && input[i] == ' ' || input[i] == '\t' || input[i] == '\n') i--;
        input[i+1] = '\0';
        if (i < 0) break;
    }
    return 0;
}