//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define TAB_SIZE 4

void line_beautify(char* line) {
    int i = 0, j = 0, indent_level = 0;
    bool in_string = false;

    while (line[i] != '\0') {
        if (line[i] == '\"') {
            in_string = !in_string;
        }

        if (!in_string) {
            if (line[i] == '{') {
                indent_level++;
                line[j++] = '{';
                line[j++] = '\n';
                for (int k = 0; k < indent_level * TAB_SIZE; k++) {
                    line[j++] = ' ';
                }
            } else if (line[i] == '}') {
                indent_level--;
                line[j++] = '\n';
                for (int k = 0; k < indent_level * TAB_SIZE; k++) {
                    line[j++] = ' ';
                }
                line[j++] = '}';
            } else if (line[i] == ';') {
                line[j++] = ';';
                line[j++] = '\n';
                for (int k = 0; k < indent_level * TAB_SIZE; k++) {
                    line[j++] = ' ';
                }
            } else {
                line[j++] = line[i];
            }
        } else {
            line[j++] = line[i];
        }

        i++;
    }

    line[j] = '\0';
}

char* beautify_html(char* html) {
    char* line = (char*)malloc((strlen(html) + 1) * sizeof(char));
    int i = 0, j = 0;
    bool in_tag = false;

    while (html[i] != '\0') {
        line[j++] = html[i];

        if (!in_tag && html[i] == '<') {
            in_tag = true;
        }

        if (in_tag && html[i] == '>') {
            in_tag = false;
            line[j++] = '\n';
        }

        if (!in_tag && html[i] == '\n') {
            line[j] = '\0';
            line_beautify(line);
            strcat(html, line);
            j = strlen(html);
        }

        i++;
    }

    free(line);

    return html;
}

int main() {
    char html[] = "<html>\n<head>\n<title>Example HTML Document</title>\n</head>\n<body>\n<h1>Welcome to My Website!</h1>\n<p>Here, you will find all sorts of interesting things to do and see.</p>\n</body>\n</html>";

    char* beautified_html = beautify_html(html);

    printf("%s", beautified_html);

    free(beautified_html);

    return 0;
}