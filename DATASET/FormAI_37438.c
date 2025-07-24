//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE ' '
#define TAB '\t'
#define MAX_LINE_LENGTH 1000

void beautify(char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    beautify(argv[1]);

    return 0;
}

void beautify(char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: file not found\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char beautified_line[MAX_LINE_LENGTH];
    int indent = 0;

    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int line_len = strlen(line);
        int leading_spaces = 0;

        for (int i = 0; i < line_len; i++) {
            if (line[i] == SPACE) {
                leading_spaces++;
            }
            else if (line[i] == TAB) {
                leading_spaces += 4;
            }
            else {
                break;
            }
        }

        if (leading_spaces > 0) {
            char indent_str[leading_spaces + 1];

            for (int i = 0; i < leading_spaces; i++) {
                indent_str[i] = SPACE;
            }

            indent_str[leading_spaces] = '\0';

            sprintf(beautified_line, "%s%s", indent_str, line + leading_spaces);
            printf("%s", beautified_line);
        }
        else if (line_len > 1) {
            printf("%s", line);
        }
    }

    fclose(fp);
}