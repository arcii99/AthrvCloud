//FormAI DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>

void indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("    "); // Use 4 spaces as one level of indentation
    }
}

int main() {
    char c;
    int indent_level = 0;

    while ((c = getchar()) != EOF) {
        if (c == '<') { // Check for start of HTML tag
            putchar(c);
            c = getchar();
            if (c == '/') { // Check if it's a closing tag
                putchar(c);
                indent_level--; // Decrease the indentation level
            } else {
                putchar('\n');
                indent_level++; // Increase the indentation level
                indent(indent_level);
                putchar(c);
            }
            while ((c = getchar()) != '>') { // Output the entire tag
                putchar(c);
            }
            putchar(c);
            putchar('\n');
            indent(indent_level); // Indent next line appropriately
        } else {
            putchar(c);
        }
    }

    return 0;
}