//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>

int main()
{
    int c, insideTag = 0, insideQuote = 0;

    while ((c = getchar()) != EOF) {
        if (c == '<') {
            insideTag = 1;
            putchar(c);
            continue;
        }

        if (c == '>') {
            insideTag = 0;
            putchar(c);
            continue;
        }

        if (insideTag) {
            putchar(c);
            continue;
        }

        if (c == '"' || c == '\'') {
            if (insideQuote == 0) {
                insideQuote = c;
            } else {
                if (insideQuote == c) {
                    insideQuote = 0;
                }
            }
            putchar(c);
            continue;
        }

        if (c == '\n') {
            putchar(c);
            continue;
        }

        if (c == ' ') {
            if (insideQuote == 0 && insideTag == 0) {
                putchar(c);
            }
            continue;
        }

        if (c == '\t') {
            if (insideQuote == 0 && insideTag == 0) {
                putchar(c);
            }
            continue;
        }

        putchar(c);
    }

    return 0;
}