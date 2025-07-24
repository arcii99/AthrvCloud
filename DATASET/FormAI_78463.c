//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char* html_code) {
    int indent = 0;
    int len = strlen(html_code);
    char* beautified = (char*) malloc(2 * len * sizeof(char));

    for (int i = 0, j = 0; i < len; i++) {
        if (html_code[i] == '<') {
            if (html_code[i + 1] == '/') indent--;
            for (int k = 0; k < indent; k++) {
                beautified[j++] = '\t';
            }
        }
        beautified[j++] = html_code[i];
        if (html_code[i] == '>') {
            if (!(html_code[i + 1] == '<' && html_code[i + 2] == '/')) {
                beautified[j++] = '\n';
                for (int k = 0; k < indent; k++) {
                    beautified[j++] = '\t';
                }
            }
            if (!(html_code[i + 1] == '/' && html_code[i + 2] != '>')) {
                indent++;
            }
        }
    }

    strcpy(html_code, beautified);
    free(beautified);
}

int main() {
    char html_code[1000] = "<html><head><title>My Page</title></head><body><h1>Hello, world!</h1></body></html>";
    printf("Before beautifying:\n%s\n", html_code);
    beautify(html_code);
    printf("After beautifying:\n%s\n", html_code);
    return 0;
}