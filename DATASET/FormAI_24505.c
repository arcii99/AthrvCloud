//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

char* beautify_html(char* html) {
    char* result = (char*)malloc(sizeof(char) * strlen(html) * 2);
    int indent_count = 0;
    char* line;
    char* tok;
    char* p;
    char* indented_html = (char*)malloc(sizeof(char) * strlen(html) * 2);

    p = strtok(html, "\n");
    while (p != NULL) {
        memset(indented_html, 0, strlen(html) * 2);
        line = (char*)malloc(sizeof(char) * MAX_LINE_LEN);
        tok = strtok(p, "<>");
        while (tok != NULL) {
            if (*tok == '/') {
                indent_count--;
            }
            for (int i = 0; i < indent_count; i++) {
                strcat(indented_html, "  ");
            }
            sprintf(line, "<%s>", tok);
            strcat(indented_html, line);
            if (*tok != '/') {
                indent_count++;
            }
            tok = strtok(NULL, "<>");
        }
        sprintf(line, "%s\n", indented_html);
        strcat(result, line);
        p = strtok(NULL, "\n");
        free(line);
    }

    free(indented_html);

    return result;
}

int main() {
    char* html = "<html><head><title>Example</title></head><body><div><p>Hello World!</p></div></body></html>\n";
    char* beautified_html = beautify_html(html);

    printf("%s", beautified_html);

    free(beautified_html);

    return 0;
}