//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define INDENT_SIZE 2

enum HTML_TAGS {
    OPEN_ANGLE_BRACKET = '<',
    CLOSE_ANGLE_BRACKET = '>',
    SPACE = ' ',
    SLASH = '/',
    QUESTION_MARK = '?',
};

void beautify_html(char *html) {
    int indent = 0;
    int size = strlen(html);
    int i;
    for (i = 0; i < size; ) {
        if (html[i] == OPEN_ANGLE_BRACKET) {
            if (html[i + 1] == SLASH) {
                indent -= INDENT_SIZE;
            }
            for (int j = 0; j < indent; j++) {
                putchar(SPACE);
            }
            putchar(OPEN_ANGLE_BRACKET);
            if (html[i + 1] != SLASH) {
                indent += INDENT_SIZE;
            }
            i++;
            while (html[i] != CLOSE_ANGLE_BRACKET) {
                putchar(html[i++]);
            }
            putchar(CLOSE_ANGLE_BRACKET);
            putchar('\n');
            i++;
        } else {
            putchar(html[i++]);
        }
    }
}

int main(int argc, char **argv) {
    char line[MAX_LINE_LENGTH];
    printf("Enter the HTML code: \n");

    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        beautify_html(line);
    }

    return 0;
}