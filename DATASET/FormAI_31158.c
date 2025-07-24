//FormAI DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void indent(char **html, int depth) {
    for (int i = 0; i < depth; i++) {
        strcat(*html, "\t");
    }
}

void beautify(char **html, int depth) {
    int len = strlen(*html);
    char beautified_html[len + 1000];
    int index = 0;
    for (int i = 0; i < len; i++) {
        if ((*html)[i] == '<') {
            if ((*html)[i+1] == '/') {
                depth--;
                strcat(beautified_html, "\n");
                indent(&beautified_html, depth);
                index = strlen(beautified_html);
            } else {
                strcat(beautified_html, "\n");
                indent(&beautified_html, depth);
                index = strlen(beautified_html);
                depth++;
            }
        } else if ((*html)[i] == '>') {
            if ((*html)[i-1] == '/') {
                strcat(beautified_html, "\n");
                indent(&beautified_html, depth);
                index = strlen(beautified_html);
            }
        }
        beautified_html[index++] = (*html)[i];
    }
    beautified_html[index] = '\0';
    strcpy(*html, beautified_html);
}

int main() {
    char html[] = "<html><head><title>Cool Webpage</title></head><body><h1>Welcome to my webpage</h1><p>This is a paragraph</p><img src=\"cool.png\" alt=\"cool image\"></img></body></html>";
    printf("Before beautification:\n%s\n", html);
    beautify(&html, 0);
    printf("After beautification:\n%s\n", html);
    return 0;
}