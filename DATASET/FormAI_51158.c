//FormAI DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool tags = false; // Are we currently in an HTML tag?
    int indent_level = 0; // How many tabs should we indent with?
    char current_char; // The current character being processed
    FILE *input_file = fopen("index.html", "r"); // Open the input file
    FILE *output_file = fopen("beautified.html", "w"); // Open the output file

    // Loop through the input file, processing each character
    while ((current_char = fgetc(input_file)) != EOF) {
        // Is the current character a < tag?
        if (current_char == '<') {
            tags = true; // We're in a tag now!
            fputc(current_char, output_file); // Write the < to the output file
            fputc('\n', output_file); // Start the next line
            indent_level++; // Indent the next line
            for (int i = 0; i < indent_level; i++) {
                fputc('\t', output_file); // Indent with tabs
            }
        }
        // Is the current character a > tag?
        else if (current_char == '>') {
            tags = false; // We're out of the tag
            fputc(current_char, output_file); // Write the > to the output file
            fputc('\n', output_file); // Start the next line
        }
        // Is the current character a newline?
        else if (current_char == '\n') {
            if (tags) {
                fputc(current_char, output_file); // Write the newline to the output file
                for (int i = 0; i < indent_level; i++) {
                    fputc('\t', output_file); // Indent with tabs
                }
            }
            else {
                fputc(' ', output_file); // If we're not in a tag, replace the newline with a space
            }
        }
        else {
            fputc(current_char, output_file); // If it's not a tag or newline, just write it to the output file
        }
    }

    // Close the files and end the program
    fclose(input_file);
    fclose(output_file);
    printf("HTML file has been beautified! Check out the new file 'beautified.html'.\n");
    return 0;
}