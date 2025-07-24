//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    char c, prev;
    int indent_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == '<') {
            if (prev == '/') {
                indent_count--;
            }
            for (int i = 0; i < indent_count; i++) {
                putchar('\t');
            }
            if (prev != '/') {
                indent_count++;
            }
            putchar(c);
            putchar('\n');
        } else if (c == '>') {
            putchar(c);
            putchar('\n');
        } else {
            putchar(c);
        }
        prev = c;
    }

    return 0;
}