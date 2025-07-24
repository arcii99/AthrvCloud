//FormAI DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>

int isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int isWhitespace(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

int main() {
    int c, lastC;
    int spaces = 0;
    int inComment = 0;
    int inString = 0;
    int inChar = 0;

    while ((c = getchar()) != EOF) {
        if (c == '/' && lastC == '/') {
            inComment = 1;
            spaces--;
            continue;
        }

        if (inComment == 1 && c == '\n') {
            inComment = 0;
        }

        if (inComment == 0 && inString == 0 && inChar == 0) {
            if (c == '(' || c == ')') {
                printf("%c ", c);
                continue;
            }

            if (isLetter(c)) {
                printf("%c", c);
                continue;
            }

            if (isWhitespace(c)) {
                spaces++;
            } else {
                for (int i = 0; i < spaces; i++) {
                    printf(" ");
                }
                spaces = 0;
                printf("%c", c);
            }
        } else if (inString == 1 && c == '\"' && lastC != '\\') {
            inString = 0;
            printf("%c", c);
        } else if (inChar == 1 && c == '\'' && lastC != '\\') {
            inChar = 0;
            printf("%c", c);
        } else {
            printf("%c", c);
        }

        if (c == '\"' && inString == 0) {
            inString = 1;
        }

        if (c == '\'' && inChar == 0) {
            inChar = 1;
        }

        lastC = c;
    }

    return 0;
}