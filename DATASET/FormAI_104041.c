//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surrealist
#include <stdio.h>
#include <ctype.h>

int main()
{
    int c, d;

    while ((c = getchar()) != EOF) {
        if (c == '<') {
            putchar(c);
            if ((d = getchar()) != EOF) {
                putchar(d);
                if (d == '/') {
                    while ((c = getchar()) != EOF) {
                        if (c == '>') {
                            putchar(c);
                            break;
                        }
                        putchar(c);
                    }
                } else {
                    while ((c = getchar()) != EOF) {
                        if (isalnum(c)) {
                            putchar(c);
                        } else if (c == '>') {
                            putchar(c);
                            break;
                        } else {
                            putchar('\n');
                        }
                    }
                }
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}