//FormAI DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <ctype.h>

int main() {
    // Initialize variables
    char c;
    int space_count = 0, comment_flag = 0;

    // Read from standard input
    while ((c = getchar()) != EOF) {
        // Handle comments
        if (c == '<' && getchar() == '!') {
            putchar(c);
            putchar(getchar());
            comment_flag = 1;
        } else if (comment_flag == 1 && c == '-' && getchar() == '-' && getchar() == '>') {
            putchar('-');
            putchar('-');
            putchar('>');
            comment_flag = 0;
        } else if (comment_flag == 1) {
            putchar(c);
        } else {
            // Handle spaces
            if (isspace(c)) {
                space_count++;
            } else {
                if (space_count > 0) {
                    putchar(' ');
                    space_count = 0;
                }
                // Output characters
                putchar(c);
            }
        }
    }
    return 0;
}