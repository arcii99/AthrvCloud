//FormAI DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for HTML tags and characters
#define CLOSING_TAG '/'
#define OPENING_TAG '<'
#define CLOSING_ANGLE '>'
#define SPACE ' '
#define QUOTE '"'
#define SINGLE_QUOTE '\''

// Function to beautify HTML code
void beautify_html(char* html_code) {

    // Keep track of nested tags and indentation level
    int nested_tags = 0;
    int indent_level = 0;
    char* output = malloc(strlen(html_code) * 2); // Allocate memory for output string
    char* p = html_code; // Pointer to traverse the input string
    char* q = output; // Pointer to traverse the output string

    // Loop through every character in the input string
    while (*p != '\0') {

        // Check if character is an opening tag
        if (*p == OPENING_TAG) {

            // Indent for nested tags
            for (int i = 0; i < indent_level; i++) {
                *q++ = SPACE;
                *q++ = SPACE;
            }

            // Copy the opening tag
            *q++ = *p++;

            // Check if tag is a closing tag
            if (*p == CLOSING_TAG) {
                nested_tags--;
            } else {
                nested_tags++;
            }
        }

        // Check if character is a closing tag
        else if (*p == CLOSING_ANGLE && *(p - 1) == CLOSING_TAG) {

            // Unindent for nested tags
            nested_tags--;
            indent_level--;

            // Indent for nested tags
            for (int i = 0; i < indent_level; i++) {
                *q++ = SPACE;
                *q++ = SPACE;
            }

            // Copy the closing tag
            *q++ = CLOSING_TAG;
            *q++ = *p++;
            *q++ = CLOSING_ANGLE;
        }

        // Check if character is a space or quote
        else if (*p == SPACE || *p == QUOTE || *p == SINGLE_QUOTE) {

            // Copy the character
            *q++ = *p++;

            // Check if the previous character was also a space or quote
            if (*(q - 2) == SPACE || *(q - 2) == QUOTE || *(q - 2) == SINGLE_QUOTE) {
                continue; // Skip duplicate characters
            }

            // Indent for nested tags
            if (*(q - 2) == OPENING_TAG) {
                for (int i = 0; i < nested_tags; i++) {
                    *q++ = SPACE;
                    *q++ = SPACE;
                }
                indent_level += nested_tags;
            }
        }

        // Otherwise, copy the character
        else {
            *q++ = *p++;
        }
    }

    *q = '\0'; // Add null terminator to output string
    strcpy(html_code, output); // Copy output string back to input string
    free(output); // Release memory allocated for output string
}

int main() {

    // Sample HTML code to beautify
    char html_code[] = "<html><body><h1>Hello World!</h1><p>This is a sample paragraph.</p></body></html>";

    // Beautify the HTML code
    beautify_html(html_code);

    // Print the beautified HTML code
    printf("%s\n", html_code);

    return 0;
}