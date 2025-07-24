//FormAI DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 256

void print_line(char line[MAX_LINE_LEN], int *line_number, int *empty_lines, int *comment_lines, int *code_lines);
void analyze_file(FILE *log_file, int *line_number, int *empty_lines, int *comment_lines, int *code_lines);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        exit(1);
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Could not open log file %s\n", argv[1]);
        exit(1);
    }

    int line_number = 1;
    int empty_lines = 0;
    int comment_lines = 0;
    int code_lines = 0;
    analyze_file(log_file, &line_number, &empty_lines, &comment_lines, &code_lines);

    printf("Total lines: %d\n", line_number - 1);
    printf("Empty lines: %d\n", empty_lines);
    printf("Comment lines: %d\n", comment_lines);
    printf("Code lines: %d\n", code_lines);

    fclose(log_file);
    return 0;
}

void analyze_file(FILE *log_file, int *line_number, int *empty_lines, int *comment_lines, int *code_lines) {
    char line[MAX_LINE_LEN];
    if (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
        (*line_number)++;
        print_line(line, line_number, empty_lines, comment_lines, code_lines);
        analyze_file(log_file, line_number, empty_lines, comment_lines, code_lines);
    }
}

void print_line(char line[MAX_LINE_LEN], int *line_number, int *empty_lines, int *comment_lines, int *code_lines) {
    int i = 0;
    int empty_line = 1;
    int in_comment = 0;

    while (line[i] != '\0') {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
            empty_line = 0;
        }
        if (line[i] == '#' && i == 0) {
            in_comment = 1;
        }
        if (line[i] == '/' && line[i+1] == '/' && !in_comment) {
            (*comment_lines)++;
            return;
        }
        if (line[i] == '/' && line[i+1] == '*' && !in_comment) {
            in_comment = 1;
            (*comment_lines)++;
        }
        if (line[i] == '*' && line[i+1] == '/' && in_comment) {
            in_comment = 0;
        }
        i++;
    }

    if (empty_line) {
        (*empty_lines)++;
    } else {
        (*code_lines)++;
    }
}