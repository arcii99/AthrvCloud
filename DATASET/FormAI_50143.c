//FormAI DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to beautify HTML code
char* beautify_html(char* html) {
    int indent_level = 0;
    char* beautified_html = malloc(strlen(html) * 2);
    char* current_position = beautified_html;
    char current_char, previous_char = '\0';

    while (*html) {
        current_char = *html++;

        if (previous_char == '<') {
            if (current_char != '/') {
                // opening tag
                for (int i = 0; i < indent_level; i++) {
                    *current_position++ = '\t';
                }
                indent_level++;
                *current_position++ = '<';
                *current_position++ = current_char;
                *current_position++ = '\n';
            } else {
                // closing tag
                indent_level--;
                for (int i = 0; i < indent_level; i++) {
                    *current_position++ = '\t';
                }
                *current_position++ = '<';
                *current_position++ = current_char;
                *current_position++ = '\n';
            }
        } else if (previous_char == '>') {
            // content within the tag
            if (current_char != '<') {
                for (int i = 0; i < indent_level; i++) {
                    *current_position++ = '\t';
                }
                strcpy(current_position, html - 1);
                while (*current_position != '<') {
                    current_position++;
                }
                current_position--;
                *current_position++ = '\n';
            }
        }

        previous_char = current_char;
    }

    // add null terminator to the end
    *current_position = '\0';

    return beautified_html;
}

int main() {
    // test the function
    char* html = "<html><head><meta charset=\"UTF-8\"><title>My Website</title></head><body><h1>Welcome to my website</h1><p>This is some sample text</p></body></html>";
    char* beautified_html = beautify_html(html);

    printf("%s", beautified_html);

    free(beautified_html);
    return 0;
}