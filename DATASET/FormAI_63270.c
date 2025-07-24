//FormAI DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 4
#define MAX_LINE_LENGTH 1024

void indent(int level)
{
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
}

void beautify(char *filename)
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int level = 0;
    int ignore_next_newline = 0;
    int in_singleline_comment = 0;
    int in_multiline_comment = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (in_multiline_comment) {
            char *end_comment_position = strstr(line, "*/");
            if (end_comment_position != NULL) {
                in_multiline_comment = 0;
                ignore_next_newline = 0;
                indent(level);
                printf("*/\n");
                line[end_comment_position - line + 2] = '\0';
            } else {
                line[0] = '\0';
            }
        }

        if (!in_multiline_comment) {
            char *start_comment_position = strstr(line, "/*");
            if (start_comment_position != NULL) {
                in_multiline_comment = 1;
                indent(level);
                printf("%s", start_comment_position);
                if (strstr(start_comment_position, "*/") == NULL) {
                    ignore_next_newline = 1;
                }
                *start_comment_position = '\0';
            }
        }

        if (!in_multiline_comment) {
            char *start_comment_position = strstr(line, "//");
            if (start_comment_position != NULL) {
                in_singleline_comment = 1;
                indent(level);
                printf("%s", start_comment_position);
                if (start_comment_position[strlen(start_comment_position) - 1] == '\n') {
                    in_singleline_comment = 0;
                }
                *start_comment_position = '\0';
            }
        }

        if (line[0] != '\0') {
            if (line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';
            }
            if (!in_singleline_comment && !in_multiline_comment) {
                ignore_next_newline = 0;
                indent(level);
            }
            printf("%s\n", line);
        }

        if (!ignore_next_newline) {
            level++;
        } else {
            ignore_next_newline = 0;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    beautify(argv[1]);

    return 0;
}