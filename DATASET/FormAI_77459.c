//FormAI DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <ctype.h>

void indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
}

int main() {
    char c, prev_c = '\0';
    int in_element = 0, level = 0;

    printf("Enter HTML code:\n");

    while ((c = getchar()) != EOF) {
        if (prev_c == '<' && c != '/') {
            in_element = 1;
            indent(level);
            level++;
        }

        putchar(c);

        if (prev_c == '>') {
            if (in_element) {
                putchar('\n');
                in_element = 0;
            }
            else if (c == '<') {
                putchar('\n');
                indent(level);
            }
            else {
                putchar(' ');
            }
        }

        prev_c = c;
    }

    return 0;
}