//FormAI DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Beautify the given HTML code */
char* beautify_html(char* code) {
    char *beautified = (char*) malloc(strlen(code) * sizeof(char));
    int indent = 0;
    char* lineStart = code;
    while (*code != '\0') {
        if (*code == '<') {
            if (*(code + 1) == '/') {
                indent -= 4;
            }
            for (int i = 0; i < indent; i++) {
                strcat(beautified, " ");
            }
            if (*(code + 1) != '/') {
                indent += 4;
            }
        }
        strncat(beautified, code, 1);
        if (*code == '>') {
            strcat(beautified, "\n");
            lineStart = code + 1;
        }
        code++;
    }
    free(lineStart);
    return beautified;
}

/* Main function to test the HTML beautifier */
int main() {
    char* html = "<html><head><title>My Website</title></head><body><h1>Welcome to My Website</h1><p>This is some example text.</p></body></html>";
    char* beautified = beautify_html(html);
    printf("%s", beautified);
    free(beautified);
    return 0;
}