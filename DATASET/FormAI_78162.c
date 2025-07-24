//FormAI DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 1000

char indent[MAX_LINE_LENGTH];
int indent_size = 0;

void print_indent() {
    for (int i = 0; i < indent_size; i++) {
        printf(" ");
    }
}

int is_single_line_comment(char *line) {
    if (line[0] == '/' && line[1] == '/') {
        return 1;
    } else {
        return 0;
    }
}

int is_multi_line_comment_start(char *line) {
    if (line[0] == '/' && line[1] == '*') {
        return 1;
    } else {
        return 0;
    }
}

int is_multi_line_comment_end(char *line) {
    for (int i = 1; i < MAX_LINE_LENGTH; i++) {
        if (line[i - 1] == '*' && line[i] == '/') {
            return 1;
        } else if (line[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

void format_single_line_comment(char *line) {
    print_indent();
    printf("%s\n", line);
}

void format_multi_line_comment(char *line) {
    print_indent();
    printf("%s\n", line);
    
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        if (is_multi_line_comment_end(line)) {
            print_indent();
            printf("%s\n", line);
            return;
        } else {
            print_indent();
            printf("%s", line);
        }
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        if (is_single_line_comment(line)) {
            format_single_line_comment(line);
        } else if (is_multi_line_comment_start(line)) {
            format_multi_line_comment(line);
        } else {
            print_indent();
            printf("%s", line);
        }
        
        // Update the indent size
        for (int i = 0; i < MAX_LINE_LENGTH; i++) {
            if (line[i] == '{') {
                indent_size += 4;
                break;
            } else if (line[i] == '}') {
                indent_size -= 4;
                break;
            } else if (!isspace(line[i])) {
                break;
            }
        }
    }
    
    return 0;
}