//FormAI DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define TAB_WIDTH 4

void print_indent(int indent_level) {
    for (int i = 0; i < indent_level * TAB_WIDTH; ++i) {
        putchar(' ');
    }
}

int main() {
    char buffer[1000];
    int indent_level = 0;
    while (fgets(buffer, sizeof buffer, stdin) != NULL) {
        size_t length = strlen(buffer);
        if (length == 1 && buffer[0] == '\n') {
            // Empty line
            putchar('\n');
        } else {
            for (int i = 0; i < length; ++i) {
                char c = buffer[i];
                if (c == '<') {
                    if (buffer[i + 1] == '/') {
                        // Closing tag
                        print_indent(indent_level - 1);
                        printf("%c", c);
                        indent_level--;
                    } else {
                        // Opening tag
                        print_indent(indent_level);
                        printf("%c", c);
                        indent_level++;
                    }
                } else if (c == '/') {
                    // Self-closing tag
                    print_indent(indent_level);
                    printf("%c", c);
                } else {
                    putchar(c);
                }
            }
        }
    }
    return 0;
}