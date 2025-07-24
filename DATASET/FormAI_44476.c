//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>

int main()
{
    int c, prev;

    while ((c = getchar()) != EOF) {
        if (c == '<') {
            putchar(c);

            while ((c = getchar()) != '>') {
                putchar(c);
            }

            putchar(c);

            while ((c = getchar()) == ' ') {}

            if (c != EOF) {
                putchar('\n');
                putchar(c);
            }
        } else if (c == ' ') {
            if (prev != ' ') {
                putchar(c);
            }
        } else {
            putchar(c);
        }

        prev = c;
    }

    return 0;
}