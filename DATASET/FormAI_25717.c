//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(FILE *in, FILE *out);

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc < 3) {
        printf("Usage: %s [input file] [output file]\n", argv[0]);
        return 1;
    }
    // Open input and output files
    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        printf("Could not open input file %s\n", argv[1]);
        return 1;
    }
    FILE *out = fopen(argv[2], "w");
    if (out == NULL) {
        printf("Could not open output file %s\n", argv[2]);
        fclose(in);
        return 1;
    }
    // Call the main beautification function
    beautify(in, out);
    // Close files
    fclose(in);
    fclose(out);
    // Print success message
    printf("HTML beautification complete!\n");
    return 0;
}

void beautify(FILE *in, FILE *out) {
    int indent = 0;
    int newline = 1;
    char c = fgetc(in);
    while (c != EOF) {
        if (newline) { // Insert appropriate indentation
            int i;
            for (i = 0; i < indent; i++) {
                fputc('\t', out);
            }
            newline = 0;
        }
        fputc(c, out);
        if (c == '<') { // Begin a new tag
            indent++;
            newline = 1;
        } else if (c == '>') { // End a tag
            indent--;
            if (newline) {
                int i;
                for (i = 0; i < indent; i++) {
                    fputc('\t', out);
                }
            } else {
                fputc('\n', out);
                newline = 1;
            }
        } else if (c == '\n') {
            newline = 1;
        }
        c = fgetc(in);
    }
}