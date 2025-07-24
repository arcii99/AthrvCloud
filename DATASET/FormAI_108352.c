//FormAI DATASET v1.0 Category: HTML beautifier ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void beautify(char html[]) {
    int i, j, in_tag = 0;
    char current;
    for (i = 0; html[i] != '\0'; i++) {
        current = html[i];
        if (current == '<') {
            in_tag = 1;
            printf("%c", current);
        } else if (current == '>') {
            in_tag = 0;
            printf("%c\n", current);
        } else if (in_tag) {
            printf("%c", toupper(current));
        } else {
            printf("%c", current);
        }
    }
}

int main() {
    char html[] = "<html>\n<head>\n<title>HTML Beautifier</title>\n</head>\n<body>\n<h1>Hello World!</h1>\n<p>This is a paragraph.</p>\n</body>\n</html>\n";
    beautify(html);
    return 0;
}