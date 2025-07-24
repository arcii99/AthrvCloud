//FormAI DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 10000

char* beautify_html(char* html) {
    char* beautified_html = (char*) malloc(MAX_LENGTH * sizeof(char));
    int indent_level = 0;
    int i, j;
    for (i = 0; html[i] != '\0'; i++) {
        if (html[i] == '<') {
            if (html[i + 1] == '/') {
                indent_level--;
            }
            for (j = 0; j < indent_level; j++) {
                strcat(beautified_html, "    ");
            }
            if (html[i + 1] != '!') {
                indent_level++;
            }
        }
        if (html[i] == '>') {
            if (beautified_html[strlen(beautified_html) - 1] == ' ') {
                beautified_html[strlen(beautified_html) - 1] = '\0';
            }
            strcat(beautified_html, ">\n");
        }
        beautified_html[strlen(beautified_html)] = html[i];
    }
    return beautified_html;
}

int main() {
    char* html = "<html><head><title>My Page</title></head><body><h1>Welcome to my page!</h1><p>This is my first page.</p></body></html>";
    char* beautified_html = beautify_html(html);
    printf("%s", beautified_html);
    free(beautified_html);
    return 0;
}