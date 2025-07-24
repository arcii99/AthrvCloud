//FormAI DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define INDENTATION "    "
#define MAX_LINE_LENGTH 1024

void indent(int level) {
    int i;
    for (i = 0; i < level; i++) {
        printf(INDENTATION);
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH], output_filename[MAX_LINE_LENGTH];
    int level = 0, in_tag = 0, in_quotes = 0, in_comment = 0;

    if (argc < 2) {
        printf("Usage: %s inputfile\n", argv[0]);
        exit(1);
    }

    // Open input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Unable to open input file %s\n", argv[1]);
        exit(1);
    }

    // Create output filename
    sprintf(output_filename, "%s_beautified.html", argv[1]);

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Unable to create output file %s\n", output_filename);
        exit(1);
    }

    // Process each character in input file
    char c;
    while ((c = fgetc(input_file)) != EOF) {
        if (c == '<') {
            in_tag = 1;
            indent(level);
            fputc(c, output_file);
        } else if (c == '>') {
            in_tag = 0;
            fputc(c, output_file);
            if (!in_comment) {
                fputc('\n', output_file);
            }
        } else if (c == '"' && !in_comment) {
            in_quotes = !in_quotes;
            fputc(c, output_file);
        } else if (c == '-' && in_tag) {
            char next_char = fgetc(input_file);
            if (next_char == '-') {
                in_comment = 1;
                fputc(c, output_file);
                fputc(next_char, output_file);
            } else {
                fputc(c, output_file);
                fputc(next_char, output_file);
            }
        } else if (c == '-' && in_comment) {
            char next_char = fgetc(input_file);
            if (next_char == '>') {
                in_comment = 0;
                fputc(c, output_file);
                fputc(next_char, output_file);
                fputc('\n', output_file);
            } else {
                fputc(c, output_file);
                fputc(next_char, output_file);
            }
        } else {
            fputc(c, output_file);
            if (c == '\n' && !in_comment) {
                if (in_tag) {
                    level++;
                } else {
                    indent(level);
                }
            }
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}