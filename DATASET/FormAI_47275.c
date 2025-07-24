//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of an HTML tag
#define MAX_TAG_LENGTH 100

// Define a data structure for a token
typedef struct Token {
    char type[MAX_TAG_LENGTH];
    char value[MAX_TAG_LENGTH];
} Token;

// Define a function to tokenize an HTML string
Token* tokenize(const char* input) {
    // Allocate memory for the tokens array
    Token* tokens = malloc(sizeof(Token) * strlen(input));

    // Initialize the index and the length variables
    int index = 0;
    int length = strlen(input);

    // Loop through the input string and tokenize it
    while (index < length) {
        // Allocate memory for the token
        Token* token = malloc(sizeof(Token));

        // Initialize the type and value variables
        char type[MAX_TAG_LENGTH] = "";
        char value[MAX_TAG_LENGTH] = "";

        // Check if the current character is a tag
        if (input[index] == '<') {
            // Add the opening tag symbol
            strcat(type, "<");

            // Move to the next character
            index++;

            // Loop through the characters until the tag is complete
            while (input[index] != '>' && index < length) {
                // Add the current character to the type variable
                strncat(type, &input[index], 1);

                // Move to the next character
                index++;
            }

            // Add the closing tag symbol
            strcat(type, ">");

            // Set the value to the empty string
            strcpy(value, "");
        } else {
            // Loop through the characters until the next tag
            while (input[index] != '<' && index < length) {
                // Add the current character to the value variable
                strncat(value, &input[index], 1);

                // Move to the next character
                index++;
            }

            // Set the type to the empty string
            strcpy(type, "");
        }

        // Set the type and value of the token
        strcpy(token->type, type);
        strcpy(token->value, value);

        // Add the token to the tokens array
        tokens[index] = *token;

        // Move to the next character
        index++;
    }

    // Return the tokens array
    return tokens;
}

// Define a function to beautify the HTML tags
char* beautify(const char* input) {
    // Tokenize the input string
    Token* tokens = tokenize(input);

    // Allocate memory for the output string
    char* output = malloc(sizeof(char) * strlen(input) * 2);

    // Initialize the indentation level variable
    int indentation_level = 0;

    // Loop through the tokens and beautify the HTML tags
    for (int i = 0; i < strlen(input); i++) {
        // Check if the current token is an opening tag
        if (tokens[i].type[0] == '<' && tokens[i].type[1] != '/') {
            // Indent the tag
            for (int j = 0; j < indentation_level; j++) {
                strcat(output, "\t");
            }

            // Add the opening tag to the output string
            strcat(output, tokens[i].type);
            strcat(output, "\n");

            // Increment the indentation level
            indentation_level++;
        }
        // Check if the current token is a closing tag
        else if (tokens[i].type[0] == '<' && tokens[i].type[1] == '/') {
            // Decrement the indentation level
            indentation_level--;

            // Indent the tag
            for (int j = 0; j < indentation_level; j++) {
                strcat(output, "\t");
            }

            // Add the closing tag to the output string
            strcat(output, tokens[i].type);
            strcat(output, "\n");
        }
        // Otherwise, add the value of the token to the output string
        else {
            // Indent the tag
            for (int j = 0; j < indentation_level; j++) {
                strcat(output, "\t");
            }

            // Add the value of the token to the output string
            strcat(output, tokens[i].value);
            strcat(output, "\n");
        }
    }

    // Free the memory used by the tokens array
    free(tokens);

    // Return the beautified HTML string
    return output;
}

// Define the main function
int main() {
    // Define the input string
    const char* input = "<html>\n"
                        "<head>\n"
                        "<title>My Website</title>\n"
                        "</head>\n"
                        "<body>\n"
                        "<h1>Welcome to my website!</h1>\n"
                        "<p>This is my first website.</p>\n"
                        "</body>\n"
                        "</html>\n";

    // Beautify the HTML string
    char* output = beautify(input);

    // Print the beautified HTML string
    printf("%s", output);

    // Free the memory used by the output string
    free(output);

    // Return 0 to indicate success
    return 0;
}