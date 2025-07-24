//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <ctype.h>

#define MAX_HTML_SIZE 10000 // Maximum size of the input HTML file.

int main() {
    char html[MAX_HTML_SIZE];
    int indent_level = 0;
    int inside_tag = 0;

    // Open the input HTML file.
    FILE *input = fopen("input.html", "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read the input HTML file into the html array.
    int i = 0;
    char c;
    while ((c = fgetc(input)) != EOF && i < MAX_HTML_SIZE) {
        html[i] = c;
        i++;
    }
    html[i] = '\0';

    // Close the input HTML file.
    fclose(input);

    // Open the output HTML file.
    FILE *output = fopen("output.html", "w");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    // Loop through each character in the html array.
    for (i = 0; html[i] != '\0'; i++) {
        if (html[i] == '<') {
            inside_tag = 1;
            
            // Print the current indent level.
            for (int j = 0; j < indent_level; j++) {
                fprintf(output, "\t");
            }
            
            // Print the opening tag.
            fprintf(output, "<%c", html[i+1]);
            
            // If the next character is a slash, it's a closing tag.
            if (html[i+1] == '/') {
                indent_level--;
                
                // Print the current indent level.
                fprintf(output, "\n");
                for (int j = 0; j < indent_level; j++) {
                    fprintf(output, "\t");
                }
            } else {
                indent_level++;
            }
        } else if (html[i] == '>') {
            inside_tag = 0;
            fprintf(output, ">\n");
        } else {
            fprintf(output, "%c", html[i]);
        }
    }

    // Close the output HTML file.
    fclose(output);

    return 0;
}