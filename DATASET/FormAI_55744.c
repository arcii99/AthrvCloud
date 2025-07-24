//FormAI DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

void beautify(char *html) {
    int indent_level = 0;
    char *formatted_html = (char *) malloc(sizeof(char));
    formatted_html[0] = '\0';

    int i = 0, j = 0;
    while (html[i] != '\0') {
        if (html[i] == '<') {
            if (html[i + 1] == '/') {
                indent_level--;
            }
            for (int k = 0; k < indent_level; k++) {
                strcat(formatted_html, "\t");
            }
            if (html[i + 1] != '/') {
                indent_level++;
            }
        }
        formatted_html[j++] = html[i++];
        if (html[i - 1] == '>') {
            formatted_html[j++] = '\n';
            formatted_html[j] = '\0';
        }
    }
    printf("%s\n", formatted_html);
    free(formatted_html);
}

int main() {
    char *html = "<html><body><h1>Header</h1><p>Paragraph</p></body></html>";
    beautify(html);

    html = "<html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>";
    beautify(html);

    return 0;
}