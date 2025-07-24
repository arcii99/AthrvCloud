//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *html) {
    int indent = 0;
    int len = strlen(html);
    char *output = calloc(len * 2, sizeof(char));
    char *token = strtok(html, "<>");
    while (token != NULL) {
        if (token[0] == '/') {
            indent -= 2;
        }
        for (int i = 0; i < indent; i++) {
            strcat(output, " ");
        }
        strcat(output, "<");
        strcat(output, token);
        strcat(output, ">\n");
        if (token[0] != '/') {
            indent += 2;
        }
        token = strtok(NULL, "<>");
    }
    printf("%s", output);
    free(output);
}

int main(void) {
    char *html = "<html><head><title>Hello world</title></head><body><h1>Welcome!</h1><p>This is a demo page.</p></body></html>";
    beautify(html);
    return 0;
}