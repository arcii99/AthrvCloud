//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if given character is a whitespace
bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Function to check if given character is a letter
bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if given character is a digit
bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to beautify HTML code
void beautify_html(char* code) {
    int indent = 0;

    for (int i = 0; code[i]; i++) {
        if (code[i] == '<') {
            if (code[i+1] == '/') {
                indent--;
            }

            for (int j = 0; j < indent; j++) {
                putchar('\t');
            }

            putchar(code[i]);
            
            if (code[i+1] != '!') {
                indent++;
            }

            if (code[i+1] == '/') {
                indent--;
            }

            putchar('\n');
        } else if (code[i] == '>') {
            putchar(code[i]);
            putchar('\n');
        } else if (is_whitespace(code[i])) {
            if (code[i] == '\n') {
                putchar('\n');
            }
            
            continue;
        } else {
            putchar(code[i]);
        }
    }
}

int main() {
    char* code = "<html><head><title>Beautified HTML</title></head><body><h1>Welcome to the beautifier!</h1></body></html>";
    
    beautify_html(code);
    
    return 0;
}