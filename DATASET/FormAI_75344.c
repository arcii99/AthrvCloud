//FormAI DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_HTML(char *html) {
    char *output = malloc(strlen(html) * 2);
    int indent = 0;
    int pos = 0;

    for (int i = 0; html[i] != '\0'; i++) {
        if (html[i] == '<') {
            if (html[i+1] == '/') indent -= 2;
            for (int j = 0; j < indent; j++) {
                output[pos++] = ' ';
            }
            output[pos++] = html[i];
            if (html[i+1] == '/') indent += 2;
            output[pos++] = '\n';
            indent += 2;
        } else if (html[i] == '>') {
            output[pos++] = html[i];
            output[pos++] = '\n';
        } else {
            output[pos++] = html[i];
        }
    }

    output[pos] = '\0';
    printf("%s\n", output);
    free(output);
}

int main() {
    char *html = "<html><head><title>Sample Page</title></head><body><h1>Welcome</h1><p>This is a sample page.</p></body></html>";
    beautify_HTML(html);
    return 0;
}