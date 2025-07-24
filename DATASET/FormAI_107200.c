//FormAI DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 10000

void print_indent(int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        printf("  ");
    }
}

void print_tag(char * tag, int indent_level) {
    print_indent(indent_level);
    printf("<%s>\n", tag);
}

void print_end_tag(char * tag, int indent_level) {
    print_indent(indent_level);
    printf("</%s>\n", tag);
}

bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int get_current_indent(char * line) {
    int indent_level = 0;
    while (is_whitespace(line[indent_level])) {
        indent_level++;
    }
    return indent_level;
}

char * trim_whitespace(char * line) {
    char * start = line;
    while (is_whitespace(*start)) {
        start++;
    }
    char * end = line + strlen(line) - 1;
    while (is_whitespace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return start;
}

void beautify(char * html) {
    int indent_level = 0;
    char * current_line = strtok(html, "\n");
    while (current_line != NULL) {
        current_line = trim_whitespace(current_line);
        if (strlen(current_line) == 0) {
            // Do nothing for empty lines
        } else if (current_line[0] == '<') {
            if (current_line[1] == '/') {
                indent_level--;
                print_end_tag(strtok(current_line+2, ">"), indent_level);
            } else {
                print_tag(strtok(current_line+1, ">"), indent_level);
                indent_level++;
            }
        } else {
            print_indent(indent_level);
            printf("%s\n", current_line);
        }
        current_line = strtok(NULL, "\n");
    }
}

int main() {
    char html[MAX_LENGTH] = "<html>\n<head>\n<title>Test Page</title>\n</head>\n<body>\n<p>Hello, World!</p>\n</body>\n</html>";

    beautify(html);

    return 0;
}