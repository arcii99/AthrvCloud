//FormAI DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given character is an operator
int is_operator(char c)
{
    char operators[] = "+-*/=><&|!%"; 
    for (int i = 0; i < strlen(operators); i++) {
        if (c == operators[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a given string is a keyword
int is_keyword(char* str)
{
    char keywords[][10] = {"int", "char", "float", "double", "if", "else", "for", "while", "do", "switch", "case", "break", "continue", "return"};
    int count = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < count; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char input[1000];   // Maximum input length
    printf("Enter c syntax to be parsed:\n");
    fgets(input, 1000, stdin);   // Get input from user

    char token[100];    // Maximum token length
    int index = 0;      // Current index in input string
    int token_index = 0;    // Current index in token string

    // Loop through input string character by character
    while (input[index] != '\0') {
        if (input[index] == ' ' || input[index] == '\n' || input[index] == '\t') {
            // Skip whitespace
        } 
        else if (is_operator(input[index])) {
            // If current character is an operator
            token[token_index] = input[index];
            token_index++;
        }
        else {
            // If current character is not an operator
            while (input[index] != ' ' && input[index] != '\n' && input[index] != '\t' && input[index] != '\0' && !is_operator(input[index])) {
                // Keep adding characters to token until we hit whitespace or an operator
                token[token_index] = input[index];
                index++;
                token_index++;
            }
            token[token_index] = '\0'; // Add null character to end of token string to signify end of string
            if (is_keyword(token)) {
                printf("%s is a keyword\n", token);
            }
            else {
                printf("%s is an identifier\n", token);
            }
            token_index = 0; // Reset token index for next token
            continue; // Skip the current character since we already added it to the token
        }
        index++; // Move on to next character in input string
    }
    return 0;
}