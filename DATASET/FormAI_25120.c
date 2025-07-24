//FormAI DATASET v1.0 Category: HTML beautifier ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char* html_str) {
    int len = strlen(html_str);
    int indent_level = 0;

    for (int i = 0; i < len; i++) {
        if (html_str[i] == '<') {
            if (html_str[i+1] == '/') {
                indent_level--;
            }
            for (int j = 0; j < indent_level; j++) {
                printf("    ");
            }
            printf("%c", html_str[i]);
            if (html_str[i+1] != '/') {
                indent_level++;
            }
            printf("\n");
        }
        else if (html_str[i] == '>') {
            printf("%c", html_str[i]);
            if (html_str[i+1] != '<') {
                printf("\n");
            }
        }
        else {
            printf("%c", html_str[i]);
        }
    }
}

int main() {
    char html_code[] = "<html>\n<head>\n<title>Page Title</title>\n</head>\n<body>\n\n<h1>Heading 1</h1>\n<p>Paragraph</p>\n\n</body>\n</html>";
    beautify(html_code);

    return 0;
}