//FormAI DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>

int main() {

    char c;
    int in_tag = 0;

    while ((c = getchar()) != EOF) {
        
        if (in_tag) {
            putchar(c);
            if (c == '>') {
                in_tag = 0;
                putchar('\n');
            }
        }
        else {
            if (c == '<') {
                in_tag = 1;
                putchar(c);
            }
            else if (c == '/') {
                if (getchar() == '>') {
                    putchar('\n');
                }
                else {
                    putchar('/');
                    putchar(c);
                }
            }
            else {
                putchar(c);
                if (c == '\n') {
                    putchar('<');
                    putchar('/');
                    putchar('b');
                    putchar('r');
                    putchar('>');
                }
            }
        }
    }
    return 0;
}