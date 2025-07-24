//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <ctype.h>

/* Function to beautify HTML code */
void beautifyHTML(char *input_file, char *output_file) {
    FILE *in_file = fopen(input_file, "r"); /* Open input file */
    if (in_file == NULL) { /* Error handling: Could not open file */
        printf("Error: Could not open file %s", input_file);
        return;
    }
    FILE *out_file = fopen(output_file, "w"); /* Open output file */
    if (out_file == NULL) { /* Error handling: Could not open file */
        printf("Error: Could not open file %s", output_file);
        fclose(in_file); /* Close input file */
        return;
    }
    char ch, prev_ch = ' ';
    int indent_level = 0;
    while ((ch = getc(in_file)) != EOF) { /* Loop through every character in the input file */
        if (prev_ch == '\n') { /* Add indentation for new lines */
            for (int i = 0; i < indent_level; ++i) {
                putc('\t', out_file);
            }
        }
        putc(ch, out_file); /* Write character to output file */
        if (ch == '<') {
            if (prev_ch == '<') { /* Handle empty tags */
                indent_level--;
                putc('\n', out_file);
                for (int i = 0; i < indent_level; ++i) {
                    putc('\t', out_file);
                }
            }
            putc('\n', out_file);
            indent_level++;
        } else if (ch == '>') {
            if (prev_ch == '/') { /* Handle closing tags */
                indent_level--;
            }
            putc('\n', out_file);
        }
        prev_ch = ch;
    }
    fclose(in_file); /* Close input file */
    fclose(out_file); /* Close output file */
}

/* Main function */
int main() {
    char input_file[] = "example.html";
    char output_file[] = "beautified.html";
    beautifyHTML(input_file, output_file);
    printf("HTML code beautified and written to %s", output_file);
    return 0;
}