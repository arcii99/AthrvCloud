//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 255

int main() {
    char input[MAX_LENGTH];

    printf("Enter C Syntax code to parse:\n");

    fgets(input, MAX_LENGTH, stdin); // Allow spaces in input

    char* token = strtok(input, " "); // Tokenize by spaces
    int is_valid_syntax = 1; // Flag for validity

    while(token != NULL) {
        // Check for main function
        if(strcmp(token, "int") == 0 || strcmp(token, "void") == 0) {
            token = strtok(NULL, " ");
            if(token != NULL && strcmp(token, "main") == 0) {
                token = strtok(NULL, " ");
                if(token != NULL && strcmp(token, "(") == 0) {
                    token = strtok(NULL, " ");
                    if(token != NULL && strcmp(token, "void") == 0) {
                        token = strtok(NULL, " ");
                        if(token != NULL && strcmp(token, ")") == 0) {
                            token = strtok(NULL, " ");
                            if(token != NULL && strcmp(token, "{") == 0) {
                                // Main function found
                                printf("Valid C Syntax!\n");
                                is_valid_syntax = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }

        // Check for semicolon at end of line
        if(strlen(token) > 0 && token[strlen(token) - 1] == ';') {
            token[strlen(token) - 1] = '\0'; // Remove semicolon
        } else {
            printf("Invalid C Syntax! Expected semicolon.\n");
            is_valid_syntax = 0;
            break;
        }

        // Check for variable declaration
        if(strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0) {
            token = strtok(NULL, " ");
            if(token == NULL) {
                printf("Invalid C Syntax! Expected variable name.\n");
                is_valid_syntax = 0;
                break;
            } else {
                int square_brackets = 0;
                for(int i = 0; i < strlen(token); i++) {
                    if(token[i] == '[') {
                        square_brackets++;
                    } else if(token[i] == ']') {
                        square_brackets--;
                    }
                }
                if(square_brackets < 0) {
                    printf("Invalid C Syntax! Mismatched square brackets.\n");
                    is_valid_syntax = 0;
                    break;
                }
                if(square_brackets > 0) {
                    printf("Invalid C Syntax! Expected closing square bracket.\n");
                    is_valid_syntax = 0;
                    break;
                }
            }
        }

        // Check for variable initialization
        if(strcmp(token, "=") == 0) {
            token = strtok(NULL, " ");
            if(token == NULL) {
                printf("Invalid C Syntax! Expected value.\n");
                is_valid_syntax = 0;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    if(is_valid_syntax) {
        printf("Valid C Syntax!\n");
    }

    return 0;
}