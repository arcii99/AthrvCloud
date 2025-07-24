//FormAI DATASET v1.0 Category: HTML beautifier ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character is whitespace
bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Function to beautify a HTML file
void beautify_html(const char *input_file, const char *output_file) {
    // Open the input file
    FILE *fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("Error opening input file\n");
        return;
    }

    // Open the output file
    FILE *fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        printf("Error opening output file\n");
        fclose(fp_in);
        return;
    }

    // Read the input file and beautify the HTML
    int indent = 0;
    bool in_tag = false;
    bool in_single_quote_string = false;
    bool in_double_quote_string = false;
    char c;
    while ((c = fgetc(fp_in)) != EOF) {
        switch (c) {
            case '<':
                in_tag = true;
                fprintf(fp_out, "<");
                break;
            case '>':
                in_tag = false;
                fprintf(fp_out, ">\n");
                break;
            case '\'':
                in_single_quote_string = !in_single_quote_string;
                fprintf(fp_out, "'");
                break;
            case '\"':
                in_double_quote_string = !in_double_quote_string;
                fprintf(fp_out, "\"");
                break;
            case '/':
                if (in_tag && !in_single_quote_string && !in_double_quote_string) {
                    indent--;
                    fprintf(fp_out, "/");
                } else {
                    fprintf(fp_out, "/");
                }
                break;
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                if (in_tag && !in_single_quote_string && !in_double_quote_string) {
                    continue;
                } else {
                    fprintf(fp_out, "%c", c);
                }
                break;
            default:
                fprintf(fp_out, "%c", c);
                break;
        }
        if (!in_tag && !in_single_quote_string && !in_double_quote_string && c == '>') {
            fprintf(fp_out, "\n");
            for (int i = 0; i < indent; i++) {
                fprintf(fp_out, "  ");
            }
        }
        if (in_tag && !in_single_quote_string && !in_double_quote_string && c == '>') {
            indent++;
        }
    }

    // Close the files
    fclose(fp_in);
    fclose(fp_out);

    printf("Successfully beautified HTML file '%s' and saved as '%s'\n", input_file, output_file);
}

int main() {
    beautify_html("input.html", "output.html");
    return 0;
}