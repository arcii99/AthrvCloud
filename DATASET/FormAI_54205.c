//FormAI DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

/* This program is a C HTML beautifier that indents the HTML tags in a readable way */

int main(void) {
    char line[MAX_LINE_LENGTH];
    int indent = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        int i = 0;

        while (isspace(line[i])) { /* skip leading white space */
            i++;
        }

        if (line[i] == '<') { /* HTML tag */
            if (line[i+1] == '/') { /* closing HTML tag */
                indent--;
            }
            for (int j=0; j<indent; j++) {
                putchar('\t'); /* print the appropriate number of tabs */
            }
            if (line[MAX_LINE_LENGTH-2] == '/') { /* self-closing HTML tag */
                printf("%s", line);
            } else {
                printf("%s", line);
                indent++;
            }
        } else { /* plain text */
            for (int j=0; j<indent; j++) {
                putchar('\t'); /* print the appropriate number of tabs */
            }
            printf("%s", line);
        }
    }

    return 0;
}