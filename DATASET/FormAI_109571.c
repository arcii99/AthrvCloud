//FormAI DATASET v1.0 Category: HTML beautifier ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Beautifies the given HTML string */
char *beautify(char *html) {
    int indent_level = 0;
    int index = 0;
    int len = strlen(html);
    char *out = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        char c = html[i];
        char next = html[i+1];
        out[index] = c;
        if (c == '\n') {
            for (int j = 0; j < indent_level; j++) {
                out[index+1] = '\t';
                index++;
            }
        }
        else if (c == '<') {
            if (next == '/') {
                indent_level--;
            }
            else {
                indent_level++;
            }
        }
        else if (c == '/') {
            if (next == '>') {
                indent_level--;
            }
        }
        index++;
    }
    return out;
}

int main() {
    char html[1000] = "<html>\n<head>\n<title>Hello World</title>\n</head>\n<body>\n<h1>Hello World!</h1>\n<p>Welcome to my website</p>\n</body>\n</html>";
    char *beautified = beautify(html);
    printf("%s", beautified);
    free(beautified);
    return 0;
}