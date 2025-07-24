//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error: could not open file");
        exit(EXIT_FAILURE);
    }

    char c, prev_c = '\0', next_c = '\0';
    int indent_level = 0;
    int in_single_quotes = 0, in_double_quotes = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (in_single_quotes || in_double_quotes) {
            putchar(c);
            if ((in_single_quotes && c == '\'') || (in_double_quotes && c == '"')) {
                in_single_quotes = in_double_quotes = 0;
            }
        } else if (c == '\'') {
            in_single_quotes = 1;
            putchar(c);
        } else if (c == '"') {
            in_double_quotes = 1;
            putchar(c);
        } else if (c == '{') {
            putchar(c);
            putchar('\n');
            indent_level++;
            for (int i = 0; i < indent_level * TAB_SIZE; i++) {
                putchar(' ');
            }
        } else if (c == '}') {
            putchar('\n');
            indent_level--;
            for (int i = 0; i < indent_level * TAB_SIZE; i++) {
                putchar(' ');
            }
            putchar(c);
        } else if (c == ';') {
            putchar(c);
            putchar('\n');
            for (int i = 0; i < indent_level * TAB_SIZE; i++) {
                putchar(' ');
            }
        } else if (c == '\n') {
            if (prev_c == '{' || prev_c == ';') {
                for (int i = 0; i < indent_level * TAB_SIZE; i++) {
                    putchar(' ');
                }
            }
            putchar(c);
        } else {
            putchar(c);
        }

        prev_c = c;
        next_c = fgetc(fp);
        if (next_c == EOF) {
            break;
        }
        ungetc(next_c, fp);
    }

    fclose(fp);
    return 0;
}