//FormAI DATASET v1.0 Category: HTML beautifier ; Style: introspective
/* This program beautifies HTML code inputted by the user.
   It parses through the input and adds indentation and newlines
   to create a more human-readable output. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

int main() {
    char input[1000], output[10000], *curr_output_ptr = output;
    char curr_tag[1000] = "", last_tag[1000] = "";
    int tag_indent = -1, print_indent = 0, in_tag = 0;

    // Get user input
    printf("Enter HTML code:\n");
    fgets(input, 1000, stdin);

    // Parse through input
    for (int i = 0; input[i] != '\0'; i++) {
        // Check for opening or closing tags
        if (input[i] == '<') {
            in_tag = 1;
            memset(curr_tag, 0, sizeof(curr_tag));
            tag_indent++;

            // Check if this is a closing tag
            if (input[i+1] == '/') {
                tag_indent--;
                print_indent = tag_indent * TAB_SIZE;
            }
        }
        else if (input[i] == '>') {
            in_tag = 0;
            if (strcmp(curr_tag, last_tag) == 0) {
                print_indent = tag_indent * TAB_SIZE;
            } else {
                print_indent = (tag_indent-1) * TAB_SIZE;
                strcpy(last_tag, curr_tag);
            }
            *curr_output_ptr++ = input[i];
            *curr_output_ptr++ = '\n';
            for (int j = 0; j < print_indent; j++) {
                *curr_output_ptr++ = ' ';
            }
        }
        else if (in_tag) {
            // Build tag string
            strncat(curr_tag, &input[i], 1);
        }

        // Print character to output
        *curr_output_ptr++ = input[i];
    }

    // Print formatted output
    printf("\nFormatted code:\n%s", output);

    return 0;
}