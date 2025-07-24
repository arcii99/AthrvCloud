//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HTML_SIZE 10000
#define TAB_SIZE 4

int main() {
    char html[MAX_HTML_SIZE];

    printf("Enter HTML code: ");
    fgets(html, MAX_HTML_SIZE, stdin);

    int html_length = strlen(html);
    char beautified_html[MAX_HTML_SIZE];
    int indent_level = 0;

    for (int i = 0; i < html_length; i++) {
        if (html[i] == '<') {
            if (html[i+1] == '/') indent_level -= TAB_SIZE;
            for (int j = 0; j < indent_level; j++) {
                beautified_html[i] = ' ';
            }
            if (html[i+1] != '/') indent_level += TAB_SIZE;
        }
        beautified_html[i] = html[i];
        if (html[i] == '>' && html[i+1] != '<') {
            beautified_html[i+1] = '\n';
            for (int j = 0; j < indent_level; j++) {
                beautified_html[i+2+j] = ' ';
            }
            i = i + TAB_SIZE + 1;
        }
    }

    printf("Beautified HTML code: \n%s", beautified_html);

    return 0;
}